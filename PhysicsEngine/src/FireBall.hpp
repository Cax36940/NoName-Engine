#pragma once
#include "TrailParticle.hpp"

class FireBall : public TrailParticle
{
private:

public:
	FireBall() = default;
	FireBall(Vector3& pos);
	
	void draw();
};

