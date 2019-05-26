#pragma once

#include <cassert>

#include "./vek3.hpp"

namespace k3math {
    union vek4 {
        struct {
            float r;
            float g;
            float b;
            float a;
        };
        struct {
            float x;
            float y;
            float z;
            float w;
	    };

        vek4() {
            this->x = 0.0f;
            this->y = 0.0f;
            this->z = 0.0f;
            this->w = 0.0f;
        }

        vek4(float value) {
            this->x = value;
            this->y = value;
            this->z = value;
            this->w = value;
        }

        vek4(float x, float y, float z, float w) {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        vek4(const vek3& v3) {
            this->x = v3.x;
            this->y = v3.y;
            this->z = v3.z;
            this->w = 0.0f;
        }

        vek4(const vek3& v3, float value) {
            this->x = v3.x;
            this->y = v3.y;
            this->z = v3.z;
            this->w = value;
        }

        float& operator [] (size_t i) {
            assert(i < 4 && i >= 0);
            return *((&x)+i);
        }

        vek4& operator += (const vek4& other) {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
            this->w += other.w;
            return *this;
        }

        vek4 operator + (const vek4& other) const {
            return vek4(this->x + other.y, this->y + other.y, this->z + other.z, this->w + other.w);
        }

        vek4& operator -= (const vek4& other) {
            this->x -= other.x;
            this->y -= other.y;
            this->z -= other.z;
            this->w -= other.w;
            return *this;
        }

        vek4 operator - (const vek4& other) const {
            return vek4(this->x - other.y, this->y - other.y, this->z - other.z, this->w - other.w);
        }

        vek4 operator - () const {
            return vek4(-this->x, -this->y, -this->z, -this->w);
        }

        template<typename T>
        vek4 operator * (const T& scalar) const {
            return vek4(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
        }

        template<typename T>
        vek4 operator *= (const T& scalar) {
            this->x *= scalar;
            this->y *= scalar;
            this->z *= scalar;
            this->w *= scalar;
            return *this;
        }

        template<typename T>
        vek4 operator / (const T& scalar) const {
            return vek4(this->x / scalar, this->y / scalar, this->z / scalar, this->w / scalar);
        }

        template<typename T>
        vek4 operator /= (const T& scalar) {
            this->x /= scalar;
            this->y /= scalar;
            this->z /= scalar;
            this->w /= scalar;
            return *this;
        }

        float length() const {
            return sqrtf(sqrLength());
        }

        float sqrLength() const {
            return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
        }

        vek4& normalize() {
            float l = length();
            if(l == 0) {
                return *this;
            }
            *this /= l;
            return *this;
        }

        vek4 normalized() {
            return vek4(this->x, this->y, this->z, this->w).normalize();
        }

        float dot(vek4& other) {
            return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
        }
    };
}