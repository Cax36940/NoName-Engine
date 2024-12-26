#include <iostream>

#include "Vector3.hpp"

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

bool Vector3::operator==(const Vector3& vector)
{
    return (this->x == vector.x) && (this->y == vector.y) && (this->z == vector.z);
}

bool Vector3::operator!=(const Vector3& vector)
{
    return (this->x != vector.x) || (this->y != vector.y) || (this->z != vector.z);
}

Vector3 Vector3::operator*(float alpha) const {
    return Vector3(alpha * this->x, alpha * this->y, alpha * this->z);
}

Vector3& Vector3::operator*=(float alpha) {
    this->x *= alpha;
    this->y *= alpha;
    this->z *= alpha;
    return *this;
}

Vector3 operator*(float alpha, const Vector3& vector) {
    return Vector3(alpha * vector.x, alpha * vector.y, alpha * vector.z);
}

Vector3 Vector3::operator/(float alpha) const
{
    return Vector3(this->x / alpha, this->y / alpha, this->z / alpha);
}

Vector3& Vector3::operator/=(float alpha)
{
    this->x /= alpha;
    this->y /= alpha;
    this->z /= alpha;
    return *this;
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

Vector3 Vector3::operator-() const
{
    return Vector3(-this->x, -this->y, -this->z);
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

float Vector3::norm() const
{
    return norm(*this);
}

float Vector3::norm(const Vector3& vector) {
    return sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

float Vector3::norm2() const
{
    return norm2(*this);
}

float Vector3::norm2(const Vector3& vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

float Vector3::inv_norm() const
{
    return inv_norm(*this);
}

float Vector3::inv_norm(const Vector3& vector) {
    float norm = sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    if (norm < std::numeric_limits<float>::epsilon()) {
         std::cerr << "[ERROR] Invalid division by 0 in " << __FILE__ << " : " << __FUNCTION__ << "(line:" << __LINE__ << ")" << std::endl;
         return 0.0f;
    }
    return 1.0f / norm;
}

float Vector3::inv_norm2() const
{
    return inv_norm2(*this);
}

float Vector3::inv_norm2(const Vector3& vector)
{
    float norm2 = vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
    if (norm2 < std::numeric_limits<float>::epsilon()) {
        std::cerr << "[ERROR] Invalid division by 0 in " << __FILE__ << " : " << __FUNCTION__ << "(line:" << __LINE__ << ")" << std::endl;
        return 0.0f;
    }
    return 1.0f / norm2;
}

Vector3 Vector3::normalize() const
{
    return normalize(*this);
}

Vector3 Vector3::normalize(const Vector3& vector) {
    float inv_norm = Vector3::inv_norm(vector);
    return inv_norm * vector;
}

Vector3 Vector3::conv(const Vector3& vector_u) const
{
    return conv(*this, vector_u);
}

Vector3 Vector3::conv(const Vector3& vector_u, const Vector3& vector_v) {
    return Vector3(vector_u.x * vector_v.x, vector_u.y * vector_v.y, vector_u.z * vector_v.z);
}

float Vector3::dot(const Vector3& vector_u) const
{
    return dot(*this, vector_u);
}

float Vector3::dot(const Vector3& vector_u, const Vector3& vector_v) {
    return vector_u.x * vector_v.x + vector_u.y * vector_v.y + vector_u.z * vector_v.z;
}

Vector3 Vector3::cross(const Vector3& vector_u) const
{
    return cross(*this, vector_u);
}

Vector3 Vector3::cross(const Vector3& vector_u, const Vector3& vector_v) {
    return Vector3(vector_u.y * vector_v.z - vector_u.z * vector_v.y,
        vector_u.z * vector_v.x - vector_u.x * vector_v.z,
        vector_u.x * vector_v.y - vector_u.y * vector_v.x);
}

Vector3 Vector3::project(const Vector3& support) const
{
    return project(*this, support);
}

Vector3 Vector3::project(const Vector3& projected, const Vector3& support)
{
    float inv_support_norm2 = inv_norm2(support);
    Vector3 projection = (dot(support, projected) * inv_support_norm2) * support;
    return projection;
}
