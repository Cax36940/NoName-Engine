#define _USE_MATH_DEFINES // Import maths constants
#include <cmath>

#include "Matrix4.hpp"

Matrix4::Matrix4() {
    Matrix4(Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0), Vector4(0, 0, 1, 0));
}

Matrix4::Matrix4(const Vector4& x, const Vector4& y, const Vector4& z) : x(x), y(y), z(z) {}

Matrix4::Matrix4(const Vector3& x, const Vector3& y, const Vector3& z, const Vector3& t) : 
    x(x.x, y.x, z.x, t.x), 
    y(x.y, y.y, z.y, t.y),
    z(x.z, y.z, z.z, t.z) {}

Matrix4::Matrix4(const Matrix3& matrix, const Vector3& vector) : 
    x(matrix.x.x, matrix.y.x, matrix.z.x, vector.x), 
    y(matrix.x.y, matrix.y.y, matrix.z.y, vector.y), 
    z(matrix.x.z, matrix.y.z, matrix.z.z, vector.z) {}

bool Matrix4::operator==(const Matrix4& matrix)
{
    return (this->x == matrix.x) && (this->y == matrix.y) && (this->z == matrix.z);
}

Matrix4 Matrix4::operator*(const float& alpha) const {
    return Matrix4(alpha * this->x, alpha * this->y, alpha * this->z);
}

Matrix4& Matrix4::operator*=(const float& alpha) {
    this->x *= alpha;
    this->y *= alpha;
    this->z *= alpha;
    return *this;
}

Matrix4 operator*(const float& alpha, const Matrix4& matrix) {
    return Matrix4(alpha * matrix.x, alpha * matrix.y, alpha * matrix.z);
}

Matrix4 operator*(const Matrix4& left_m, const Matrix4& right_m)
{
    Matrix4 result;

    Vector4 tmp(right_m.x.x, right_m.y.x, right_m.z.x, 0);

    result.x.x = Vector4::dot(left_m.x, tmp);
    result.y.x = Vector4::dot(left_m.y, tmp);
    result.z.x = Vector4::dot(left_m.z, tmp);

    tmp = Vector4(right_m.x.y, right_m.y.y, right_m.z.y, 0);

    result.x.y = Vector4::dot(left_m.x, tmp);
    result.y.y = Vector4::dot(left_m.y, tmp);
    result.z.y = Vector4::dot(left_m.z, tmp);

    tmp = Vector4(right_m.x.z, right_m.y.z, right_m.z.z, 0);

    result.x.z = Vector4::dot(left_m.x, tmp);
    result.y.z = Vector4::dot(left_m.y, tmp);
    result.z.z = Vector4::dot(left_m.z, tmp);

    tmp = Vector4(right_m.x.t, right_m.y.t, right_m.z.t, 1);

    result.x.t = Vector4::dot(left_m.x, tmp);
    result.y.t = Vector4::dot(left_m.y, tmp);
    result.z.t = Vector4::dot(left_m.z, tmp);

    return result;
}

Vector4 operator*(const Matrix4& matrix, const Vector4& vector) {
    float x = vector.x * matrix.x.x + vector.y * matrix.x.y + vector.z * matrix.x.z + vector.t * matrix.x.t;
    float y = vector.x * matrix.y.x + vector.y * matrix.y.y + vector.z * matrix.y.z + vector.t * matrix.y.t;
    float z = vector.x * matrix.z.x + vector.y * matrix.z.y + vector.z * matrix.z.z + vector.t * matrix.z.t;
    return Vector4(x, y, z, vector.t);
}


Matrix4 Matrix4::operator+(const Matrix4& matrix) const {
    return Matrix4(this->x + matrix.x, this->y + matrix.y, this->z + matrix.z);
}

Matrix4& Matrix4::operator+=(const Matrix4& matrix) {
    this->x += matrix.x;
    this->y += matrix.y;
    this->z += matrix.z;
    return *this;
}

Matrix4 Matrix4::operator-(const Matrix4& matrix) const {
    return Matrix4(this->x - matrix.x, this->y - matrix.y, this->z - matrix.z);
}

Matrix4& Matrix4::operator-=(const Matrix4& matrix) {
    this->x -= matrix.x;
    this->y -= matrix.y;
    this->z -= matrix.z;
    return *this;
}

Matrix3 Matrix4::get_ortho_transform()
{
    return Matrix3(Vector3(x.x, x.y, x.z), Vector3(y.x, y.y, y.z), Vector3(z.x, z.y, z.z));
}

/*float Matrix4::determinant(const Matrix4& matrix) {
    return
        matrix.x.x * (matrix.y.y * (matrix.z.z * matrix.t.t - matrix.z.t * matrix.t.z) -
            matrix.y.z * (matrix.z.y * matrix.t.t - matrix.z.t * matrix.t.y) +
            matrix.y.t * (matrix.z.y * matrix.t.z - matrix.z.z * matrix.t.y))
        - matrix.x.y * (matrix.y.x * (matrix.z.z * matrix.t.t - matrix.z.t * matrix.t.z) -
            matrix.y.z * (matrix.z.x * matrix.t.t - matrix.z.t * matrix.t.x) +
            matrix.y.t * (matrix.z.x * matrix.t.z - matrix.z.z * matrix.t.x))
        + matrix.x.z * (matrix.y.x * (matrix.z.y * matrix.t.t - matrix.z.t * matrix.t.y) -
            matrix.y.y * (matrix.z.x * matrix.t.t - matrix.z.t * matrix.t.x) +
            matrix.y.t * (matrix.z.x * matrix.t.y - matrix.z.y * matrix.t.x))
        - matrix.x.t * (matrix.y.x * (matrix.z.y * matrix.t.z - matrix.z.z * matrix.t.y) -
            matrix.y.y * (matrix.z.x * matrix.t.z - matrix.z.z * matrix.t.x) +
            matrix.y.z * (matrix.z.x * matrix.t.y - matrix.z.y * matrix.t.x));
}*/


//Matrix4 Matrix4::inv(const Matrix4& matrix) {
//    Matrix4 temp = matrix;
//    Matrix4 inv = Matrix4();
//
//    // Étape 1
//    inv.x.x = 1 / temp.x.x;
//    temp.y.x = temp.y.x / temp.x.x;
//    temp.z.x = temp.z.x / temp.x.x;
//    temp.t.x = temp.t.x / temp.x.x;
//    temp.x.x = 1;
//
//    inv.x.y = -temp.x.y * inv.x.x;
//    temp.y.y = temp.y.y - temp.x.y * temp.y.x;
//    temp.z.y = temp.z.y - temp.x.y * temp.z.x;
//    temp.t.y = temp.t.y - temp.x.y * temp.t.x;
//    temp.x.y = 0;
//
//    inv.x.z = -temp.x.z * inv.x.x;
//    temp.y.z = temp.y.z - temp.x.z * temp.y.x;
//    temp.z.z = temp.z.z - temp.x.z * temp.z.x;
//    temp.t.z = temp.t.z - temp.x.z * temp.t.x;
//    temp.x.z = 0;
//
//    inv.x.t = -temp.x.t * inv.x.x;
//    temp.y.t = temp.y.t - temp.x.t * temp.y.x;
//    temp.z.t = temp.z.t - temp.x.t * temp.z.x;
//    temp.t.t = temp.t.t - temp.x.t * temp.t.x;
//    temp.x.t = 0;
//
//    // Étape 2
//    inv.y.y = 1 / temp.y.y;
//    inv.x.y = inv.x.y / temp.y.y;
//    temp.z.y = temp.z.y / temp.y.y;
//    temp.t.y = temp.t.y / temp.y.y;
//    temp.y.y = 1;
//
//    inv.x.x = inv.x.x - temp.y.x * inv.x.y;
//    inv.y.x = inv.y.x - temp.y.x * inv.y.y;
//    temp.z.x = temp.z.x - temp.y.x * temp.z.y;
//    temp.t.x = temp.t.x - temp.y.x * temp.t.y;
//    temp.y.x = 0;
//
//    inv.x.z = inv.x.z - temp.y.z * inv.x.y;
//    inv.y.z = inv.y.z - temp.y.z * inv.y.y;
//    temp.z.z = temp.z.z - temp.y.z * temp.z.y;
//    temp.t.z = temp.t.z - temp.y.z * temp.t.y;
//    temp.y.z = 0;
//
//    inv.x.t = inv.x.t - temp.y.t * inv.x.y;
//    inv.y.t = inv.y.t - temp.y.t * inv.y.y;
//    temp.z.t = temp.z.t - temp.y.t * temp.z.y;
//    temp.t.t = temp.t.t - temp.y.t * temp.t.y;
//    temp.y.t = 0;
//
//    // Étape 3
//    inv.z.z = 1 / temp.z.z;
//    inv.x.z = inv.x.z / temp.z.z;
//    inv.y.z = inv.y.z / temp.z.z;
//    temp.t.z = temp.t.z / temp.z.z;
//    temp.z.z = 1;
//
//    inv.x.x = inv.x.x - temp.z.x * inv.x.z;
//    inv.y.x = inv.y.x - temp.z.x * inv.y.z;
//    inv.z.x = inv.z.x - temp.z.x * inv.z.z;
//    temp.t.x = temp.t.x - temp.z.x * temp.t.z;
//    temp.z.x = 0;
//
//    inv.x.y = inv.x.y - temp.z.y * inv.x.z;
//    inv.y.y = inv.y.y - temp.z.y * inv.y.z;
//    inv.z.y = inv.z.y - temp.z.y * inv.z.z;
//    temp.t.y = temp.t.y - temp.z.y * temp.t.z;
//    temp.z.y = 0;
//
//    // Étape 4
//    inv.t.t = 1 / temp.t.t;
//    inv.x.t = inv.x.t / temp.t.t;
//    inv.y.t = inv.y.t / temp.t.t;
//    inv.z.t = inv.z.t / temp.t.t;
//    temp.t.t = 1;
//
//    inv.x.x = inv.x.x - temp.t.x * inv.x.t;
//    inv.y.x = inv.y.x - temp.t.x * inv.y.t;
//    inv.z.x = inv.z.x - temp.t.x * inv.z.t;
//    temp.t.x = 0;
//
//    inv.x.y = inv.x.y - temp.t.y * inv.x.t;
//    inv.y.y = inv.y.y - temp.t.y * inv.y.t;
//    inv.z.y = inv.z.y - temp.t.y * inv.z.t;
//    temp.t.y = 0;
//
//    inv.x.z = inv.x.z - temp.t.z * inv.x.t;
//    inv.y.z = inv.y.z - temp.t.z * inv.y.t;
//    inv.z.z = inv.z.z - temp.t.z * inv.z.t;
//    temp.t.z = 0;
//
//    return inv;
//}