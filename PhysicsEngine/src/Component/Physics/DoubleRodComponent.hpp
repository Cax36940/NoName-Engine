#pragma once
#include "Component/Particle.hpp"
#include "PhysicsComponent.hpp"

class DoubleRodComponent : public PhysicsComponent {
private:
	Particle* first;
	Particle* second;
	float default_length;

public:
	DoubleRodComponent() = default;
	DoubleRodComponent(const DoubleRodComponent&) = default;
	DoubleRodComponent& operator=(const DoubleRodComponent&) = default;

	DoubleRodComponent(Particle* first, Particle* second, const float& default_length) : first(first), second(second), default_length(default_length) {}

	Vector3 get_first_position() const;
	Vector3 get_second_position() const;

	void register_physics() override;
};