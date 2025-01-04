#include "Matrix4.hpp"

Matrix4::Matrix4() : x(1, 0, 0, 0), y(0, 1, 0, 0), z(0, 0, 1, 0), t(0, 0, 0, 1) {}

Matrix4::Matrix4(const Vector4& x, const Vector4& y, const Vector4& z, const Vector4& t) : x(x), y(y), z(z), t(t) {}

Matrix4::Matrix4(float x, float y, float z, float t) : x(x, 0, 0, 0), y(0, y, 0, 0), z(0, 0, z, 0), t(0, 0, 0, t) {}

Matrix4::Matrix4(const Transform& transform) :
    x(transform.rotation.x, 0.0f),
    y(transform.rotation.y, 0.0f),
    z(transform.rotation.z, 0.0f),
    t(transform.translation, 1.0f){}

bool Matrix4::operator==(const Matrix4& matrix)
{
    return (this->x == matrix.x) && (this->y == matrix.y) && (this->z == matrix.z) && (this->t == matrix.t);
}

bool Matrix4::operator!=(const Matrix4& matrix)
{
    return (this->x != matrix.x) || (this->y != matrix.y) || (this->z != matrix.z) || (this->t != matrix.t);
}

Matrix4 Matrix4::operator*(float alpha) const {
    return Matrix4(alpha * this->x, alpha * this->y, alpha * this->z, alpha * this->t);
}

Matrix4& Matrix4::operator*=(float alpha) {
    this->x *= alpha;
    this->y *= alpha;
    this->z *= alpha;
    this->t *= alpha;
    return *this;
}

Matrix4 operator*(float alpha, const Matrix4& matrix) {
    return Matrix4(alpha * matrix.x, alpha * matrix.y, alpha * matrix.z, alpha * matrix.t);
}

Matrix4 operator*(const Matrix4& left_m, const Matrix4& right_m)
{
    Matrix4 result;
    result.x.x = left_m.x.x * right_m.x.x + left_m.y.x * right_m.x.y + left_m.z.x * right_m.x.z + left_m.t.x * right_m.x.t;
    result.x.y = left_m.x.y * right_m.x.x + left_m.y.y * right_m.x.y + left_m.z.y * right_m.x.z + left_m.t.y * right_m.x.t;
    result.x.z = left_m.x.z * right_m.x.x + left_m.y.z * right_m.x.y + left_m.z.z * right_m.x.z + left_m.t.z * right_m.x.t;
    result.x.t = left_m.x.t * right_m.x.x + left_m.y.t * right_m.x.y + left_m.z.t * right_m.x.z + left_m.t.t * right_m.x.t;

    result.y.x = left_m.x.x * right_m.y.x + left_m.y.x * right_m.y.y + left_m.z.x * right_m.y.z + left_m.t.x * right_m.y.t;
    result.y.y = left_m.x.y * right_m.y.x + left_m.y.y * right_m.y.y + left_m.z.y * right_m.y.z + left_m.t.y * right_m.y.t;
    result.y.z = left_m.x.z * right_m.y.x + left_m.y.z * right_m.y.y + left_m.z.z * right_m.y.z + left_m.t.z * right_m.y.t;
    result.y.t = left_m.x.t * right_m.y.x + left_m.y.t * right_m.y.y + left_m.z.t * right_m.y.z + left_m.t.t * right_m.y.t;

    result.z.x = left_m.x.x * right_m.z.x + left_m.y.x * right_m.z.y + left_m.z.x * right_m.z.z + left_m.t.x * right_m.z.t;
    result.z.y = left_m.x.y * right_m.z.x + left_m.y.y * right_m.z.y + left_m.z.y * right_m.z.z + left_m.t.y * right_m.z.t;
    result.z.z = left_m.x.z * right_m.z.x + left_m.y.z * right_m.z.y + left_m.z.z * right_m.z.z + left_m.t.z * right_m.z.t;
    result.z.t = left_m.x.t * right_m.z.x + left_m.y.t * right_m.z.y + left_m.z.t * right_m.z.z + left_m.t.t * right_m.z.t;

    result.t.x = left_m.x.x * right_m.t.x + left_m.y.x * right_m.t.y + left_m.z.x * right_m.t.z + left_m.t.x * right_m.t.t;
    result.t.y = left_m.x.y * right_m.t.x + left_m.y.y * right_m.t.y + left_m.z.y * right_m.t.z + left_m.t.y * right_m.t.t;
    result.t.z = left_m.x.z * right_m.t.x + left_m.y.z * right_m.t.y + left_m.z.z * right_m.t.z + left_m.t.z * right_m.t.t;
    result.t.t = left_m.x.t * right_m.t.x + left_m.y.t * right_m.t.y + left_m.z.t * right_m.t.z + left_m.t.t * right_m.t.t;
    return result;
}

Vector4 operator*(const Matrix4& matrix, const Vector4& vector)
{
    float x = vector.x * matrix.x.x + vector.y * matrix.y.x + vector.z * matrix.z.x + vector.t * matrix.t.x;
    float y = vector.x * matrix.x.y + vector.y * matrix.y.y + vector.z * matrix.z.y + vector.t * matrix.t.y;
    float z = vector.x * matrix.x.z + vector.y * matrix.y.z + vector.z * matrix.z.z + vector.t * matrix.t.z;
    float t = vector.x * matrix.x.t + vector.y * matrix.y.t + vector.z * matrix.z.t + vector.t * matrix.t.t;
    return Vector4(x, y, z, t);
}

Matrix4 Matrix4::operator/(float alpha) const
{
    return Matrix4(this->x / alpha, this->y / alpha, this->z / alpha, this->t / alpha);
}

Matrix4& Matrix4::operator/=(float alpha)
{
    this->x /= alpha;
    this->y /= alpha;
    this->z /= alpha;
    this->t /= alpha;
    return *this;
}

Matrix4 Matrix4::operator+(const Matrix4& matrix) const {
    return Matrix4(this->x + matrix.x, this->y + matrix.y, this->z + matrix.z, this->t + matrix.t);
}

Matrix4& Matrix4::operator+=(const Matrix4& matrix) {
    this->x += matrix.x;
    this->y += matrix.y;
    this->z += matrix.z;
    this->t += matrix.t;
    return *this;
}

Matrix4 Matrix4::operator-() const
{
    return Matrix4(-this->x, -this->y, -this->z, -this->t);
}

Matrix4 Matrix4::operator-(const Matrix4& matrix) const {
    return Matrix4(this->x - matrix.x, this->y - matrix.y, this->z - matrix.z, this->t - matrix.t);
}

Matrix4& Matrix4::operator-=(const Matrix4& matrix) {
    this->x -= matrix.x;
    this->y -= matrix.y;
    this->z -= matrix.z;
    this->t -= matrix.t;
    return *this;
}

Matrix3 Matrix4::get_ortho_transform() const
{
    return Matrix3(Vector3(x.x, x.y, x.z), Vector3(y.x, y.y, y.z), Vector3(z.x, z.y, z.z));
}
