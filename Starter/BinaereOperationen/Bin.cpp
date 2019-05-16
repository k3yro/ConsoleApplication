#include <iostream>

void grundlagen();
void praxisBeispiel01();
void testing01();

std::string trigger();
unsigned char triggerVar = 0b00000001;

enum ObjectFlags
{
	ACTIVE = 0x01,			// 0000 0001
	VISIBLE = 0x02,			// 0000 0010
	ENABLE_COLLISION = 0x04	// 0000 0100
};

int main() 
{

	//grundlagen();
	//praxisBeispiel01();
	//testing01();
	trigger();
	trigger();
	trigger();
	trigger();
}

std::string trigger() 
{
	return((triggerVar ^= 0b00000001) ? "Ein" : "Aus");
}

std::string testing01Helper(unsigned char* myFlags)
{
	std::string farbe = "";
	if (*myFlags & 0b10000000)
	{
		farbe += "rot, ";
	}
	if (*myFlags & 0b01000000)
	{
		farbe += "gruen, ";
	}
	if (*myFlags & 0b00100000)
	{
		farbe += "blau, ";
	}
	if (*myFlags & 0b00010000)
	{
		farbe += "orange, ";
	}
	if (*myFlags & 0b00001000)
	{
		farbe += "weiss, ";
	}
	if (*myFlags & 0b00000100)
	{
		farbe += "schwarz, ";
	}
	if (*myFlags & 0b00000010)
	{
		farbe += "gelb, ";
	}
	if (*myFlags & 0b00000001)
	{
		farbe += "cyan, ";
	}
	return farbe;
}
void testing01() 
{
	//rot, gruen, blau, orange, weiss, schwarz, gelb, cyan
	unsigned char myFlags = 0b10001101; //rot, weiss, schwarz, cyan

	//blau einschalten:
	myFlags |= 0b00100000;

	//Auswahl umgehren:
	myFlags = ~(myFlags);

	//orange ausschalten
	myFlags &= ~0b00010000;

	//orange ausschalten
	myFlags &= ~0b00010000;

	//orange einschalten:
	myFlags ^= 0b00010000;

	//orange ausschalten:
	myFlags ^= 0b00010000;


	std::string farbe = testing01Helper(&myFlags);

	std::cout << farbe << std::endl;
}

void praxisBeispiel01() 
{
	// Normaler Weg mit Bool:
	bool active = false;			// 1 Byte +
	bool visible = false;			// 1 Byte +
	bool enableCollision = false;	// 1 Byte
	//=========================================
	//								 = 3 Byte
	std::cout << "Size 3 Booleans: " << sizeof(active) + sizeof(visible) + sizeof(enableCollision) << " Byte" << std::endl;


	//Bitweise mit Flags:
	unsigned char flags = 0; // 0000 0000
	std::cout << "Size ObjectFlags: " << sizeof(ObjectFlags) << " Byte" << std::endl;	// 4 Byte
	std::cout << "Size flags(u char): " << sizeof(flags) << " Byte" << std::endl;		// 1 Byte


	// Bits auf True setzen:

	// 0000 0000 (flags)
	// 0000 0001 (ACTIVE)
	// =========
	//=0000 0001 -> true
	flags |= ACTIVE;
	
	// 0000 0001 (flags)
	// 0000 0100 (ENABLE_COLLISION)
	// =========
	//=0000 0101 -> 2 Werte true
	flags |= ENABLE_COLLISION;

	// Bits auf False setzen:

	// 0000 0101 (flags)
	// 0000 0100 (ENABLE_COLLISION)
	// =========
	//=0000 0001 -> nur noch ACTIVE true 
	flags ^= ENABLE_COLLISION;

	// 0000 0101
	// 1111 1110
	// =========
	//=0000 0001
	flags &= ~ACTIVE;


	//IF Abfrage:

	// 2 Werte auf True:
	flags |= ACTIVE;
	flags |= ENABLE_COLLISION;

	// flags:
	// 0000 0101

	std::cout << "flags vor IF (5): " << (int)flags << std::endl;
	// 0000 0101 (flags)
	// 0000 0001
	// =========
	// 0000 0001
	if (flags & ACTIVE)
	{
		std::cout << "Active" << std::endl;
	}
	std::cout << "flags nach IF: " << (int)flags << std::endl;

	// 0000 0101 (flags)
	// 0000 0010 (VISIBLE)
	// =========
	// 0000 0000
	if (flags & VISIBLE)
	{
		std::cout << "Active" << std::endl;
	}
	if (!(flags & VISIBLE))
	{
		std::cout << "Inactive" << std::endl;
	}

}

void grundlagen() 
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