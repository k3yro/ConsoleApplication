#include <cstdint>
#include <iostream>

// 2 Werte, eine Speicherbereich
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
	// Setze erstes Bit auf 1 und verschiebe es um 15 Stellen
	// Ergebnis: 1000 0000 0000 0000 (Binaer)
	test_endianness.sixteenBits = 1 << 15; // 0x8000, 32768

	if (test_endianness.twoBytes[0] != 0) {
		// Big-Endian:
		// twoBytes[0] -> 1000 0000 (0x80, 128)
		// twoBytes[1] -> 0000 0000
		std::cout << "Das Programm laeuft auf einer Big-Endian-Maschine." << std::endl;
	}
	else {
		// Little-Endian:
		// twoBytes[0] -> 0000 0000
		// twoBytes[1] -> 1000 0000 (0x80, 128)
		std::cout << "Das Programm laeuft auf einer Little-Endian-Maschine." << std::endl;
	}
} 
