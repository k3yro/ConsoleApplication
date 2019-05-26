#pragma once

#include <cassert>

namespace k3math {
    union vek2 {
        struct {
            float u;
            float v;
        };
        struct {
            float x;
            float y;
        };

        vek2() {
            this->x = 0.0f;
            this->y = 0.0f;
        }

        vek2(float value) {
            this->x = value;
            this->y = value;
        }

        vek2(float x, float y) {
            this->x = x;
            this->y = y;
        }

        float& operator [] (size_t i) {
            assert(i < 2 && i >= 0);
            return *((&x)+i);
        }

        vek2 operator + (const vek2& other) const {
            return vek2(this->x + other.x, this->y + other.y);
        }

        vek2& operator += (const vek2& other) {
            this->x += other.x;
            this->y += other.y;
            return *this;
        }

        vek2 operator - (const vek2& other) const {
            return vek2(this->x - other.x, this->y - other.y);
        }

        vek2& operator -= (const vek2& other) {
            this->x -= other.x;
            this->y -= other.y;
            return *this;
        }

        vek2 operator - () const {
            return vek2(-this->x, -this->y);
        }

        template<typename T>
        vek2 operator * (const T& scalar) const {
            return vek2(this->x * scalar, this->y * scalar);
        }

        template<typename T>
        vek2 operator *= (const T& scalar) {
            this->x *= scalar;
            this->y *= scalar;
            return *this;
        }

        template<typename T>
        vek2 operator / (const T& scalar) const {
            return vek2(this->x / scalar, this->y / scalar);
        }

        template<typename T>
        vek2 operator /= (const T& scalar) {
            this->x /= scalar;
            this->y /= scalar;
            return *this;
        }

        float sqrLength() const {
            return this->x * this->x + this->y * this->y;
        }

        float length() const {
            return sqrtf(sqrLength());
        }

        vek2& normalize() {
            float l = length();
            if(l == 0) {
                return *this;
            }
            *this /= l;
            return *this;
        }
    
        vek2 normalized() {
            return vek2(this->x, this->y).normalize();
        }

        float dot(vek2& other) {
            return this->x * other.x + this->y * other.y;
        }
    };
}