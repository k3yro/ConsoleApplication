#include <cstdint>
#include <iostream>

union
{
	uint32_t Bits32;
	uint8_t Bytes4[4];
} ganzahl32Bit;

/*
Byte-Reihenfolge des Systems rausfinden
Beispiel siehe: https://de.wikipedia.org/wiki/Byte-Reihenfolge#Beispiel:_Speicherung_einer_32_Bit-Ganzzahl_in_4_Bytes
*/
int main() 
{
	ganzahl32Bit.Bits32 = 16909060; //  (0x01020304, 0b0001000000100000001100000100) 

	if (ganzahl32Bit.Bytes4[0] == 1 && ganzahl32Bit.Bytes4[1] == 2 && ganzahl32Bit.Bytes4[2] == 3 && ganzahl32Bit.Bytes4[3] == 4) 
	{
		std::cout << "Das Programm laeuft auf einer Big-Endian-Maschine." << std::endl;
	}
	else if(ganzahl32Bit.Bytes4[0] == 4 && ganzahl32Bit.Bytes4[1] == 3 && ganzahl32Bit.Bytes4[2] == 2 && ganzahl32Bit.Bytes4[3] == 1)
	{
		std::cout << "Das Programm laeuft auf einer Little-Endian-Maschine." << std::endl;
	}
	else if (ganzahl32Bit.Bytes4[0] == 2 && ganzahl32Bit.Bytes4[1] == 1 && ganzahl32Bit.Bytes4[2] == 4 && ganzahl32Bit.Bytes4[3] == 3)
	{
		std::cout << "Das Programm laeuft auf einer Mixed-Endian-Maschine." << std::endl;
	}
} 
