#include "ParticuleRegistry.hpp"

void ParticleRegistry::add(Particle* particle)
{
	registry.push_back(particle);
}

void ParticleRegistry::remove(Particle* particle)
{
	int to_delete = -1;
	for (int i = 0; i < registry.size(); i++) {
		if (registry[i] == particle)
		{
			to_delete = i;
		}
	}
	if (to_delete != -1) {
		registry.erase(registry.begin() + to_delete);
	}
}

void ParticleRegistry::updateAllParticules(float duration)
{
	for (Particle* particle : registry) {
		particle->update(duration);
	}
}
