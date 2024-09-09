#include "Vector3.hpp"

class Particle {
private:
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;
	float weight;

public:
	Particle() = default;
	Particle(Vector3& pos, Vector3& vel, Vector3& acc, float weight);

	void update(float delta);
	void draw();
};