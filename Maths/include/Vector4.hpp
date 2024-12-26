#pragma once
#include "Vector3.hpp"

struct Vector4
{

    float x;
    float y;
    float z;
    float t;

    /**
     * @brief Default constructor
     */
    Vector4() = default;

    /**
     * @brief Constructor from coordinates
     */
    Vector4(float x, float y, float z, float t);

    /**
     * @brief Constructor from Vector3 and coordinate
     */
    Vector4(const Vector3& vector, float t);

    /**
     * @brief Equal operator
     * @param vector
     */
    bool operator==(const Vector4& vector);

    /**
     * @brief Not Equal operator
     * @param vector
     */
    bool operator!=(const Vector4& vector);

    /**
     * @brief Scalar multiplication on the right
     * @param alpha the scalar
     */
    Vector4 operator*(float alpha) const;

    /**
     * @brief Scalar multiplication assignment
     * @param alpha the scalar
     */
    Vector4& operator*=(float alpha);

    /**
     * @brief Scalar multiplication on the left
     * @param alpha the scalar
     * @param vector the vector
     */
    friend Vector4 operator*(float alpha, const Vector4& vector);

    /**
     * @brief Scalar division on the right
     * @param alpha the scalar
     */
    Vector4 operator/(float alpha) const;

    /**
     * @brief Scalar division assignment
     * @param alpha the scalar
     */
    Vector4& operator/=(float alpha);

    /**
     * @brief Vector addition (return new vector)
     * @param vector the vector to add to current vector
     */
    Vector4 operator+(const Vector4& vector) const;

    /**
     * @brief Vector addition assignment
     * @param vector the vector to add to current vector
     */
    Vector4& operator+=(const Vector4& vector);

    /**
     * @brief Vector negation
     */
    Vector4 operator-() const;

    /**
     * @brief Vector subtraction (return new vector)
     * @param vector the vector to add to current vector
     */
    Vector4 operator-(const Vector4& vector) const;

    /**
     * @brief Vector subtraction assignment
     * @param vector the vector to add to current vector
     */
    Vector4& operator-=(const Vector4& vector);

    /**
     * @brief Vector euclidean norm
     */
    float norm() const;

    /**
     * @brief Vector euclidean norm
     * @param vector The vector from which to take the norm
     */
    static float norm(const Vector4& vector);

    /**
     * @brief Vector euclidean squared norm
     */
    float norm2() const;

    /**
     * @brief Vector euclidean squared norm
     * @param vector The vector from which to take the norm
     */
    static float norm2(const Vector4& vector);

    /**
     * @brief Inverse of vector euclidean norm
     */
    float inv_norm() const;

    /**
     * @brief Inverse of vector euclidean norm
     * @param vector The vector from which to take the norm
     */
    static float inv_norm(const Vector4& vector);

    /**
     * @brief Inverse of vector euclidean norm2
     */
    float inv_norm2() const;

    /**
     * @brief Inverse of vector euclidean norm2
     * @param vector The vector from which to take the norm2
     */
    static float inv_norm2(const Vector4& vector);

    /**
     * @brief Vector normalization
     */
    Vector4 normalize() const;

    /**
     * @brief Vector normalization
     * @param vector The vector to normalize
     */
    static Vector4 normalize(const Vector4& vector);

    /**
     * @brief Convolution between two vectors
     * @param vector_u
     */
    Vector4 conv(const Vector4& vector_u) const;

    /**
     * @brief Convolution between two vectors
     * @param vector_u
     * @param vector_v
     */
    static Vector4 conv(const Vector4& vector_u, const Vector4& vector_v);

    /**
     * @brief Dot product between two vectors
     * @param vector_u
     */
    float dot(const Vector4& vector_u) const;

    /**
     * @brief Dot product between two vectors
     * @param vector_u
     * @param vector_v
     */
    static float dot(const Vector4& vector_u, const Vector4& vector_v);
};

