#include "Component/Particle.hpp"

class ParticleRegistry
{
private:

	typedef std::vector<Particle*> Registry;

	static Registry registry;

public:
	static void add(Particle* particle);
	static void remove(Particle* particle);
	static void updateAllParticules(float duration);
};
