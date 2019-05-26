#pragma once

#include <cassert>

namespace k3math {
    // union... Abfrage mit x,y und u,v moeglich
    union vek2 {
        struct {
            float u; // u, x = Gleicher Speicherbereich
            float v; // v, y = ...
        };
        struct {
            float x;
            float y;
        };

        // Konstr. 1 (ohne Param): x, y = 0.0f;
        vek2() {
            this->x = 0.0f;
            this->y = 0.0f;
        }

        // Konstr. 2 (1 Param): x, y = value
        vek2(float value) {
            this->x = value;
            this->y = value;
        }

        // Konstr. 3 (2 Param): x = x; y = y
        vek2(float x, float y) {
            this->x = x;
            this->y = y;
        }

        // Zugriff mit v[0] / v[1] ermoeglichen
        float& operator [] (size_t i/*0 oder 1*/) {
            // Out of Index?
            assert(i < 2 && i >= 0);
            // *(&x)... Wert aus Adresse von x
            return *((&x/*Adresse x*/)+i/*oder Adresse von x + 1 (= Addresse y)*/);
        }

        // Vektoraddition (+ Operator ueberschreiben)
        vek2 operator + (const vek2& other) const {
            return vek2(this->x + other.x, this->y + other.y);
        }

        // Vektoraddition Kurzschreibweise (+= Opera...)
        vek2& operator += (const vek2& other) {
            this->x += other.x;
            this->y += other.y;
            return *this;
        }

        // Vektordivision
        vek2 operator - (const vek2& other) const {
            return vek2(this->x - other.x, this->y - other.y);
        }

        // Vektordivision kurz
        vek2& operator -= (const vek2& other) {
            this->x -= other.x;
            this->y -= other.y;
            return *this;
        }

        // Negativer Divident/Divisor
        // Bsp.: v1 = -v2
        //            ===
        // v1 soll das Negative von v2 hinzugefuegt werden
        // v2 soll dabei unveraendert bleiben
        vek2 operator - () const {
            return vek2(-this->x, -this->y);
        }

        // Multiplikation mit Zahlenwert (Skalar)
        template<typename T> // verschieden Typen (z.B. float, int, double)
        vek2 operator * (const T& scalar) const {
            return vek2(this->x * scalar, this->y * scalar);
        }

        // Multiplikation mit Zahlenwert Kurzschreibweise
        template<typename T>
        vek2 operator *= (const T& scalar) {
            this->x *= scalar;
            this->y *= scalar;
            return *this;
        }

        // Division mit Zahlenwert
        template<typename T>
        vek2 operator / (const T& scalar) const {
            return vek2(this->x / scalar, this->y / scalar);
        }

        // Division mit Zahlenwert Kurz...
        template<typename T>
        vek2 operator /= (const T& scalar) {
            this->x /= scalar;
            this->y /= scalar;
            return *this;
        }

        // Vektorlaenge ohne Wurzel ziehen (Optimierung)
        // Kann bei Abstandsmessungen sinnvoll sein
        float sqrLength() const {
            // Satz des Pythagoras (x² + y²) ohne Wurzel
            return this->x * this->x + this->y * this->y;
        }

        // Vektorlaenge mit Wurzel
        float length() const {
            return sqrtf(sqrLength()); // Wurzel -> rechenintensiv
        }

        // Vektor normalisieren (Laenge des Vektors ist dann 1)
        // Verdopplung Normalenvektor in einer Sekunde (Gameloop) bedeutet Verdopplung Geschwindigkeit
        // ---
        // Wird durch vek2& direkt zurueck gegeben,
        // dadurch Kette moeglich: pos1.nomalize() * 3
        vek2& normalize() { 
            float l = length();
            if(l == 0/*Division durch 0?*/) {
                return *this;
            }
            *this /= l;
            return *this;
        }

        // Vektor kopieren und die Kopie normalisiert zurueckgeben
        vek2 normalized() {
            return vek2(this->x, this->y).normalize();
        }

        // Skalarprodukt / Punktprodukt
        // a * b = ax * bx + ay + by = |a| * |b| * cos(alpha)
        //                           = Laenge von a * Laenge von b * Winkel zwischen den Vektoren
        // 
        // Beispiel:
        //   2     3
        //   -  *  -  = 6 + 8 = 14
        //   4     2
        //
        // Anwendungen (mit normalisierten Vektoren):
        // -Bestimmung Winkel zwische Vektoren
        // -Stehen 2 Vektoren im 90° Winkel aufeinander gilt a*b=0
        // -Zeigen 2 Vektoren in die selbe Richtung gilt a*b=|a|*|b| = 1
        // -Befindet sich Vektor 1 vor Vektor 2 gilt Punktprodukt > 0
        // -Befindet sich Vektor 1 hinter Vektor 2 gilt Punktprodukt < 0
        //      
        // Notizen:
        // cos(alpha) = 1 ....0° (Einheitskreis)
        // cos(alpha) = 0 ...90° (Einheitskreis)
        // sin(alpha) = 1 ...90° (Einheitskreis)
        // sin(alpha) = 0 ....0° (Einheitskreis)
        float dot(vek2& other) { // Weitere Produktoperationen moeglich! Daher dot anstelle ueberladenen * Operator
            return this->x * other.x + this->y * other.y;
        }
    };
}
