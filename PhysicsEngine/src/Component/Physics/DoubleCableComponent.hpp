#pragma once
#include "Component/Particle.hpp"
#include "PhysicsComponent.hpp"

class DoubleCableComponent : public PhysicsComponent {
private:	
	Particle* first;
	Particle* second;
	float default_length;
		 
public:
	DoubleCableComponent() = default;
	DoubleCableComponent(const DoubleCableComponent&) = default;
	DoubleCableComponent& operator=(const DoubleCableComponent&) = default;

	DoubleCableComponent(Particle* first, Particle* second, const float& default_length) : first(first), second(second), default_length(default_length){}

	Vector3 get_first_position() const;
	Vector3 get_second_position() const;

	void register_physics() override;
};