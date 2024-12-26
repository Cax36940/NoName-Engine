#pragma once
#include "Vector3.hpp"

class Matrix3
{
public:
    // Each Vector3 is a column of the Matrix3 (column-major order)
    Vector3 x;
    Vector3 y;
    Vector3 z;

    /**
     * @brief Default constructor
     */
    Matrix3();

    /**
     * @brief Constructor from column vectors
     */
    Matrix3(const Vector3& x, const Vector3& y, const Vector3& z);

    /**
     * @brief Constructor from diagonal values
     */
    Matrix3(float x, float y, float z);

    /**
     * @brief Equal operator
     * @param vector
     */
    bool operator==(const Matrix3& matrix);

    /**
     * @brief Not Equal operator
     * @param vector
     */
    bool operator!=(const Matrix3& matrix);

    /**
     * @brief Scalar multiplication on the right
     * @param alpha the scalar
     */
    Matrix3 operator*(float alpha) const;

    /**
     * @brief Scalar multiplication assignment
     * @param alpha the scalar
     */
    Matrix3& operator*=(float alpha);

    /**
     * @brief Scalar multiplication on the left
     * @param alpha the scalar
     * @param matrix the matrix
     */
    friend Matrix3 operator*(float alpha, const Matrix3& matrix);

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
     * @brief Scalar division on the right
     * @param alpha the scalar
     */
    Matrix3 operator/(float alpha) const;

    /**
     * @brief Scalar division assignment
     * @param alpha the scalar
     */
    Matrix3& operator/=(float alpha);

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
     * @brief Matrix negate
     */
    Matrix3 operator-() const;

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
     */
    float det() const;

    /**
     * @brief Matrix determinant
     * @param matrix the matrix from which the determinant is calculated
     */
    static float det(const Matrix3& matrix);

    /**
     * @brief Matrix inverse
     */
    Matrix3 inv() const;

    /**
     * @brief Matrix inverse
     * @param matrix the matrix to inverse
     */
    static Matrix3 inv(const Matrix3& matrix);
};



