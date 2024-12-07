#include "CollidersComponentRegistry.hpp"
#include "CollisionsRegistry.hpp"
#include "Component/Physics/Collider/SphereCollider.hpp"
#include "Component/Octree.hpp"
#include "Component/Particle.hpp"
#include "Component/Vector3.hpp"
#include "Component/Mesh/Mesh.hpp"
#include "Component/Physics/Force/GravityForce.hpp"

#include <unordered_set>

#define ELASTIC_COEF 0.5

std::vector<SphereCollider*> CollidersComponentRegistry::registry;

void CollidersComponentRegistry::add(SphereCollider* collider)
{
	registry.push_back(collider);
}

void CollidersComponentRegistry::remove(SphereCollider* collider)
{
	for (auto i = registry.begin(); i != registry.end(); i++) {
		if (*i == collider) {
			registry.erase(i);
			break;
		}
	}
}


static void sphere_sphere_collision(SphereCollider* first_collider, SphereCollider* second_collider) {
	
	Particle* particle1 = first_collider->physical_body;
	Particle* particle2 = second_collider->physical_body;

	const Vector3 vector_ji = particle1->get_position() - particle2->get_position();
	const float norm_ij = Vector3::norm(vector_ji);
	const Vector3 normal = vector_ji * (1 / norm_ij);

	// Compute the distance to separate both objects
	const float minimal_length = first_collider->get_size() + second_collider->get_size();
	const float collision_distance = minimal_length - norm_ij;

	const float m1 = particle1->get_mass();
	const float m2 = particle2->get_mass();

	const Vector3 delta_position1 = (collision_distance * m2 / (m1 + m2)) * normal;
	const Vector3 delta_position2 = (-collision_distance * m1 / (m1 + m2)) * normal;


	// Compute the change in velocity for both objects
	const Vector3 v_relative = particle1->get_velocity() - particle2->get_velocity();
	const float k = ((ELASTIC_COEF + 1) * Vector3::dot(v_relative, normal)) / (particle1->get_inv_mass() + particle2->get_inv_mass());
	const Vector3 delta_velocity1 = (-k * particle1->get_inv_mass()) * normal;
	const Vector3 delta_velocity2 = (k * particle2->get_inv_mass()) * normal;


	CollisionsRegistry::add(particle1, delta_position1, delta_velocity1);
	CollisionsRegistry::add(particle2, delta_position2, delta_velocity2);
}

static void sphere_mesh_collision(SphereCollider* sphere, Mesh* mesh) {
	/* TODO : check for sphere mesh collision */
}

// No hash function is defined for std::pair<unsigned int, unsigned int>
// See : https://en.cppreference.com/w/cpp/utility/hash
static struct EdgeHash {
	std::size_t operator()(const std::pair<unsigned int, unsigned int>& edge) const {
		return std::hash<unsigned int>()(edge.first) ^ std::hash<unsigned int>()(edge.second);
	}
};

static void mesh_mesh_collision(SphereCollider* first_collider, SphereCollider* second_collider) {

	// For resolution
	float collision_distance = _FMAX;
	Vector3 collision_normal(0.0f, 0.0f, 0.0f);


	Mesh* first_mesh = first_collider->get_mesh_ptr();
	Mesh* second_mesh = second_collider->get_mesh_ptr();

	/* TODO : Check if vertices could be retrived easily from ofMesh */
	std::vector<Vector3> first_vertices = first_mesh->get_mesh_ressource().get_vertices();
	const std::vector<unsigned int>& first_indices = first_mesh->get_mesh_ressource().get_indices();

	for (Vector3& vertex : first_vertices) {
		vertex += first_mesh->get_offset();
		Vector4 tmp_vector = first_mesh->get_transform() * Vector4(vertex, 1);
		vertex = Vector3(tmp_vector.x, tmp_vector.y, tmp_vector.z);
	}

	std::vector<Vector3> second_vertices = second_mesh->get_mesh_ressource().get_vertices();
	const std::vector<unsigned int>& second_indices = second_mesh->get_mesh_ressource().get_indices();

	for (Vector3& vertex : second_vertices) {
		vertex += second_mesh->get_offset();
		Vector4 tmp_vector = second_mesh->get_transform() * Vector4(vertex, 1);
		vertex = Vector3(tmp_vector.x, tmp_vector.y, tmp_vector.z);
	}

	// Check if a face of first_mesh define a separating plane
	for (int i = 0; i < first_indices.size(); i+=3) {

		bool is_separating_plane = true;
		const Vector3& first_vertex = first_vertices[first_indices[i]];
		const Vector3& second_vertex = first_vertices[first_indices[i + 1]];
		const Vector3& third_vertex = first_vertices[first_indices[i + 2]];

		const Vector3 normal = Vector3::cross(second_vertex - first_vertex, third_vertex - first_vertex);

		for (const Vector3& vertex: second_vertices) {
			float dot = Vector3::dot(normal, vertex - first_vertex);
			if (dot < 0) {
				is_separating_plane = false;
				const float norm = Vector3::norm(normal);
				dot *= -norm;
				if (dot < collision_distance) {
					collision_distance = dot;
					collision_normal = (1 / norm) * normal;
				}
				break;
			}
		}

		// If no vertex is 'behind' this plane then it is a separating plane
		if (is_separating_plane) {
			return;
		}

	}

	// Check if a face of second_mesh define a separating plane
	for (int i = 0; i < second_indices.size(); i += 3) {

		bool is_separating_plane = true;
		const Vector3& first_vertex = second_vertices[second_indices[i]];
		const Vector3& second_vertex = second_vertices[second_indices[i + 1]];
		const Vector3& third_vertex = second_vertices[second_indices[i + 2]];

		const Vector3 normal = Vector3::cross(second_vertex - first_vertex, third_vertex - first_vertex);

		for (const Vector3& vertex : first_vertices) {
			float dot = Vector3::dot(normal, vertex - first_vertex);
			if (dot < 0) {
				is_separating_plane = false;
				const float norm = Vector3::norm(normal);
				dot *= -norm;
				if (dot < collision_distance) {
					collision_distance = dot;
					collision_normal = (-1 / norm) * normal; // Mult -1 to Aim normal to go toward second collider
				}
				break;
			}
		}

		// If no vertex is 'behind' this plane then it is a separating plane
		if (is_separating_plane) {
			return;
		}

	}

	std::unordered_set<std::pair<unsigned int, unsigned int>, EdgeHash> first_edges;
	first_edges.reserve(first_indices.size() / 2);

	// Iterate over all triangles
	for (int i = 0; i < first_indices.size(); i += 3) {
		// Insert edges into the set
		// Hash function is symetric so no need to sort the vertices of the edge
		first_edges.insert({ first_indices[i], first_indices[i + 1] });
		first_edges.insert({ first_indices[i + 1], first_indices[i + 2] });
		first_edges.insert({ first_indices[i + 2], first_indices[i] });
	}


	std::unordered_set<std::pair<unsigned int, unsigned int>, EdgeHash> second_edges;
	second_edges.reserve(second_indices.size() / 2);

	// Iterate over all triangles
	for (int i = 0; i < second_indices.size(); i += 3) {
		// Insert edges into the set
		// Hash function is symetric so no need to sort the vertices of the edge
		second_edges.insert({ second_indices[i], second_indices[i + 1] });
		second_edges.insert({ second_indices[i + 1], second_indices[i + 2] });
		second_edges.insert({ second_indices[i + 2], second_indices[i] });
	}

	// Check if edge-edge collision
	for (const auto& first_edge : first_edges) {
		const Vector3& first_vertex_a = first_vertices[first_edge.first];
		const Vector3& first_vertex_b = first_vertices[first_edge.second];

		for (const auto& second_edge : second_edges) {
			const Vector3& second_vertex_a = second_vertices[second_edge.first];
			const Vector3& second_vertex_b = second_vertices[second_edge.second];

			const Vector3 normal = Vector3::cross(first_vertex_b - first_vertex_a, second_vertex_b - second_vertex_a);

			if (Vector3::norm2(normal) == 0.0f) {
				continue;
			}

			float first_min_value = FLT_MAX;
			float first_max_value = -FLT_MAX;

			for (const Vector3& vertex : first_vertices) {
				float dot = Vector3::dot(normal, vertex);
				
				if (dot < first_min_value) {
					first_min_value = dot;
				}

				if (dot > first_max_value) {
					first_max_value = dot;
				}
			}

			float second_min_value = FLT_MAX;
			float second_max_value = -FLT_MAX;

			for (const Vector3& vertex : second_vertices) {
				float dot = Vector3::dot(normal, vertex);

				if (dot < second_min_value) {
					second_min_value = dot;
				}

				if (dot > second_max_value) {
					second_max_value = dot;
				}
			}

			// If no common projected part then a separating plane as been found
			if (first_min_value > second_max_value || second_min_value > first_max_value) {
				return;
			}

			bool negate_dir = false;
			float min_dist = first_max_value - second_min_value;
			if (second_max_value - first_min_value < min_dist) {
				min_dist = second_max_value - first_min_value;
				negate_dir = true;
			}

			float norm = Vector3::norm(normal);
			min_dist *= norm;
			if (negate_dir) { // Aim normal to go toward second collider
				norm *= -1.0f; 
			}

			if (min_dist < collision_distance) {
				collision_distance = min_dist;
				collision_normal = (1 / norm) * normal;
			}

		}
	}

	// Collision resolution

	Particle* particle1 = first_collider->physical_body;
	Particle* particle2 = second_collider->physical_body;

	const float m1 = particle1->get_mass();
	const float m2 = particle2->get_mass();

	const Vector3 delta_position1 = (-collision_distance * m2 / (m1 + m2)) * collision_normal;
	const Vector3 delta_position2 = (collision_distance * m1 / (m1 + m2)) * collision_normal;


	// Compute the change in velocity for both objects
	const Vector3 v_relative = particle1->get_velocity() - particle2->get_velocity();
	const float k = ((ELASTIC_COEF + 1) * Vector3::dot(v_relative, collision_normal)) / (particle1->get_inv_mass() + particle2->get_inv_mass());
	Vector3 delta_velocity1 = (-k * particle1->get_inv_mass()) * collision_normal;
	Vector3 delta_velocity2 = (k * particle2->get_inv_mass()) * collision_normal;


	if (delta_velocity1.y > 0 && delta_velocity1.y < -2*GravityForce::get_instance().get_value()) {
		delta_velocity1.y = -particle1->get_velocity().y;
		particle1->set_cancel_gravity(true);
	}
	if (delta_velocity2.y > 0 && delta_velocity2.y < -2*GravityForce::get_instance().get_value()) {
		delta_velocity2.y = -particle2->get_velocity().y;
		particle2->set_cancel_gravity(true);
	}

	CollisionsRegistry::add(particle1, delta_position1, delta_velocity1);
	CollisionsRegistry::add(particle2, delta_position2, delta_velocity2);


}

static void register_collision(SphereCollider* first_collider, SphereCollider* second_collider) {
	if (first_collider->get_mesh_ptr() == nullptr && second_collider->get_mesh_ptr() == nullptr) {
		sphere_sphere_collision(first_collider, second_collider);
		return;
	}

	if (first_collider->get_mesh_ptr() == nullptr) {
		sphere_mesh_collision(first_collider, second_collider->get_mesh_ptr());
		return;
	}

	if (second_collider->get_mesh_ptr() == nullptr) {
		sphere_mesh_collision(second_collider, first_collider->get_mesh_ptr());
		return;
	}

	mesh_mesh_collision(first_collider, second_collider);

}


void CollidersComponentRegistry::check_collisions(Octree & visual_octree)
{
	
	Octree collider_octree(registry.size(), Vector3(0, 0, 0), Vector3(256, 256, 256));
	for (auto i : registry) {
		collider_octree.add_collider(*i);
	}
	visual_octree = collider_octree;

	std::unordered_set<SphereCollider*> checked_colliders;


	std::vector<SphereCollider*> potential_colliders;
	// Check only sphere collisions
	for (auto i : registry) {
		potential_colliders.clear();
		collider_octree.get_overlapping_colliders(*i, potential_colliders);

		for (auto j : potential_colliders) {
			// Collider has already been checked, don't check it again
			if (checked_colliders.find(j) != checked_colliders.end()) {
				continue;
			}

			const Vector3 vector_ji = i->physical_body->get_position() - j->physical_body->get_position();
			const float norm2_ij = Vector3::norm2(vector_ji);
			const float minimal_length = i->get_size() + j->get_size();
			// If spheres collide check for more precise collision
			if (norm2_ij <= minimal_length * minimal_length) {
				register_collision(i, j);
			}
		}
		checked_colliders.insert(i);
	}

}
