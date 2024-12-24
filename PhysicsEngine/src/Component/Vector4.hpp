#pragma once
#include "Vector3.hpp"

class Vector4
{

public:
    float x;
    float y;
    float z;
    float t;

    /**
     * @brief Default constructor
     */
    Vector4() = default;

    /**
     * @brief Copy constructor
     */
    Vector4(const Vector4&) = default;

    /**
     * @brief Move constructor
     */
    Vector4(Vector4&&) = default;

    /**
     * @brief Copy assignment operator
     */
    Vector4& operator=(const Vector4&) = default;

    /**
     * @brief Move assignment operator
     */
    Vector4& operator=(Vector4&&) = default;

    /**
     * @brief Destructor
     */
    ~Vector4() = default;

    /**
     * @brief Constructor from coordinates
     */
    Vector4(const float& x, const float& y, const float& z, const float& t);

    /**
     * @brief Constructor from Vector3 and coordinate
     */
    Vector4(const Vector3& vector, const float& t);

    /**
     * @brief Equal operator
     * @param vector
     */
    bool operator==(const Vector4& vector);

    /**
     * @brief Scalar multiplication on the right
     * @param alpha the scalar
     */
    Vector4 operator*(const float& alpha) const;

    /**
     * @brief Scalar multiplication assignment
     * @param alpha the scalar
     */
    Vector4& operator*=(const float& alpha);

    /**
     * @brief Scalar multiplication on the left
     * @param alpha the scalar
     * @param vector the vector
     */
    friend Vector4 operator*(const float& alpha, const Vector4& vector);

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
     * @param vector The vector from which to take the norm
     */
    static float norm(const Vector4& vector);

    /**
     * @brief Vector euclidean squared norm
     * @param vector The vector from which to take the norm
     */
    static float norm2(const Vector4& vector);

    /**
     * @brief Inverse of vector euclidean norm
     * @param vector The vector from which to take the norm
     */
    static float inv_norm(const Vector4& vector);

    /**
     * @brief Vector normalization
     * @param vector The vector to normalize
     */
    static Vector4 normalize(const Vector4& vector);

    /**
     * @brief Convolution between two vectors
     * @param vector_u
     * @param vector_v
     */
    static Vector4 conv(const Vector4& vector_u, const Vector4& vector_v);

    /**
     * @brief Dot product between two vectors
     * @param vector_u
     * @param vector_v
     */
    static float dot(const Vector4& vector_u, const Vector4& vector_v);
};

