#include "Blob.hpp"
#include <ofMain.h>


#define STIFFNESS 20
#define DAMPING 1
#define DEFAULT_LENGTH 50
#define WIDTH 1

Blob::Blob(const Blob& copy_blob)
{


}

Blob& Blob::operator=(const Blob& copy_blob)
{
	particles = copy_blob.particles;
	int particle_number = particles.size();
	const glm::vec3 color(0.5, 0.5, 0.5);

	for (int i = 0; i < particle_number; i++) {
		springs.emplace_back(particles[i].get_physical_particle(), particles[(i + 1) % particle_number].get_physical_particle(), STIFFNESS, DAMPING, DEFAULT_LENGTH, WIDTH, color);
		springs.emplace_back(particles[i].get_physical_particle(), particles[(i + particles.size()/2 + 1) % particle_number].get_physical_particle(), STIFFNESS, DAMPING, DEFAULT_LENGTH / (sin(PI / particle_number)), WIDTH, color);
	}

	std::vector<Vector3*> positions;
	positions.reserve(particle_number);
	for (int i = 0; i < particle_number; i++) {
		positions.push_back((Vector3*)particles[i].get_physical_particle());
	}
	sprite.set_positions(positions);
	sprite.set_color(0., 128, 255);

	eye_white_l.set_color(255, 255, 255);
	eye_black_l.set_color(0, 0, 0);
	eye_white_r.set_color(255, 255, 255);
	eye_black_r.set_color(0, 0, 0);

	eye_white_l.set_size(10);
	eye_black_l.set_size(5);
	eye_white_r.set_size(10);
	eye_black_r.set_size(5);

	for (int i = 0; i < springs.size(); i++) {
		springs[i].sprite.set_visible(false);
	}
	for (int i = 0; i < particle_number; i++) {
		particles[i].sprite.set_visible(false);
	}

	return *this;
}

Blob::Blob(const Vector3& pos, const int& particle_number)
{
	particles.reserve(particle_number);
	springs.reserve(4 * particle_number);

	const glm::vec3 color(0.5, 0.5, 0.5);

	//DampedDoubleSpring(Particle * particle1, Particle * particle2, const float stiffness, const float damping, const float default_length, const float width, const glm::vec3 & color)

	float radius = DEFAULT_LENGTH / (2 * sin(PI / particle_number));

	for (int i = 0; i < particle_number; i++) {
		particles.emplace_back(Particle(pos + Vector3(radius * cos(i*TWO_PI/particle_number), radius * sin(i*TWO_PI / particle_number), 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 5), Sphere(pos, 20, glm::vec3(255, 255, 255)));
	}

	/*for (int i = 0; i < particle_number; i++) {
		springs.emplace_back(particles[i].get_physical_particle(), particles[(i + 1) % particle_number].get_physical_particle(), STIFFNESS, DAMPING, DEFAULT_LENGTH, WIDTH, color);
	}*/

}

void Blob::update(const float& delta)
{
	Vector3 mean_position{};

	for (DefaultParticle& particle_it : particles) {
		particle_it.update(delta);
		mean_position += particle_it.particle.get_position();
	}
	mean_position *= 1. / particles.size();

	eye_white_l.set_position(mean_position + Vector3(-20,0,0));
	eye_black_l.set_position(mean_position + Vector3(-20, 0, 0));
	eye_white_r.set_position(mean_position + Vector3(20, 0, 0));
	eye_black_r.set_position(mean_position + Vector3(20, 0, 0));

	for (DampedDoubleSpring& spring_it : springs) {
		spring_it.update(delta);
	}
}
