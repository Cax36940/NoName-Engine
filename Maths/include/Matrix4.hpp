#pragma once
#include "Vector4.hpp"
#include "Matrix3.hpp"
#include "Transform.hpp"

struct Matrix4
{
    // Each Vector4 is a column of the Matrix4 (column-major order)
    Vector4 x;
    Vector4 y;
    Vector4 z;
    Vector4 t;

    /**
     * @brief Default constructor
     */
    Matrix4();

    /**
     * @brief Constructor from column vectors
     */
    Matrix4(const Vector4& x, const Vector4& y, const Vector4& z, const Vector4& t);

    /**
     * @brief Constructor from diagonal values
     */
    Matrix4(float x, float y, float z, float t);

    /**
     * @brief Constructor from Transform
     */
    Matrix4(const Transform& transform);

    /**
     * @brief Equal operator
     * @param vector
     */
    bool operator==(const Matrix4& matrix);

    /**
     * @brief Not Equal operator
     * @param vector
     */
    bool operator!=(const Matrix4& matrix);

    /**
     * @brief Scalar multiplication on the right
     * @param alpha the scalar
     */
    Matrix4 operator*(float alpha) const;

    /**
     * @brief Scalar multiplication assignment
     * @param alpha the scalar
     */
    Matrix4& operator*=(float alpha);

    /**
     * @brief Scalar multiplication on the left
     * @param alpha the scalar
     * @param matrix the matrix
     */
    friend Matrix4 operator*(float alpha, const Matrix4& matrix);

    /**
     * @brief Matrix multiplication
     * @param matrix the left matrix
     * @param matrix the right matrix
     */
    friend Matrix4 operator*(const Matrix4& left_m, const Matrix4& right_m);

    /**
     * @brief Matrix-Vector multiplication
     * @param vector the vector
     * @param matrix the matrix
     */
    friend Vector4 operator*(const Matrix4& matrix, const Vector4& vector);

    /**
     * @brief Scalar division on the right
     * @param alpha the scalar
     */
    Matrix4 operator/(float alpha) const;

    /**
     * @brief Scalar division assignment
     * @param alpha the scalar
     */
    Matrix4& operator/=(float alpha);

    /**
     * @brief Matrix addition (return new matrix)
     * @param matrix the matrix to add to current matrix
     */
    Matrix4 operator+(const Matrix4& matrix) const;

    /**
     * @brief Matrix addition assignment
     * @param matrix the matrix to add to current matrix
     */
    Matrix4& operator+=(const Matrix4& matrix);

    /**
     * @brief Matrix negate
     */
    Matrix4 operator-() const;

    /**
     * @brief Matrix subtraction (return new matrix)
     * @param matrix the matrix to add to current matrix
     */
    Matrix4 operator-(const Matrix4& matrix) const;

    /**
     * @brief Matrix subtraction assignment
     * @param matrix the matrix to add to current matrix
     */
    Matrix4& operator-=(const Matrix4& matrix);

    /**
     * @brief Return the top-left 3 by 3 Matrix
     */
    Matrix3 get_ortho_transform() const;

    /**
     * @brief Return a projection matrix
     */
    static Matrix4 projection(float fov_y, float aspect_ratio, float near, float far);

};
