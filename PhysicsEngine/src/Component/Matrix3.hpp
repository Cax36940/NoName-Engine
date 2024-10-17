#pragma once
#include "Vector3.hpp"

class Matrix3
{
public:
    Vector3 x;
    Vector3 y;
    Vector3 z;

    /**
     * @brief Default constructor
     */
    Matrix3();

    /**
     * @brief Copy constructor
     */
    Matrix3(const Matrix3&) = default;

    /**
     * @brief Move constructor
     */
    Matrix3(Matrix3&&) = default;

    /**
     * @brief Copy assignment operator
     */
    Matrix3& operator=(const Matrix3&) = default;

    /**
     * @brief Move assignment operator
     */
    Matrix3& operator=(Matrix3&&) = default;

    /**
     * @brief Destructor
     */
    ~Matrix3() = default;

    /**
     * @brief Constructor from coordinates
     */
    Matrix3(const Vector3& x, const Vector3& y, const Vector3& z);

    /**
     * @brief Equal operator
     * @param vector
     */
    bool operator==(const Matrix3& matrix);

    /**
     * @brief Scalar multiplication on the right
     * @param alpha the scalar
     */
    Matrix3 operator*(const float& alpha) const;

    /**
     * @brief Scalar multiplication assignment
     * @param alpha the scalar
     */
    Matrix3& operator*=(const float& alpha);

    /**
     * @brief Scalar multiplication on the left
     * @param alpha the scalar
     * @param matrix the matrix
     */
    friend Matrix3 operator*(const float& alpha, const Matrix3& matrix);

    /**
     * @brief Matrix multiplication
     * @param matrix the left matrix
     * @param matrix the right matrix
     */
    friend Matrix3 operator*(const Matrix3& left_m, const Matrix3& right_m);

    /**
     * @brief Matrix-Vector multiplication
     * @param vector the vector
     * @param matrix the matrix
     */
    friend Vector3 operator*(const Matrix3& matrix, const Vector3& vector);

    /**
     * @brief Matrix addition (return new matrix)
     * @param matrix the matrix to add to current matrix
     */
    Matrix3 operator+(const Matrix3& matrix) const;

    /**
     * @brief Matrix addition assignment
     * @param matrix the matrix to add to current matrix
     */
    Matrix3& operator+=(const Matrix3& matrix);

    /**
     * @brief Matrix subtraction (return new matrix)
     * @param matrix the matrix to add to current matrix
     */
    Matrix3 operator-(const Matrix3& matrix) const;

    /**
     * @brief Matrix subtraction assignment
     * @param matrix the matrix to add to current matrix
     */
    Matrix3& operator-=(const Matrix3& matrix);

    /**
     * @brief Matrix determinant
     * @param matrix the matrix from which the determinant is calculated
     */
    static float determinant(const Matrix3& matrix);

    /**
     * @brief Matrix inverse
     * @param matrix the matrix to inverse
     */
    static Matrix3 inv(const Matrix3& matrix);

    /**
     * @brief Create an orthonormal base
     * @param vector the vector from which the base is constructed
     */
    static Matrix3 get_orthonormal_base(const Vector3& vector);
};



