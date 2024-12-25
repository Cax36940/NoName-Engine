#pragma once

#include "Component/Graphics/GraphicsComponent.hpp"
#include "Vector3.hpp"


class EyeSprite : public GraphicsComponent
{
private:
	Vector3 position;

public:
	EyeSprite() = default;
	EyeSprite(const EyeSprite&) = default;
	EyeSprite& operator=(const EyeSprite&) = default;

	EyeSprite(const Vector3& pos) : position(pos){}

	void set_position(const Vector3& pos);

	Vector3 get_position() const;

	void draw() override;
};