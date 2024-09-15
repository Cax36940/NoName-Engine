#include "Particle.hpp"

class TrailParticle : public Particle
{
private:
	std::vector<Particle> trail;

public:
	TrailParticle() = default;
	TrailParticle(Vector3& pos, Vector3& vel, Vector3& acc, float weight);

	void update(float delta);
	void draw();
};