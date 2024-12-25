#pragma once

struct Vector3 {

    float x;
    float y;
    float z;

    /**
     * @brief Default constructor
     */
    Vector3() = default;

    /**
     * @brief Constructor from coordinates
     */
    Vector3(float x, float y, float z);

    /**
     * @brief Equal operator
     * @param vector
     */
    bool operator==(const Vector3& vector);

    /**
     * @brief Not Equal operator
     * @param vector
     */
    bool operator!=(const Vector3& vector);

    /**
     * @brief Scalar multiplication on the right
     * @param alpha the scalar
     */
    Vector3 operator*(float alpha) const;

    /**
     * @brief Scalar multiplication assignment
     * @param alpha the scalar
     */
    Vector3& operator*=(float alpha);

    /**
     * @brief Scalar multiplication on the left
     * @param alpha the scalar
     * @param vector the vector
     */
    friend Vector3 operator*(float alpha, const Vector3& vector);

    /**
     * @brief Scalar division on the right
     * @param alpha the scalar
     */
    Vector3 operator/(float alpha) const;

    /**
     * @brief Scalar division assignment
     * @param alpha the scalar
     */
    Vector3& operator/=(float alpha);

    /**
     * @brief Vector addition (return new vector)
     * @param vector the vector to add to current vector
     */
    Vector3 operator+(const Vector3& vector) const;

    /**
     * @brief Vector addition assignment
     * @param vector the vector to add to current vector
     */
    Vector3& operator+=(const Vector3& vector);

    /**
     * @brief Vector negation
     */
    Vector3 operator-() const;

    /**
     * @brief Vector substraction
     * @param vector the vector to add to current vector
     */
    Vector3 operator-(const Vector3& vector) const;

    /**
     * @brief Vector subtraction assignment
     * @param vector the vector to add to current vector
     */
    Vector3& operator-=(const Vector3& vector);

    /**
     * @brief Vector euclidean norm
     */
    float norm() const;

    /**
     * @brief Vector euclidean norm
     * @param vector The vector from which to take the norm
     */
    static float norm(const Vector3& vector);

    /**
     * @brief Vector euclidean squared norm
     */
    float norm2() const;

    /**
     * @brief Vector euclidean squared norm
     * @param vector The vector from which to take the norm
     */
    static float norm2(const Vector3& vector);

    /**
     * @brief Inverse of vector euclidean norm
     */
    float inv_norm() const;

    /**
     * @brief Inverse of vector euclidean norm
     * @param vector The vector from which to take the norm
     */
    static float inv_norm(const Vector3& vector);

    /**
     * @brief Inverse of vector euclidean norm2
     */
    float inv_norm2() const;

    /**
     * @brief Inverse of vector euclidean norm2
     * @param vector The vector from which to take the norm2
     */
    static float inv_norm2(const Vector3& vector);

    /**
     * @brief Vector normalization
     */
    Vector3 normalize() const;

    /**
     * @brief Vector normalization
     * @param vector The vector to normalize
     */
    static Vector3 normalize(const Vector3& vector);

    /**
     * @brief Convolution between two vectors
     * @param vector_u
     */
    Vector3 conv(const Vector3& vector_u) const;

    /**
     * @brief Convolution between two vectors 
     * @param vector_u
     * @param vector_v
     */
    static Vector3 conv(const Vector3& vector_u, const Vector3& vector_v);

    /**
     * @brief Dot product between two vectors
     * @param vector_u
     */
    float dot(const Vector3& vector_u) const;

    /**
     * @brief Dot product between two vectors
     * @param vector_u
     * @param vector_v
     */
    static float dot(const Vector3& vector_u, const Vector3& vector_v);

    /**
     * @brief Cross product between two vectors
     * @param vector_u
     */
    Vector3 cross(const Vector3& vector_u) const;

    /**
     * @brief Cross product between two vectors
     * @param vector_u
     * @param vector_v
     */
    static Vector3 cross(const Vector3& vector_u, const Vector3& vector_v);

    /**
     * @brief Orthogonal projection of one vector on another
     * @param support The supporting vector
     */
    Vector3 project(const Vector3& support) const;

    /**
     * @brief Orthogonal projection of one vector on another
     * @param projected The vector to project
     * @param support The supporting vector
     */
    static Vector3 project(const Vector3& projected, const Vector3& support);
};
