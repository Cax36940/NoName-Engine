#include <cmath>
#include "Vector4.hpp"

Vector4::Vector4(const float& x, const float& y, const float& z, const float& t) : x(x), y(y), z(z), t(t) {}

glm::vec4 Vector4::to_glm_vec4(const Vector4& vector)
{
    return glm::vec4(vector.x, vector.y, vector.z, vector.t);
}

bool Vector4::operator==(const Vector4& vector)
{
    return (this->x == vector.x) && (this->y == vector.y) && (this->z == vector.z) && (this->z == vector.t);
}

Vector4 Vector4::operator*(const float& alpha) const {
    return Vector4(alpha * this->x, alpha * this->y, alpha * this->z, alpha * this->t);
}

Vector4& Vector4::operator*=(const float& alpha) {
    this->x *= alpha;
    this->y *= alpha;
    this->z *= alpha;
    this->t *= alpha;
    return *this;
}

Vector4 operator*(const float& alpha, const Vector4& vector) {
    return Vector4(alpha * vector.x, alpha * vector.y, alpha * vector.z, alpha * vector.t);
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

float Vector4::norm(const Vector4& vector) {
    return sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.t * vector.t);
}

float Vector4::norm2(const Vector4& vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.t * vector.t;
}

float Vector4::inv_norm(const Vector4& vector) {
    float ret = 1.0f / sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.t * vector.t);
    if (std::isinf(ret)) {
        std::cerr << "[ERROR] Invalid division by 0 in " << __FILE__ << " : " << __FUNCTION__ << "(line:" << __LINE__ << ")" << std::endl;
        ret = 0; // TODO : Check what is the best thing to return in case of null vector inverse norm 
    }
    return ret;
}

Vector4 Vector4::normalize(const Vector4& vector) {
    float inv_norm = Vector4::inv_norm(vector);
    return inv_norm * vector;
}

Vector4 Vector4::conv(const Vector4& vector_u, const Vector4& vector_v) {
    return Vector4(vector_u.x * vector_v.x, vector_u.y * vector_v.y, vector_u.z * vector_v.z, vector_u.t * vector_v.t);
}

float Vector4::dot(const Vector4& vector_u, const Vector4& vector_v) {
    return vector_u.x * vector_v.x + vector_u.y * vector_v.y + vector_u.z * vector_v.z + vector_u.t * vector_v.t;
}

//Vector4 Vector4::cross(const Vector4& vector_u, const Vector4& vector_v) {
//    return Vector4(vector_u.y * vector_v.z - vector_u.z * vector_v.y,
//        vector_u.z * vector_v.x - vector_u.x * vector_v.z,
//        vector_u.x * vector_v.y - vector_u.y * vector_v.x);
//}

Vector4 Vector4::orthogonal_projection(const Vector4& support_v, const Vector4& projected_v)
{
    float support_norm2 = norm2(support_v);
    Vector4 projection = dot(support_v, projected_v) * support_v * (1 / support_norm2);

    return projection;
}
