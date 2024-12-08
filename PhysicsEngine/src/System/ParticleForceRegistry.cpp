#include "ParticleForceRegistry.hpp"

std::vector<ParticleForceRegistry::ParticleForceRegistration> ParticleForceRegistry::registry;
std::vector<FrictionForce*> ParticleForceRegistry::temporary_force;

void ParticleForceRegistry::add(Particle* particle, ParticleForceGenerator* fg)
{
	ParticleForceRegistration pfr;
	pfr.particle = particle;
	pfr.fg = fg;
	registry.push_back(pfr);
}

void ParticleForceRegistry::add(Particle* particle, const FrictionForce& fg)
{
	ParticleForceRegistration pfr;
	pfr.particle = particle;

	FrictionForce* fg_ptr = new FrictionForce(fg); /* Find a way to remove this new */
	temporary_force.push_back(fg_ptr);
	pfr.fg = fg_ptr;
	registry.push_back(pfr);
}

void ParticleForceRegistry::remove(Particle* particle, ParticleForceGenerator* fg)
{
	int to_delete = -1;
	for (int i = 0; i < registry.size(); i++) {
		if (registry[i].particle == particle && registry[i].fg == fg)
		{
			to_delete = i;
		}
	}
	if (to_delete != -1) {
		registry.erase(registry.begin() + to_delete);
	}
}

void ParticleForceRegistry::clear()
{
	registry.clear();

	for (auto tmp_force_ptr : temporary_force) {
		delete tmp_force_ptr;
	}

	temporary_force.clear();
}

void ParticleForceRegistry::update_forces(float duration)
{
	for (ParticleForceRegistration pfr : registry) {
		pfr.fg->update_force(pfr.particle, duration);
	}
	clear();
}
