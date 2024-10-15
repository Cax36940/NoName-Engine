#include "ParticleForceGenerator.hpp"

class DefaultSpringForce : ParticleForceGenerator {
private:
	const float stiffness;
	const float default_length;
	const Vector3 origin;

public:
	DefaultSpringForce(const float stiffness, const float default_length);
	DefaultSpringForce(const float stiffness, const float default_length, const Vector3& origin);
	void setOrigin(const Vector3& new_origin);
	void updateForce(Particle* particle, float duration) override;
};