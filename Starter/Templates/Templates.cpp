#include <iostream>

//Auslagerung nur in .h Dateien
template<class T> //"class" oder "typename"
T GetMax(T x, T y)
{
	return x > y ? x : y;
}

template<typename X, class O>
X Cast(O o)
{
	return (X)o;
}

int main()
{
	int iMax = GetMax<int>(1, 2);
	float fMax = GetMax<float>(2.4f, 1.3f);

	int iValue = Cast<int, float>(fMax);
	std::cout << iValue << std::endl;


}