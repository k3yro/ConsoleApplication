#pragma once

#include <cassert>
#include "./vek2.hpp"

namespace k3math {
    //Todo: union fuer u,v,w (siehe vek2)
    struct vek3 {
        float x;
        float y;
        float z;

        vek3() {
            this->x = 0.0f;
            this->y = 0.0f;
            this->z = 0.0f;
        }

        vek3(float value) {
            this->x = value;
            this->y = value;
            this->z = value;
        }

        vek3(float x, float y, float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        // Konstr. 4... vek3 kann einen vek2 engegennehmen
        vek3(const vek2& v2) {
            this->x = v2.x;
            this->y = v2.y;
            this->z = 0.0f; // z wird auf 0 gesetzt
        }

        // Konstr. 5... wie Konstr 4 mit value fuer z
        vek3(const vek2& v2, float value) {
            this->x = v2.x;
            this->y = v2.y;
            this->z = value; // z wird auf value gesetzt
        }

        float& operator [] (size_t i) {
            assert(i < 3 && i >= 0);
            return *((&x)+i);
        }

        vek3& operator += (const vek3& other) {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
            return *this;
        }

        vek3 operator + (const vek3& other) const {
            return vek3(this->x + other.y, this->y + other.y, this->z + other.z);
        }

        vek3& operator -= (const vek3& other) {
            this->x -= other.x;
            this->y -= other.y;
            this->z -= other.z;
            return *this;
        }

        vek3 operator - (const vek3& other) const {
            return vek3(this->x - other.y, this->y - other.y, this->z - other.z);
        }

        vek3 operator - () const {
            return vek3(-this->x, -this->y, -this->z);
        }

        template<typename T>
        vek3 operator * (const T& scalar) const {
            return vek3(this->x * scalar, this->y * scalar, this->z * scalar);
        }

        template<typename T>
        vek3 operator *= (const T& scalar) {
            this->x *= scalar;
            this->y *= scalar;
            this->z *= scalar;
            return *this;
        }

        template<typename T>
        vek3 operator / (const T& scalar) const {
            return vek3(this->x / scalar, this->y / scalar, this->z / scalar);
        }

        template<typename T>
        vek3 operator /= (const T& scalar) {
            this->x /= scalar;
            this->y /= scalar;
            this->z /= scalar;
            return *this;
        }

        float length() const {
            return sqrtf(sqrLength());
        }

        float sqrLength() const {
            // Eweiterter Pythagoras (x² + y² + z²)
            // Fuer alles Dimensionen erweiterbar (x² + y² + ... + n²)
            return this->x * this->x + this->y * this->y + this->z * this->z;
        }

        vek3& normalize() {
            float l = length();
            if(l == 0) {
                return *this;
            }
            *this /= l;
            return *this;
        }

        vek3 normalized() {
            return vek3(this->x, this->y, this->z).normalize();
        }

        float dot(vek3& other) {
            return this->x * other.x + this->y * other.y + this->z * other.z;
        }
    }; 
}