#include "Transform.hpp"

Transform::Transform() : rotation(), translation() {}

Transform::Transform(const Vector3& x, const Vector3& y, const Vector3& z, const Vector3& t) : 
    rotation(x, y, z), translation(t){}

Transform::Transform(const Matrix3& matrix, const Vector3& vector) : 
    rotation(matrix), translation(vector) {}

bool Transform::operator==(const Transform& transform)
{
    return (this->rotation == transform.rotation) && (this->translation == transform.translation);
}

bool Transform::operator!=(const Transform& transform)
{
    return (this->rotation != transform.rotation) || (this->translation != transform.translation);
}

Transform Transform::operator*(const float& alpha) const {
    return Transform(alpha * this->rotation, this->translation);
}

Transform& Transform::operator*=(const float& alpha) {
    this->rotation *= alpha;
    return *this;
}

Transform operator*(const float& alpha, const Transform& transform) {
    return Transform(alpha * transform.rotation, transform.translation);
}

Transform operator*(const Transform& left_m, const Transform& right_m)
{
    return Transform(left_m.rotation * right_m.rotation, left_m.rotation * right_m.translation + left_m.translation);
}

Vector4 operator*(const Transform& transform, const Vector4& vector) {
    Vector3 vector_pos(vector.x, vector.y, vector.z);
    return Vector4(transform.rotation * vector_pos + transform.translation, vector.t);
}

Transform Transform::operator/(float alpha) const
{
    return Transform(this->rotation / alpha, this->translation);
}

Transform& Transform::operator/=(float alpha)
{
    this->rotation /= alpha;
    return *this;
}

Transform Transform::operator+(const Transform& transform) const {
    return Transform(this->rotation + transform.rotation, this->translation + transform.translation);
}

Transform& Transform::operator+=(const Transform& transform) {
    this->rotation += transform.rotation;
    this->translation += transform.translation;
    return *this;
}

Transform Transform::operator-() const
{
    return Transform(-rotation, -translation);
}

Transform Transform::operator-(const Transform& transform) const {
    return Transform(this->rotation - transform.rotation, this->translation - transform.translation);
}

Transform& Transform::operator-=(const Transform& transform) {
    this->rotation -= transform.rotation;
    this->translation -= transform.translation;
    return *this;
}

Matrix3 Transform::get_ortho_transform() const
{
    return rotation;
}

Transform Transform::inv(const Transform& transform) const {
    Matrix3 local_rotation(transform.rotation);
    local_rotation.in_place_transpose();
    return Transform(local_rotation, -transform.translation);
}