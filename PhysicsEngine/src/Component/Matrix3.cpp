#define _USE_MATH_DEFINES // Import maths constants
#include <cmath>

#include "Matrix3.hpp"
#include "Vector3.hpp"

Matrix3::Matrix3() : x(1, 0, 0), y(0, 1, 0), z(0, 0, 1) {}

Matrix3::Matrix3(const Vector3& x, const Vector3& y, const Vector3& z) : x(x), y(y), z(z) {}

Matrix3::Matrix3(float x, float y, float z) : x(x, 0, 0), y(0, y, 0), z(0, 0, z) {}

bool Matrix3::operator==(const Matrix3& matrix)
{
    return (this->x == matrix.x) && (this->y == matrix.y) && (this->z == matrix.z);
}

Matrix3 Matrix3::operator*(const float& alpha) const {
    return Matrix3(alpha * this->x, alpha * this->y, alpha * this->z);
}

Matrix3& Matrix3::operator*=(const float& alpha) {
    this->x *= alpha;
    this->y *= alpha;
    this->z *= alpha;
    return *this;
}

Matrix3 operator*(const float& alpha, const Matrix3& matrix) {
    return Matrix3(alpha * matrix.x, alpha * matrix.y, alpha * matrix.z);
}

Matrix3 operator*(const Matrix3& left_m, const Matrix3& right_m)
{
    Matrix3 result;
    result.x.x = left_m.x.x * right_m.x.x + left_m.y.x * right_m.x.y + left_m.z.x * right_m.x.z;
    result.x.y = left_m.x.y * right_m.x.x + left_m.y.y * right_m.x.y + left_m.z.y * right_m.x.z;
    result.x.z = left_m.x.z * right_m.x.x + left_m.y.z * right_m.x.y + left_m.z.z * right_m.x.z;
    result.y.x = left_m.x.x * right_m.y.x + left_m.y.x * right_m.y.y + left_m.z.x * right_m.y.z;
    result.y.y = left_m.x.y * right_m.y.x + left_m.y.y * right_m.y.y + left_m.z.y * right_m.y.z;
    result.y.z = left_m.x.z * right_m.y.x + left_m.y.z * right_m.y.y + left_m.z.z * right_m.y.z;
    result.z.x = left_m.x.x * right_m.z.x + left_m.y.x * right_m.z.y + left_m.z.x * right_m.z.z;
    result.z.y = left_m.x.y * right_m.z.x + left_m.y.y * right_m.z.y + left_m.z.y * right_m.z.z;
    result.z.z = left_m.x.z * right_m.z.x + left_m.y.z * right_m.z.y + left_m.z.z * right_m.z.z;
    return result;
}

Vector3 operator*(const Matrix3& matrix, const Vector3& vector)
{
    float x = vector.x * matrix.x.x + vector.y * matrix.y.x + vector.z * matrix.z.x;
    float y = vector.x * matrix.x.y + vector.y * matrix.y.y + vector.z * matrix.z.y;
    float z = vector.x * matrix.x.z + vector.y * matrix.y.z + vector.z * matrix.z.z;
    return Vector3(x, y, z);
}

Matrix3 Matrix3::operator+(const Matrix3& matrix) const {
    return Matrix3(this->x + matrix.x, this->y + matrix.y, this->z + matrix.z);
}

Matrix3& Matrix3::operator+=(const Matrix3& matrix) {
    this->x += matrix.x;
    this->y += matrix.y;
    this->z += matrix.z;
    return *this;
}

Matrix3 Matrix3::operator-(const Matrix3& matrix) const {
    return Matrix3(this->x - matrix.x, this->y - matrix.y, this->z - matrix.z);
}

Matrix3& Matrix3::operator-=(const Matrix3& matrix) {
    this->x -= matrix.x;
    this->y -= matrix.y;
    this->z -= matrix.z;
    return *this;
}

float Matrix3::determinant(const Matrix3& matrix)
{
    return matrix.x.x * (matrix.y.y * matrix.z.z - matrix.y.z * matrix.z.y)
        - matrix.x.y * (matrix.y.x * matrix.z.z - matrix.y.z * matrix.z.x)
        + matrix.x.z * (matrix.y.x * matrix.z.y - matrix.y.y * matrix.z.x);
}

Matrix3 Matrix3::inv(const Matrix3& matrix)
{
    if (determinant(matrix) == 0.f) {
        return Matrix3(Vector3(0,0,0),Vector3(0,0,0),Vector3(0,0,0));
    }
    Matrix3 temp = matrix;
    Matrix3 inv = Matrix3();
    //1st step
    inv.x.x = 1 / temp.x.x;
    temp.y.x = temp.y.x / temp.x.x;
    temp.z.x = temp.z.x / temp.x.x;
    temp.x.x = 1;

    inv.x.y = -temp.x.y * inv.x.x;
    temp.y.y = temp.y.y - temp.x.y * temp.y.x;
    temp.z.y = temp.z.y - temp.x.y * temp.z.x;
    temp.x.y = 0;

    inv.x.z = -temp.x.z * inv.x.x;
    temp.y.z = temp.y.z - temp.x.z * temp.y.x;
    temp.z.z = temp.z.z - temp.x.z * temp.z.x;
    temp.x.z = 0;
    //2nd step
    inv.y.y = 1 / temp.y.y;
    inv.x.y = inv.x.y / temp.y.y;
    temp.z.y = temp.z.y / temp.y.y;
    temp.y.y = 1;

    inv.x.x = inv.x.x - temp.y.x * inv.x.y;
    inv.y.x = inv.y.x - temp.y.x * inv.y.y;
    temp.z.x = temp.z.x - temp.y.x * temp.z.y;
    temp.y.x = 0;

    inv.x.z = inv.x.z - temp.y.z * inv.x.y;
    inv.y.z = inv.y.z - temp.y.z * inv.y.y;
    temp.z.z = temp.z.z - temp.y.z * temp.z.y;
    temp.y.z = 0;
    //3rd step
    inv.x.z = inv.x.z / temp.z.z;
    inv.y.z = inv.y.z / temp.z.z;
    inv.z.z = 1 / temp.z.z;
    temp.z.z = 1;

    inv.x.x = inv.x.x - temp.z.x * inv.x.z;
    inv.y.x = inv.y.x - temp.z.x * inv.y.z;
    inv.z.x = inv.z.x - temp.z.x * inv.z.z;
    temp.z.x = 0;

    inv.x.y = inv.x.y - temp.z.y * inv.x.z;
    inv.y.y = inv.y.y - temp.z.y * inv.y.z;
    inv.z.y = inv.z.y - temp.z.y * inv.z.z;
    temp.z.y = 0;

    return inv;
}

Matrix3 Matrix3::get_orthonormal_base(const Vector3& vector) // TODO : remove, used only for spring
{
    Vector3 v2 = Vector3(M_PI, M_E, M_SQRT2);
    Vector3 v3;
    Vector3 u1 = Vector3::normalize(vector);
    Vector3 u2;
    Vector3 u3;

    u2 = v2 - Vector3::dot(u1, v2) * u1;
    u2 = Vector3::normalize(u2);

    v3 = Vector3::cross(u1, u2);
    u3 = v3 - Vector3::dot(u1, v3) * u1 - Vector3::dot(u2, v3) * u2;
    u3 = Vector3::normalize(u3);

    return Matrix3(u1, u2, u3);
}
