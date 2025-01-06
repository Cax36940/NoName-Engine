#pragma once
#include "Vector4.hpp"
#include "Matrix3.hpp"

struct Transform
{

    Matrix3 rotation;
    Vector3 translation;

    /**
     * @brief Default constructor
     */
    Transform();

    /**
     * @brief Constructor from Vector3 columns
     */
    Transform(const Vector3& x, const Vector3& y, const Vector3& z, const Vector3& t);

    /**
     * @brief Constructor from a Matrix3 and a Vector3
     */
    Transform(const Matrix3& matrix, const Vector3& vector = Vector3());

    /**
     * @brief Equal operator
     * @param vector
     */
    bool operator==(const Transform& transform);

    /**
     * @brief Not Equal operator
     * @param vector
     */
    bool operator!=(const Transform& transform);

    /**
     * @brief Scalar multiplication on the right
     * @param alpha the scalar
     */
    Transform operator*(const float& alpha) const;

    /**
     * @brief Scalar multiplication assignment
     * @param alpha the scalar
     */
    Transform& operator*=(const float& alpha);

    /**
     * @brief Scalar multiplication on the left
     * @param alpha the scalar
     * @param matrix the matrix
     */
    friend Transform operator*(const float& alpha, const Transform& transform);

    /**
     * @brief Matrix multiplication
     * @param matrix the left matrix
     * @param matrix the right matrix
     */
    friend Transform operator*(const Transform& left_m, const Transform& right_m);

    /**
     * @brief Matrix-Vector multiplication
     * @param vector the vector
     * @param matrix the matrix
     */
    friend Vector4 operator*(const Transform& transform, const Vector4& vector);

    /**
     * @brief Scalar division on the right
     * @param alpha the scalar
     */
    Transform operator/(float alpha) const;

    /**
     * @brief Scalar division assignment
     * @param alpha the scalar
     */
    Transform& operator/=(float alpha);

    /**
     * @brief Matrix addition (return new matrix)
     * @param matrix the matrix to add to current matrix
     */
    Transform operator+(const Transform& transform) const;

    /**
     * @brief Matrix addition assignment
     * @param matrix the matrix to add to current matrix
     */
    Transform& operator+=(const Transform& transform);

    /**
     * @brief Matrix negate
     */
    Transform operator-() const;

    /**
     * @brief Matrix subtraction (return new matrix)
     * @param matrix the matrix to add to current matrix
     */
    Transform operator-(const Transform& transform) const;

    /**
     * @brief Matrix subtraction assignment
     * @param matrix the matrix to add to current matrix
     */
    Transform& operator-=(const Transform& transform);

    /**
     * @brief Return the invert transform
    */
    Transform inv(const Transform& transform) const;

};