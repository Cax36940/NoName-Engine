#pragma once
#include "Component/Particle.hpp"
#include "Component/Physics/Force/ParticleForceGenerator.hpp"

class ParticleForceRegistry
{
private:
	struct ParticleForceRegistration
	{
		Particle* particle;
		ParticleForceGenerator* fg;
	};

	static std::vector<ParticleForceRegistration> registry;

public:
	static void add(Particle* particle, ParticleForceGenerator* fg);
	static void remove(Particle* particle, ParticleForceGenerator* fg);
	static void clear(); //supp le registre, pas les forces
	static void update_forces(float duration);
};

