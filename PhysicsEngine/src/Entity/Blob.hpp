#pragma once

#include "Component/Graphics/ConvexHull.hpp"
#include "Component/Graphics/Sphere.hpp"
#include "Entity/DampedDoubleSpring.hpp"
#include "Entity/DefaultParticle.hpp"


class Blob {
public:

	std::vector<DefaultParticle> particles;
	std::vector<DampedDoubleSpring> springs;
	ConvexHull sprite;
	Sphere eye_white_l;
	Sphere eye_black_l;
	Sphere eye_white_r;
	Sphere eye_black_r;


	Blob() = default;
	Blob(const Blob&);
	Blob& operator=(const Blob&);

	Blob(const Vector3& pos, const int& particle_number);
	void update(const float& delta);
};