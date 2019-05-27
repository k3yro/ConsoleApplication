#include <cstdint>
#include <iostream>

union {
	uint16_t sixteenBits;
	uint8_t twoBytes[2];
} test_endianness;

/*
Byte-Reihenfolge des Systems rausfinden
Quelle: https://de.wikipedia.org/wiki/Byte-Reihenfolge
*/
int main() 
{
	test_endianness.sixteenBits = 1 << 15; // 0x8000, 32768
	if (test_endianness.twoBytes[0] != 0) {
		std::cout << "Das Programm laeuft auf einer Big-Endian-Maschine." << std::endl;
	}
	else {
		std::cout << "Das Programm laeuft auf einer Little-Endian-Maschine." << std::endl;
	}
} 
