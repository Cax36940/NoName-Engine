#include <iostream>

#include "Vector4.hpp"

Vector4::Vector4(float x, float y, float z, float t) : x(x), y(y), z(z), t(t) {}

Vector4::Vector4(const Vector3& vector, float t) : x(vector.x), y(vector.y), z(vector.z), t(t) {}

bool Vector4::operator==(const Vector4& vector)
{
    return (this->x == vector.x) && (this->y == vector.y) && (this->z == vector.z) && (this->t == vector.t);
}

bool Vector4::operator!=(const Vector4& vector)
{
    return (this->x != vector.x) || (this->y != vector.y) || (this->z != vector.z) || (this->t != vector.t);
}

Vector4 Vector4::operator*(float alpha) const {
    return Vector4(alpha * this->x, alpha * this->y, alpha * this->z, alpha * this->t);
}

Vector4& Vector4::operator*=(float alpha) {
    this->x *= alpha;
    this->y *= alpha;
    this->z *= alpha;
    this->t *= alpha;
    return *this;
}

Vector4 operator*(float alpha, const Vector4& vector) {
    return Vector4(alpha * vector.x, alpha * vector.y, alpha * vector.z, alpha * vector.t);
}

Vector4 Vector4::operator/(float alpha) const
{
    return Vector4(this->x / alpha, this->y / alpha, this->z / alpha, this->t / alpha);
}

Vector4& Vector4::operator/=(float alpha)
{
    this->x /= alpha;
    this->y /= alpha;
    this->z /= alpha;
    this->t /= alpha;
    return *this;
}

Vector4 Vector4::operator+(const Vector4& vector) const {
    return Vector4(this->x + vector.x, this->y + vector.y, this->z + vector.z, this->t + vector.t);
}

Vector4& Vector4::operator+=(const Vector4& vector) {
    this->x += vector.x;
    this->y += vector.y;
    this->z += vector.z;
    this->t += vector.t;
    return *this;
}

Vector4 Vector4::operator-() const
{
    return Vector4(-this->x, -this->y, -this->z, -this->t);
}

Vector4 Vector4::operator-(const Vector4& vector) const {
    return Vector4(this->x - vector.x, this->y - vector.y, this->z - vector.z, this->t - vector.t);
}

Vector4& Vector4::operator-=(const Vector4& vector) {
    this->x -= vector.x;
    this->y -= vector.y;
    this->z -= vector.z;
    this->t -= vector.t;
    return *this;
}

float Vector4::norm() const
{
    return norm(*this);
}

float Vector4::norm(const Vector4& vector) {
    return sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.t * vector.t);
}

float Vector4::norm2() const
{
    return norm2(*this);
}

float Vector4::norm2(const Vector4& vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.t * vector.t;
}

float Vector4::inv_norm() const
{
    return inv_norm(*this);
}

float Vector4::inv_norm(const Vector4& vector) {
    float norm = sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.t * vector.t);
    if (norm < std::numeric_limits<float>::epsilon()) {
        std::cerr << "[ERROR] Invalid division by 0 in " << __FILE__ << " : " << __FUNCTION__ << "(line:" << __LINE__ << ")" << std::endl;
        return 0.0f;
    }
    return 1.0f / norm;
}

float Vector4::inv_norm2() const
{
    return inv_norm2(*this);
}

float Vector4::inv_norm2(const Vector4& vector)
{
    float norm2 = vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.t * vector.t;
    if (norm2 < std::numeric_limits<float>::epsilon()) {
        std::cerr << "[ERROR] Invalid division by 0 in " << __FILE__ << " : " << __FUNCTION__ << "(line:" << __LINE__ << ")" << std::endl;
        return 0.0f;
    }
    return 1.0f / norm2;
}

Vector4 Vector4::normalize() const
{
    return normalize(*this);
}

Vector4 Vector4::normalize(const Vector4& vector) {
    float inv_norm = Vector4::inv_norm(vector);
    return inv_norm * vector;
}

Vector4 Vector4::conv(const Vector4& vector_u) const
{
    return conv(*this, vector_u);
}

Vector4 Vector4::conv(const Vector4& vector_u, const Vector4& vector_v) {
    return Vector4(vector_u.x * vector_v.x, vector_u.y * vector_v.y, vector_u.z * vector_v.z, vector_u.t * vector_v.t);
}

float Vector4::dot(const Vector4& vector_u) const
{
    return dot(*this, vector_u);
}

float Vector4::dot(const Vector4& vector_u, const Vector4& vector_v) {
    return vector_u.x * vector_v.x + vector_u.y * vector_v.y + vector_u.z * vector_v.z + vector_u.t * vector_v.t;
}
