#include "FireBall.hpp"
#include <ofGraphics.h>

FireBall::FireBall(Vector3& pos)
	: TrailParticle(pos, Vector3(100, -150, 0), Vector3(0,45,0), 1)
{
	
}



void FireBall::draw()
{
	ofSetColor(255, 0, 0);
	TrailParticle::draw();
}


