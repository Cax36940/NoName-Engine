#include "Component/Mesh/ArrowMesh.hpp"
#include "Component/Mesh/Mesh.hpp"
#include "Matrix4.hpp"

class Arrow {
public:
	Arrow() = default;
	Arrow(const Arrow& arrow) :
		mesh(arrow.mesh),
		transform(transform) {
		mesh.set_transform_ptr(&transform);
	}

	Arrow& operator=(const Arrow& arrow) {
		mesh = arrow.mesh;
		transform = arrow.transform;
		mesh.set_transform_ptr(&transform);
		return *this;
	}

	Arrow(const Vector3& position, float size, const Vector3& color, const Quaternion& rotation = Quaternion()) :
		mesh(&ArrowMesh::get_instance(), color),
		transform(size* Quaternion::toMatrix3(rotation), position) {
		mesh.set_transform_ptr(&transform);
	}

	Mesh mesh;
	Matrix4 transform;

};