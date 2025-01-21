#ifndef LUMENAURA_VEC3
#define LUMENAURA_VEC3


#include <cmath>
#include <iostream>


struct Vec3 {
    float x, y, z;

    // Default constructor
    Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

    // Parameterized constructor
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    // Vector addition
    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    // Vector subtraction
    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    // Scalar multiplication
    Vec3 operator*(float scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    // Dot product
    float dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Cross product
    Vec3 cross(const Vec3& other) const {
        return Vec3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Magnitude of the vector
    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Normalize the vector
    Vec3 normalize() const {
        float len = length();
        return (len > 0.0f) ? (*this * (1.0f / len)) : Vec3(0.0f, 0.0f, 0.0f);
    }

    // Print the vector
    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec) {
        os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }
};

#endif