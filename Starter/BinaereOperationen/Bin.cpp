#include <iostream>

int main() 
{
	// 00000000 (8bit)
	unsigned char x = 0; // = 0b00000000(bin) = 0x00(hex)
	std::cout << (int)x << std::endl;

	//Negation:
	x = ~x; // = 0b11111111
	std::cout << (int)x << std::endl;

	//Und-Verknuepfung:
	x = x & 0b10000001; //Ergebnis: 0b10000001
	std::cout << (int)x << std::endl;

	//& Verknuepfung Kurzschreibweise:
	x &= 0x00;
	std::cout << (int)x << std::endl;

	//Verodern:
	x |= 0x41; //0b01000001
	std::cout << (int)x << std::endl;

	//XOR - Exclusiv Oder
	x ^= 0b11000000;
	//   0b01000001 
	//=============
	//x==0b10000001; (Ergebnis)
	std::cout << (int)x << std::endl;

	//Bitweise verschieben:
	x = x >> 1; //Ergebnis: 0b01000000
	std::cout << (int)x << std::endl;
	x = x << 1; //Ergebnis: 0b10000000
	std::cout << (int)x << std::endl;


	//Aus ungerader Zahl eine gerade machen:
	x = 35;
	std::cout << "Ungerade: " << (int)x << std::endl;
	x = x >> 1;
	x = x << 1;
	std::cout << "Gerade: " << (int)x << std::endl;

	//Mit Vorzeichen wird 1 abgezogen
	signed char y = -35;
	y = y >> 1;
	y = y << 1;
	std::cout << (int)y << std::endl;

}