#include <cmath>
#include "Vector3.hpp"

Vector3::Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}

bool Vector3::operator==(const Vector3& vector)
{
    return (this->x == vector.x) && (this->y == vector.y) && (this->z == vector.z);
}

Vector3 Vector3::operator*(const float alpha) const {
    return Vector3(alpha * this->x, alpha * this->y, alpha * this->z);
}

Vector3& Vector3::operator*=(const float alpha) {
    this->x *= alpha;
    this->y *= alpha;
    this->z *= alpha;
    return *this;
}

Vector3 operator*(const float alpha, const Vector3& vector) {
    return Vector3(alpha * vector.x, alpha * vector.y, alpha * vector.z);
}

Vector3 Vector3::operator+(const Vector3& vector) const {
    return Vector3(this->x + vector.x, this->y + vector.y, this->z + vector.z);
}

Vector3& Vector3::operator+=(const Vector3& vector) {
    this->x += vector.x;
    this->y += vector.y;
    this->z += vector.z;
    return *this;
}

Vector3 Vector3::operator-(const Vector3& vector) const {
    return Vector3(this->x - vector.x, this->y - vector.y, this->z - vector.z);
}

Vector3& Vector3::operator-=(const Vector3& vector) {
    this->x -= vector.x;
    this->y -= vector.y;
    this->z -= vector.z;
    return *this;
}

float Vector3::norm(const Vector3& vector) {
    return sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

float Vector3::norm2(const Vector3& vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

float Vector3::inv_norm(const Vector3& vector) {
    return 1/sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

Vector3 Vector3::normalize(const Vector3& vector) {
    float inv_norm = Vector3::inv_norm(vector);
    return inv_norm * vector;
}

Vector3 Vector3::conv(const Vector3& vector_u, const Vector3& vector_v) {
    return Vector3(vector_u.x * vector_v.x, vector_u.y * vector_v.y, vector_u.z * vector_v.z);
}

float Vector3::dot(const Vector3& vector_u, const Vector3& vector_v) {
    return vector_u.x * vector_v.x + vector_u.y * vector_v.y + vector_u.z * vector_v.z;
}

Vector3 Vector3::cross(const Vector3& vector_u, const Vector3& vector_v) {
    return Vector3(vector_u.y * vector_v.z - vector_u.z * vector_v.y,
        vector_u.z * vector_v.x - vector_u.x * vector_v.z,
        vector_u.x * vector_v.y - vector_u.y * vector_v.x);
}
