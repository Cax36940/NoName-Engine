#pragma once

#include "Component/Graphics/GraphicsComponent.hpp"
#include "Component/Vector3.hpp"


class ConvexHull : public GraphicsComponent
{
private:
	std::vector<Vector3*> positions;
	glm::vec3 color;
	bool visible_outline = false;

public:
	ConvexHull() = default;
	ConvexHull(const ConvexHull&) = default;
	ConvexHull& operator=(const ConvexHull&) = default;

	ConvexHull(const std::vector<Vector3*>& pos, const glm::vec3& color) : positions(pos), color(color) {}

	void set_positions(const std::vector<Vector3*>& pos);
	void set_color(const float& r, const float& g, const float& b);

	void set_visible_outline(bool new_visible);

	void draw() override;
};