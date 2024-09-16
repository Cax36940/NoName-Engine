#pragma once
#include "DefaultParticle.hpp"

#define FIREBALL_SIZE 20
#define FIREBALL_COLOR glm::vec3(255, 0, 0)
#define FIREBALL_VELOCITY Vector3(100, -250, 0)
#define FIREBALL_MASS 250


class FireBall : public DefaultParticle
{
private:

public:
	FireBall() = default;
	FireBall(Vector3& pos, Vector3& acc) 
		: DefaultParticle(Particle(pos, FIREBALL_VELOCITY, acc, FIREBALL_MASS)
						, Sphere(pos, FIREBALL_SIZE, FIREBALL_COLOR)) {}
	
	void draw() override;
};

