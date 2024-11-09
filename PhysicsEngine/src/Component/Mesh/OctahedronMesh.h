#pragma once
#include <vector>
#include "Component/Vector3.hpp"
class OctahedronMesh
{
	std::vector<Vector3> points = { Vector3(1, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1),
									Vector3(-1, 0, 0), Vector3(0, -1, 0), Vector3(0, 0, -1) };
};

