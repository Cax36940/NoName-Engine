#include "ParticleForceGenerator.hpp"

class DefaultSpringForce : ParticleForceGenerator {
private:
	float stiffness;
	float default_length;
	Vector3 origin;

public:
	DefaultSpringForce() = default;
	DefaultSpringForce(const DefaultSpringForce&) = default;
	DefaultSpringForce& operator=(const DefaultSpringForce&) = default;

	DefaultSpringForce(const float& stiffness, const float& default_length);
	DefaultSpringForce(const float& stiffness, const float& default_length, const Vector3& origin);
	void setOrigin(const Vector3& new_origin);
	Vector3 getOrigin() const;
	void updateForce(Particle* particle, float duration) override;
};