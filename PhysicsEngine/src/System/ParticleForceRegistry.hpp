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

	typedef std::vector<ParticleForceRegistration> Registry; 

	Registry registry;

public:
	void add(Particle* particle, ParticleForceGenerator* fg);
	void remove(Particle* particle, ParticleForceGenerator* fg);
	void clear(); //supp le registre, pas les forces
	void updateForces(float duration);
};

