#pragma once

#include "Component/Graphics/ConvexHull.hpp"
#include "Component/Graphics/Sphere.hpp"
#include "Entity/DampedDoubleSpring.hpp"
#include "Entity/DefaultParticle.hpp"


class Blob {
public:

	std::vector<DefaultParticle> particles;
	std::vector<DampedDoubleSpring> springs;
	ConvexHull sprite;
	Sphere eye_white_l{ Vector3(0,0,0), 10, glm::vec3(255, 255, 255) };
	Sphere eye_white_r{ Vector3(0,0,0), 10, glm::vec3(255, 255, 255) };
	Sphere eye_black_l{ Vector3(0,0,0), 5, glm::vec3(0, 0, 0) };
	Sphere eye_black_r{ Vector3(0,0,0), 5, glm::vec3(0, 0, 0) };


	void flip_inside_visible();

	bool is_inside_visible();

	void init();

	Blob() = default;
	Blob(const Blob&);
	Blob& operator=(const Blob&);

	Blob(const Vector3& pos, int particle_number);
	Blob(const std::vector<DefaultParticle>& new_particles, int begin, size_t size);
	Blob(const Blob& first_blob, const Blob& second_blob);

	void update(const float& delta);
};