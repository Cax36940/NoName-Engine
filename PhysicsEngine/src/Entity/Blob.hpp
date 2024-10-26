#pragma once

#include "Component/Graphics/ConvexHull.hpp"
#include "Component/Graphics/EyeSprite.hpp"
#include "Entity/DampedDoubleSpring.hpp"
#include "Entity/DefaultParticle.hpp"


class Blob : public UpdatesComponent{
public:

	std::vector<DefaultParticle> particles;
	std::vector<DampedDoubleSpring> springs;
	ConvexHull sprite;
	EyeSprite eye_l{ Vector3(0,0,0)};
	EyeSprite eye_r{ Vector3(0,0,0)};



	void flip_inside_visible();

	bool is_inside_visible();

	void init();

	Blob() = default;
	Blob(const Blob&);
	Blob& operator=(const Blob&);

	Blob(const Vector3& pos, int particle_number);
	Blob(const std::vector<DefaultParticle>& new_particles, int begin, size_t size);
	Blob(const Blob& first_blob, const Blob& second_blob);

	void update(float delta) override;
};