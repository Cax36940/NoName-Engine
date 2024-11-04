#pragma once
#include "Vector3.hpp"

class Quaternion {

public:
    float w;
    float x;
    float y;
    float z;

    /**
     * @brief Default constructor
     */
    Quaternion();

    /**
     * @brief Copy constructor
     */
    Quaternion(const Quaternion&) = default;

    /**
     * @brief Move constructor
     */
    Quaternion(Quaternion&&) = default;

    /**
     * @brief Copy assignment operator
     */
    Quaternion& operator=(const Quaternion&) = default;

    /**
     * @brief Move assignment operator
     */
    Quaternion& operator=(Quaternion&&) = default;

    /**
     * @brief Destructor
     */
    ~Quaternion() = default;

    /**
     * @brief Constructor from coordinates
     */
    Quaternion(const float& w, const float& x, const float& y, const float& z);

    /**
     * @brief Constructor from vector
     */
    Quaternion(const Vector3& vector);

    /**
     * @brief Constructor from scalar and vector
     */
    Quaternion(const float& alpha, const Vector3& vector);

    /**
     * @brief Equal operator
     * @param quat
     */
    bool operator==(const Quaternion& quat);

    /**
     * @brief Scalar multiplication on the right
     * @param alpha the scalar
     */
    Quaternion operator*(const float& alpha) const;

    /**
     * @brief Scalar multiplication assignment
     * @param alpha the scalar
     */
    Quaternion& operator*=(const float& alpha);

    /**
     * @brief Scalar multiplication on the left
     * @param alpha the scalar
     * @param quat the quaternion
     */
    friend Quaternion operator*(const float& alpha, const Quaternion& quat);

    /**
     * @brief Quaternion product (return new quaternion)
     * @param quat the quaternion to multiply to current quaternion
     */
    Quaternion operator*(const Quaternion& quat) const;

    /**
     * @brief Quaternion product assignment
     * @param quat the quaternion to multiply to current quaternion
     */
    Quaternion& operator*=(const Quaternion& quat);

    /**
     * @brief Quaternion addition (return new quaternion)
     * @param quat the quaternion to add to current quaternion
     */
    Quaternion operator+(const Quaternion& quat) const;

    /**
     * @brief Quaternion addition assignment
     * @param quat the quaternion to add to current quaternion
     */
    Quaternion& operator+=(const Quaternion& quat);

    /**
     * @brief Quaternion subtraction (return new quaternion)
     * @param quat the quaternion to substract to current quaternion
     */
    Quaternion operator-(const Quaternion& quat) const;

    /**
     * @brief Quaternion subtraction assignment
     * @param quat the quaternion to substract to current quaternion
     */
    Quaternion& operator-=(const Quaternion& quat);

    /**
     * @brief Negate quaternion
     */
    Quaternion& operator-();

    /**
     * @brief Quaternion conjugate
     * @param quat The quaternion from which to take the conjugate
     */
    static Quaternion conj(const Quaternion& quat);

    /**
     * @brief Quaternion to go from quat_u to quat_v
     * @param quat_u
     * @param quat_v
     */
    static Quaternion diff(const Quaternion& quat_u, const Quaternion& quat_v);

    /**
     * @brief Quaternion inverse
     * @param quat The quaternion from which to take the inverse
     */
    static Quaternion inv(const Quaternion& quat);

    /**
     * @brief Quaternion euclidean norm
     * @param quat The quaternion from which to take the norm
     */
    static float norm(const Quaternion& quat);

    /**
     * @brief Quaternion euclidean squared norm
     * @param quat The quaternion from which to take the norm
     */
    static float norm2(const Quaternion& quat);

    /**
     * @brief Inverse of quaternion euclidean norm
     * @param quat The quaternion from which to take the norm
     */
    static float inv_norm(const Quaternion& quat);

    /**
     * @brief Quaternion normalization
     * @param quat The quaternion to normalize
     */
    static Quaternion normalize(const Quaternion& quat);

    /**
     * @brief Dot product between two quaternions
     * @param quat_u
     * @param quat_v
     */
    static float dot(const Quaternion& quat_u, const Quaternion& quat_v);

    /**
     * @brief Quaternion exponential
     * @param quat The quaternion to put to a certain power
     * @param alpha A scalar representing the power
     */
    static Quaternion exp(const Quaternion& quat, const float& alpha);

    /**
     * @brief Return the vector part of the quaternion
     */
    Vector3 toVector3() const;
    /**
     * @brief Return the vector part of the quaternion
     * @param quat
     */
    static Vector3 toVector3(const Quaternion& quat);

    /*
    @brief Transform quaternion to matrix
    @param q
    */
    static Matrix3 toMatrix3(const Quaternion& q);

};
