#include <iostream>

class Vektor
{
public:
	double x, y, z;
	Vektor(double x, double y, double z):x(x),y(y),z(z) {}
	
	Vektor operator +(Vektor r) 
	{
		Vektor op(r.x + x, r.y + y, r.z + z);
		return op;
	}
};

int main() 
{
	Vektor v1(1.0, 2.0, 3.0);
	Vektor v2(1.0, 2.0, 3.0);
	Vektor v3 = v1 + v2;

	std::cout << v3.x << " " << v3.y << " " << v3.z << std::endl;
}