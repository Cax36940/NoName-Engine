#include "ParticleForceRegistry.hpp"

std::vector<ParticleForceRegistry::ParticleForceRegistration> ParticleForceRegistry::registry;

void ParticleForceRegistry::add(Particle* particle, ParticleForceGenerator* fg)
{
	ParticleForceRegistration pfr;
	pfr.particle = particle;
	pfr.fg = fg;
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
}

void ParticleForceRegistry::updateForces(float duration)
{
	for (ParticleForceRegistration pfr : registry) {
		pfr.fg->updateForce(pfr.particle, duration);
	}
	clear();
}
