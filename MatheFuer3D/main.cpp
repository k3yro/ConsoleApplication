#include <iostream>

#include "k3math/k3math.hpp"

void print(k3math::vek2 v)
{
    std::cout << "(" << v.x << "," << v.y << ")" << std::endl;
}

void print(k3math::vek3 v)
{
    std::cout << "(" << v.x << "," << v.y << "," << v.z << ")" << std::endl;
}

void print(k3math::vek4 v)
{
    std::cout << "(" << v.x << "," << v.y << "," << v.z << "," << v.w << ")" << std::endl;
}

int main(int argc, char** argv)
{
    // 2D
    {
        // Initial
        k3math::vek2 pos1 (1.3f, 2.2f);
        k3math::vek2 pos2 (3.5f, 1.6f);
        k3math::vek2 pos3 = {};

        // Addition
        pos3 = pos1 + pos2;
        std::cout << "2D Addition:" << std::endl;
        print(pos3);

        // Subtraktion
        pos3 = pos2 - pos1;
        std::cout << "2D Subtraktion:" << std::endl;
        print(pos3);

        // Multiplikation mit Skalar
        pos3 = pos2 * 2;
        std::cout << "2D Multiplikation mit Skalar:" << std::endl;
        print(pos3);

        // Division mit Skalar
        pos3 = pos2 / 2;
        std::cout << "2D Division mit Skalar:" << std::endl;
        print(pos3);

        // Normalisierung
        std::cout << "2D Normalisierung:" << std::endl;
        std::cout << pos3.length() << std::endl;
        pos3 = pos2.normalize();
        print(pos3);
        std::cout << pos3.sqrLength() << std::endl; // Anwendung optimierte Laenge

        // Punktprodukt / Skalarprodukt
        std::cout << "2D Punktprodukt:" << std::endl;
        float result = pos1.dot(pos2);
        result /= pos1.length();
        result /= pos2.length();
        std::cout << result << std::endl; // cos(alpha)
        // Result = Winkel des Vektors
        // Umrechnung Grad -> siehe https://www.wolframalpha.com/input/?i=acos(0.820615)

    }

    
}
