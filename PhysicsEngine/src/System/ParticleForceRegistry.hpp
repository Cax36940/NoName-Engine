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

	static Registry registry;

public:
	static void add(Particle* particle, ParticleForceGenerator* fg);
	static void remove(Particle* particle, ParticleForceGenerator* fg);
	static void clear(); //supp le registre, pas les forces
	static void updateForces(float duration);
};

