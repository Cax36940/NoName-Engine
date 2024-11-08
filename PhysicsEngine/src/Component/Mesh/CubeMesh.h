#pragma once
#include "../Vector3.hpp"
class CubeMesh
{
public:
	std::vector<Vector3> points = { Vector3(1, 1, 1), Vector3(1, 1, -1), Vector3(1, -1, -1), Vector3(1, -1, 1),
									Vector3(-1, 1, 1), Vector3(-1, 1, -1), Vector3(-1, -1, -1), Vector3(-1, -1, 1) };
};

