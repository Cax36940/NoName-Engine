#pragma once
#include "../Vector3.hpp"
class IcosahedronMesh
{
	float gold = 1.6;
	std::vector<Vector3> points = { Vector3(0, gold, 1), Vector3(0, gold, -1), Vector3(0, -gold, -1), Vector3(0, -gold, 1),
									Vector3(-1, 0, gold), Vector3(-1, 0, -gold), Vector3(1, 0, -gold), Vector3(1, 0, gold),
									Vector3(-gold, 1, 0), Vector3(-gold, -1, 0), Vector3(gold, -1, 0), Vector3(gold, 1, 0), }; //0.1.g
};

