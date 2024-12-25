#include <cmath>
#include <iostream>

#include "Quaternion.hpp"
#include "Matrix3.hpp"

Quaternion::Quaternion() : w(1), x(0), y(0), z(0) {}

Quaternion::Quaternion(const float& w, const float& x, const float& y, const float& z) : w(w), x(x), y(y), z(z) {}

Quaternion::Quaternion(const Vector3& vector) : w(0), x(vector.x), y(vector.y), z(vector.z) {}

Quaternion::Quaternion(const float& alpha, const Vector3& vector) : w(alpha), x(vector.x), y(vector.y), z(vector.z) {}

bool Quaternion::operator==(const Quaternion& quat)
{
    return (this->w == quat.w) && (this->x == quat.x) && (this->y == quat.y) && (this->z == quat.z);
}

Quaternion Quaternion::operator*(const float& alpha) const {
    return Quaternion(alpha * this->w, alpha * this->x, alpha * this->y, alpha * this->z);
}

Quaternion& Quaternion::operator*=(const float& alpha) {
    this->w *= alpha;
    this->x *= alpha;
    this->y *= alpha;
    this->z *= alpha;
    return *this;
}

Quaternion operator*(const float& alpha, const Quaternion& quat) {
    return Quaternion(alpha * quat.w, alpha * quat.x, alpha * quat.y, alpha * quat.z);
}

Quaternion Quaternion::operator*(const Quaternion& quat) const
{
    Vector3 this_vect(x, y, z);
    Vector3 quat_vect(quat.x, quat.y, quat.z);
    return Quaternion(this->w * quat.w - Vector3::dot(this_vect, quat_vect),
                      this->w * quat_vect + quat.w * this_vect + Vector3::cross(this_vect, quat_vect));
}

Quaternion& Quaternion::operator*=(const Quaternion& quat)
{
    Vector3 this_vect(x, y, z);
    Vector3 quat_vect(quat.x, quat.y, quat.z);
    Vector3 result = this->w * quat_vect + quat.w * this_vect + Vector3::cross(this_vect, quat_vect);
    this->w = this->w * quat.w - Vector3::dot(this_vect, quat_vect);
    this->x = result.x;
    this->y = result.y;
    this->z = result.z;

    return *this;
}

Quaternion Quaternion::operator+(const Quaternion& quat) const
{
    return Quaternion(this->w + quat.w, this->x + quat.x, this->y + quat.y, this->z + quat.z);
}

Quaternion& Quaternion::operator+=(const Quaternion& quat)
{
    this->w += quat.w;
    this->x += quat.x;
    this->y += quat.y;
    this->z += quat.z;
    return *this;
}

Quaternion Quaternion::operator-(const Quaternion& quat) const {
    return Quaternion(this->w - quat.w, this->x - quat.x, this->y - quat.y, this->z - quat.z);
}

Quaternion& Quaternion::operator-=(const Quaternion& quat) {
    this->w -= quat.w;
    this->x -= quat.x;
    this->y -= quat.y;
    this->z -= quat.z;
    return *this;
}

Quaternion& Quaternion::operator-()
{
    this->w = -this->w;
    this->x = -this->x;
    this->y = -this->y;
    this->z = -this->z;
    return *this;
}

Quaternion Quaternion::conj(const Quaternion& quat)
{
    return Quaternion(quat.w, -quat.x, -quat.y, -quat.z);
}

Quaternion Quaternion::diff(const Quaternion& quat_u, const Quaternion& quat_v)
{
    return quat_u * Quaternion::conj(quat_v);
}

Quaternion Quaternion::inv(const Quaternion& quat)
{
    return Quaternion::normalize(Quaternion::conj(quat));
}

float Quaternion::norm(const Quaternion& quat) {
    return sqrtf(quat.w * quat.w + quat.x * quat.x + quat.y * quat.y + quat.z * quat.z);
}

float Quaternion::norm2(const Quaternion& quat) {
    return quat.w * quat.w + quat.x * quat.x + quat.y * quat.y + quat.z * quat.z;
}

float Quaternion::inv_norm(const Quaternion& quat) {
    float ret = 1.0f / sqrtf(quat.w * quat.w + quat.x * quat.x + quat.y * quat.y + quat.z * quat.z);
    if (std::isinf(ret)) {
        std::cerr << "[ERROR] Invalid division by 0 in " << __FILE__ << " : " << __FUNCTION__ << "(line:" << __LINE__ << ")" << std::endl;
        ret = 0; // TODO : Check what is the best thing to return in case of null vector inverse norm 
    }
    return ret;
}

Quaternion Quaternion::normalize(const Quaternion& quat) {
    float inv_norm = Quaternion::inv_norm(quat);
    return inv_norm * quat;
}

float Quaternion::dot(const Quaternion& quat_u, const Quaternion& quat_v) {
    return quat_u.w * quat_v.w + quat_u.x * quat_v.x + quat_u.y * quat_v.y + quat_u.z * quat_v.z;
}

Quaternion Quaternion::exp(const Quaternion& quat, const float& alpha)
{
    float angle = std::acos(quat.w);
    if (isnan(angle)) {
        std::cout << "Angle nan" << std::endl;
    }
    if (angle == 0) {
        return Quaternion();
    }
    return Quaternion(std::cosf(alpha * angle), (std::sinf(alpha * angle)/std::sinf(angle)) * quat.toVector3());
}

Vector3 Quaternion::toVector3() const
{
    return Vector3(this->x, this->y, this->z);
}

Vector3 Quaternion::toVector3(const Quaternion& quat)
{
    return Vector3(quat.x, quat.y, quat.z);
}

Matrix3 Quaternion::toMatrix3(const Quaternion& quat)
{
    const Vector3 x ((1 - 2 * (pow((quat.y), 2) + pow((quat.z), 2))), 2 * (quat.x * quat.y + quat.z * quat.w), 2 * (quat.x * quat.z - quat.y * quat.w));

    const Vector3 y (2 * (quat.x * quat.y - quat.z * quat.w), (1 - 2 * (pow((quat.x), 2) + pow((quat.z), 2))), 2 * (quat.y * quat.z + quat.x * quat.w));

    const Vector3 z (2 * (quat.x * quat.z + quat.y * quat.w), 2 * (quat.y * quat.z - quat.x * quat.w), (1 - 2 * (pow((quat.x), 2) + pow((quat.y), 2))));

    return Matrix3(x, y, z);
}

