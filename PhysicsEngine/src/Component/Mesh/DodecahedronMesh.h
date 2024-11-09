#pragma once
#include <vector>
#include "Component/Vector3.hpp"
class DodecahedronMesh
{
	float gold = 1.6;
	std::vector<Vector3> points = { Vector3(1, 1, 1), Vector3(1, 1, -1), Vector3(1, -1, -1), Vector3(1, -1, 1),
									Vector3(-1, 1, 1), Vector3(-1, 1, -1), Vector3(-1, -1, -1), Vector3(-1, -1, 1),
									Vector3(0, gold, 1 / gold), Vector3(0, gold, -1 / gold), Vector3(0, -gold, -1 / gold), Vector3(0, -gold, 1 / gold),
									Vector3(-1 / gold, 0, gold), Vector3(-1 / gold, 0, -gold), Vector3(1 / gold, 0, -gold), Vector3(1 / gold, 0, gold),
									Vector3(-gold, 1 / gold, 0), Vector3(-gold, -1 / gold, 0), Vector3(gold, -1 / gold, 0), Vector3(gold, 1 / gold, 0), };
};

