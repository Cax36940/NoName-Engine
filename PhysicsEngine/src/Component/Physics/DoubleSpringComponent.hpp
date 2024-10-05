#pragma once
#include "Component/Particle.hpp"
#include "PhysicsComponent.hpp"

class DoubleSpringComponent : public PhysicsComponent {
private:	
	Particle* first;
	Particle* second;
	// SpringForce
public:
	DoubleSpringComponent(Particle* first, Particle* second);

	void registerPhysics() override;
};