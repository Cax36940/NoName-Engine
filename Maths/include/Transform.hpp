#pragma once
#include "Vector4.hpp"
#include "Matrix3.hpp"
class Transform
{
public:

	// row-major order 
    Vector4 x;
    Vector4 y;
    Vector4 z;

    /**
     * @brief Default constructor
     */
    Transform();

    /**
     * @brief Copy constructor
     */
    Transform(const Transform&) = default;

    /**
     * @brief Move constructor
     */
    Transform(Transform&&) = default;

    /**
     * @brief Copy assignment operator
     */
    Transform& operator=(const Transform&) = default;

    /**
     * @brief Move assignment operator
     */
    Transform& operator=(Transform&&) = default;

    /**
     * @brief Destructor
     */
    ~Transform() = default;

    /**
     * @brief Constructor from Vector4 rows
     */
    Transform(const Vector4& x, const Vector4& y, const Vector4& z);

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
    bool operator==(const Transform& matrix);

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
    friend Transform operator*(const float& alpha, const Transform& matrix);

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
    friend Vector4 operator*(const Transform& matrix, const Vector4& vector);

    /**
     * @brief Matrix addition (return new matrix)
     * @param matrix the matrix to add to current matrix
     */
    Transform operator+(const Transform& matrix) const;

    /**
     * @brief Matrix addition assignment
     * @param matrix the matrix to add to current matrix
     */
    Transform& operator+=(const Transform& matrix);

    /**
     * @brief Matrix subtraction (return new matrix)
     * @param matrix the matrix to add to current matrix
     */
    Transform operator-(const Transform& matrix) const;

    /**
     * @brief Matrix subtraction assignment
     * @param matrix the matrix to add to current matrix
     */
    Transform& operator-=(const Transform& matrix);

    /**
     * @brief Return the linear/orthogonal part of the transform
    */
    Matrix3 get_ortho_transform();

};