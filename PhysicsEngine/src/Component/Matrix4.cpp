#define _USE_MATH_DEFINES // Import maths constants
#include <cmath>

#include "Matrix4.hpp"
//#include "Vector4.hpp"

//Matrix4::Matrix4() {
//    Matrix4(Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0), Vector4(0, 0, 1, 0), Vector4(0, 0, 0, 1));
//}
//
//Matrix4::Matrix4(const Vector4& x, const Vector4& y, const Vector4& z, const Vector4& t) : x(x), y(y), z(z), t(t) {}
//
//bool Matrix4::operator==(const Matrix4& matrix)
//{
//    return (this->x == matrix.x) && (this->y == matrix.y) && (this->z == matrix.z) && (this->t == matrix.t);
//}
//
//Matrix4 Matrix4::operator*(const float& alpha) const {
//    return Matrix4(alpha * this->x, alpha * this->y, alpha * this->z, alpha * this->t);
//}
//
//Matrix4& Matrix4::operator*=(const float& alpha) {
//    this->x *= alpha;
//    this->y *= alpha;
//    this->z *= alpha;
//    this->t *= alpha;
//    return *this;
//}
//
//Matrix4 operator*(const float& alpha, const Matrix4& matrix) {
//    return Matrix4(alpha * matrix.x, alpha * matrix.y, alpha * matrix.z, alpha * matrix.t);
//}
//
//Matrix4 operator*(const Matrix4& left_m, const Matrix4& right_m)
//{
//    Matrix4 result;
//
//    result.x.x = left_m.x.x * right_m.x.x + left_m.y.x * right_m.x.y + left_m.z.x * right_m.x.z + left_m.t.x * right_m.x.t;
//    result.x.y = left_m.x.y * right_m.x.x + left_m.y.y * right_m.x.y + left_m.z.y * right_m.x.z + left_m.t.y * right_m.x.t;
//    result.x.z = left_m.x.z * right_m.x.x + left_m.y.z * right_m.x.y + left_m.z.z * right_m.x.z + left_m.t.z * right_m.x.t;
//    result.x.t = left_m.x.t * right_m.x.x + left_m.y.t * right_m.x.y + left_m.z.t * right_m.x.z + left_m.t.t * right_m.x.t;
//
//    result.y.x = left_m.x.x * right_m.y.x + left_m.y.x * right_m.y.y + left_m.z.x * right_m.y.z + left_m.t.x * right_m.y.t;
//    result.y.y = left_m.x.y * right_m.y.x + left_m.y.y * right_m.y.y + left_m.z.y * right_m.y.z + left_m.t.y * right_m.y.t;
//    result.y.z = left_m.x.z * right_m.y.x + left_m.y.z * right_m.y.y + left_m.z.z * right_m.y.z + left_m.t.z * right_m.y.t;
//    result.y.t = left_m.x.t * right_m.y.x + left_m.y.t * right_m.y.y + left_m.z.t * right_m.y.z + left_m.t.t * right_m.y.t;
//
//    result.z.x = left_m.x.x * right_m.z.x + left_m.y.x * right_m.z.y + left_m.z.x * right_m.z.z + left_m.t.x * right_m.z.t;
//    result.z.y = left_m.x.y * right_m.z.x + left_m.y.y * right_m.z.y + left_m.z.y * right_m.z.z + left_m.t.y * right_m.z.t;
//    result.z.z = left_m.x.z * right_m.z.x + left_m.y.z * right_m.z.y + left_m.z.z * right_m.z.z + left_m.t.z * right_m.z.t;
//    result.z.t = left_m.x.t * right_m.z.x + left_m.y.t * right_m.z.y + left_m.z.t * right_m.z.z + left_m.t.t * right_m.z.t;
//
//    result.t.x = left_m.x.x * right_m.t.x + left_m.y.x * right_m.t.y + left_m.z.x * right_m.t.z + left_m.t.x * right_m.t.t;
//    result.t.y = left_m.x.y * right_m.t.x + left_m.y.y * right_m.t.y + left_m.z.y * right_m.t.z + left_m.t.y * right_m.t.t;
//    result.t.z = left_m.x.z * right_m.t.x + left_m.y.z * right_m.t.y + left_m.z.z * right_m.t.z + left_m.t.z * right_m.t.t;
//    result.t.t = left_m.x.t * right_m.t.x + left_m.y.t * right_m.t.y + left_m.z.t * right_m.t.z + left_m.t.t * right_m.t.t;
//    
//    return result;
//}
//
//Vector4 operator*(const Matrix4& matrix, const Vector4& vector) {
//    float x = vector.x * matrix.x.x + vector.y * matrix.y.x + vector.z * matrix.z.x + vector.t * matrix.t.x;
//    float y = vector.x * matrix.x.y + vector.y * matrix.y.y + vector.z * matrix.z.y + vector.t * matrix.t.y;
//    float z = vector.x * matrix.x.z + vector.y * matrix.y.z + vector.z * matrix.z.z + vector.t * matrix.t.z;
//    float t = vector.x * matrix.x.t + vector.y * matrix.y.t + vector.z * matrix.z.t + vector.t * matrix.t.t;
//    return Vector4(x, y, z, t);
//}
//
//
//Matrix4 Matrix4::operator+(const Matrix4& matrix) const {
//    return Matrix4(this->x + matrix.x, this->y + matrix.y, this->z + matrix.z, this->t + matrix.t);
//}
//
//Matrix4& Matrix4::operator+=(const Matrix4& matrix) {
//    this->x += matrix.x;
//    this->y += matrix.y;
//    this->z += matrix.z;
//    this->t += matrix.t;
//    return *this;
//}
//
//Matrix4 Matrix4::operator-(const Matrix4& matrix) const {
//    return Matrix4(this->x - matrix.x, this->y - matrix.y, this->z - matrix.z, this->t - matrix.t);
//}
//
//Matrix4& Matrix4::operator-=(const Matrix4& matrix) {
//    this->x -= matrix.x;
//    this->y -= matrix.y;
//    this->z -= matrix.z;
//    this->t -= matrix.t;
//    return *this;
//}
//
//float Matrix4::determinant(const Matrix4& matrix) {
//    return
//        matrix.x.x * (matrix.y.y * (matrix.z.z * matrix.t.t - matrix.z.t * matrix.t.z) -
//            matrix.y.z * (matrix.z.y * matrix.t.t - matrix.z.t * matrix.t.y) +
//            matrix.y.t * (matrix.z.y * matrix.t.z - matrix.z.z * matrix.t.y))
//        - matrix.x.y * (matrix.y.x * (matrix.z.z * matrix.t.t - matrix.z.t * matrix.t.z) -
//            matrix.y.z * (matrix.z.x * matrix.t.t - matrix.z.t * matrix.t.x) +
//            matrix.y.t * (matrix.z.x * matrix.t.z - matrix.z.z * matrix.t.x))
//        + matrix.x.z * (matrix.y.x * (matrix.z.y * matrix.t.t - matrix.z.t * matrix.t.y) -
//            matrix.y.y * (matrix.z.x * matrix.t.t - matrix.z.t * matrix.t.x) +
//            matrix.y.t * (matrix.z.x * matrix.t.y - matrix.z.y * matrix.t.x))
//        - matrix.x.t * (matrix.y.x * (matrix.z.y * matrix.t.z - matrix.z.z * matrix.t.y) -
//            matrix.y.y * (matrix.z.x * matrix.t.z - matrix.z.z * matrix.t.x) +
//            matrix.y.z * (matrix.z.x * matrix.t.y - matrix.z.y * matrix.t.x));
//}
//
//
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