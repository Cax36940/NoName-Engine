#pragma once
#include "Component/Particle.hpp"
#include "PhysicsComponent.hpp"

class CableComponent : public PhysicsComponent {
private:	
	Particle* first;
	Particle* second;
	float default_length;
	bool is_rigid; // If true, the cable act as a Rod (can't move in both directions)
		 
public:
	CableComponent() = default;
	CableComponent(const CableComponent&) = default;
	CableComponent& operator=(const CableComponent&) = default;

	CableComponent(Particle* first, Particle* second, const float& default_length, const bool is_rigid = false) : first(first), second(second), default_length(default_length), is_rigid(is_rigid){}

	Vector3 get_first_position() const;
	Vector3 get_second_position() const;

	void register_physics() override;
};