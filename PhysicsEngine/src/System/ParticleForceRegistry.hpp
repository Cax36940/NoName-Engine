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
	std::vector<ParticleForceRegistration> registry;
	void clear(); //supp le registre, pas les forces
public:
	void add(Particle* particle, ParticleForceGenerator* fg);
	void remove(Particle* particle, ParticleForceGenerator* fg);
	void updateForces(float duration);
};

