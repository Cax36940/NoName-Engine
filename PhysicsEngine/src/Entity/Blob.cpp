#include "Blob.hpp"
#include <ofMain.h>


#define STIFFNESS 20
#define DAMPING 1
#define DEFAULT_LENGTH 50
#define WIDTH 1

void Blob::flip_inside_visible()
{
	const bool visible = springs[0].sprite.is_visible();
	for (DampedDoubleSpring& spring : springs) {
		spring.sprite.set_visible(!visible);
	}
	for (DefaultParticle& particle : particles) {
		particle.sprite.set_visible(!visible);
	}
}

bool Blob::is_inside_visible()
{
	return particles[0].sprite.is_visible();
}

void Blob::init()
{
	int particle_number = particles.size();

	const glm::vec3 color(0.5, 0.5, 0.5);

	// Add springs
	springs.reserve(2 * particles.size());
	springs.clear();
	for (int i = 0; i < particle_number; i++) {
		springs.emplace_back(particles[i].get_physical_particle(), particles[(i + 1) % particle_number].get_physical_particle(), STIFFNESS, DAMPING, DEFAULT_LENGTH, WIDTH, color);
		springs.emplace_back(particles[i].get_physical_particle(), particles[(i + particles.size() / 2 + 1) % particle_number].get_physical_particle(), STIFFNESS, DAMPING, DEFAULT_LENGTH / (sin(PI / particle_number)), WIDTH, color);
	}

	// Create sprite, need the position of all particles
	std::vector<const Vector3*> positions;
	positions.reserve(particle_number);
	for (int i = 0; i < particle_number; i++) {
		positions.emplace_back(particles[i].get_physical_particle()->get_position_ptr());
	}
	sprite.set_positions(positions);
	sprite.set_color(0., 128, 255);

	// Hide the skeleton of the blob
	for (int i = 0; i < springs.size(); i++) {
		springs[i].sprite.set_visible(false);
	}
	for (int i = 0; i < particle_number; i++) {
		particles[i].sprite.set_visible(false);
	}

}

Blob::Blob(const Blob& copy_blob)
{
	particles = copy_blob.particles;
	init();
}

Blob& Blob::operator=(const Blob& copy_blob)
{
	particles = copy_blob.particles;
	init();
	return *this;
}

Blob::Blob(const Vector3& pos, int particle_number)
{
	if (particle_number < 3) {
		std::cout << "[WARNING] Blob can not be created with " << particle_number << " < 3 particles. Creating a Blob with 3 particles instead." << std::endl;
		particle_number = 3;
	}

	particles.reserve(particle_number);

	float radius = DEFAULT_LENGTH / (2 * sin(PI / particle_number));

	for (int i = 0; i < particle_number; i++) {
		particles.emplace_back(Particle(pos + Vector3(radius * cos(i*TWO_PI/particle_number), radius * sin(i*TWO_PI / particle_number), 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 5), Sphere(20, glm::vec3(255, 255, 255)));
	}

	init();
}

Blob::Blob(const std::vector<DefaultParticle>& new_particles, int begin, size_t size)
{
	particles.reserve(size);

	std::vector<DefaultParticle>::const_iterator particle_it = std::next(new_particles.begin(), begin);

	for (int i = 0; i < size; i++) {
		particles.emplace_back(*particle_it);
		++particle_it;
	}

	init();
}

Blob::Blob(const Blob& first_blob, const Blob& second_blob)
{
	size_t total_size = first_blob.particles.size() + second_blob.particles.size();
	particles.reserve(total_size);

	for (const DefaultParticle& particle : first_blob.particles) {
		particles.emplace_back(particle);
	}
	for (const DefaultParticle& particle : second_blob.particles) {
		particles.emplace_back(particle);
	}

	init();

}

void Blob::update(float delta)
{
	Vector3 mean_position{};

	for (DefaultParticle& particle_it : particles) {
		mean_position += particle_it.particle.get_position();
	}
	mean_position *= 1. / particles.size();

	eye_l.set_position(mean_position + Vector3(-20, 0, 0));
	eye_r.set_position(mean_position + Vector3(20, 0, 0));

}
