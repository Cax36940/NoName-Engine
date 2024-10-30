#pragma once
#include "Vector4.hpp"

class Matrix4
{
public:

	
    Vector4 x;
    Vector4 y;
    Vector4 z;
    Vector4 t;

    /**
     * @brief Default constructor
     */
    Matrix4();

    /**
     * @brief Copy constructor
     */
    Matrix4(const Matrix4&) = default;

    /**
     * @brief Move constructor
     */
    Matrix4(Matrix4&&) = default;

    /**
     * @brief Copy assignment operator
     */
    Matrix4& operator=(const Matrix4&) = default;

    /**
     * @brief Move assignment operator
     */
    Matrix4& operator=(Matrix4&&) = default;

    /**
     * @brief Destructor
     */
    ~Matrix4() = default;

    /**
     * @brief Constructor from coordinates
     */
    Matrix4(const Vector4& x, const Vector4& y, const Vector4& z, const Vector4& t);

    /**
     * @brief Equal operator
     * @param vector
     */
    bool operator==(const Matrix4& matrix);

    /**
     * @brief Scalar multiplication on the right
     * @param alpha the scalar
     */
    Matrix4 operator*(const float& alpha) const;

    /**
     * @brief Scalar multiplication assignment
     * @param alpha the scalar
     */
    Matrix4& operator*=(const float& alpha);

    /**
     * @brief Scalar multiplication on the left
     * @param alpha the scalar
     * @param matrix the matrix
     */
    friend Matrix4 operator*(const float& alpha, const Matrix4& matrix);

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
     * @brief Matrix determinant
     * @param matrix the matrix from which the determinant is calculated
     */
    static float determinant(const Matrix4& matrix);

    /**
     * @brief Matrix inverse
     * @param matrix the matrix to inverse
     */
    static Matrix4 inv(const Matrix4& matrix);

};