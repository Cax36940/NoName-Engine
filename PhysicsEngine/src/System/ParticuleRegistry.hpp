#include "Component/Particle.hpp"

class ParticleRegistry
{
private:
	static std::vector<Particle*> registry;
public:
	static void add(Particle* particle);
	static void remove(Particle* particle);
	static void updateAllParticules(float duration);
};
