#pragma once
#include "ParticleForceGenerator.hpp"

class FrictionForce : public ParticleForceGenerator
{
private:
	float coef_static_friction;
	float coef_cinetic_friction_1;
	float coef_cinetic_friction_2;
	Vector3 normal;

public:
	FrictionForce() : coef_static_friction(0), coef_cinetic_friction_1(0), coef_cinetic_friction_2(0), normal(0, 1, 0) {};
	FrictionForce(const FrictionForce&) = default;
	FrictionForce& operator=(const FrictionForce&) = default;
	FrictionForce(const float& coef_static_friction, const float& coef_cinetic_friction_1, const float& coef_cinetic_friction_2, const Vector3& normal)
		: coef_static_friction(coef_static_friction)
		, coef_cinetic_friction_1(coef_cinetic_friction_1), coef_cinetic_friction_2(coef_cinetic_friction_2)
		, normal(Vector3::normalize(normal)) {};

	void update_force(Particle* particle, float duration) override;
};