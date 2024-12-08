#pragma once
#include "Component/Particle.hpp"
#include "Component/Physics/Force/ParticleForceGenerator.hpp"
#include "Component/Physics/Force/FrictionForce.hpp"

class ParticleForceRegistry
{
private:
	struct ParticleForceRegistration
	{
		Particle* particle;
		ParticleForceGenerator* fg;
	};

	static std::vector<ParticleForceRegistration> registry;
	static std::vector<FrictionForce*> temporary_force;

public:
	static void add(Particle* particle, ParticleForceGenerator* fg);
	static void add(Particle* particle, const FrictionForce& fg);
	static void remove(Particle* particle, ParticleForceGenerator* fg);
	static void clear(); //supp le registre, pas les forces
	static void update_forces(float duration);
};

