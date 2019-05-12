#include <iostream>
#include <stdio.h> /*Zufallszahlen*/
#include <time.h> /*Zufallszahlen*/
#include <array>

#ifdef _DEBUG
	#define DEBUG
#else
	#define RELEASE
#endif // DEBUG


using namespace std;

struct GroessenTest1
{
	int i1;
	short s1;
	int i2;
	short s2;
};

struct GroessenTest2
{
	int i1;
	int i2;
	short s1;
	short s2;
};

struct GroessenTest3
{
	short s1;
	short s2;
	int i1;
	int i2;	
};

void Strings();
void Arrays();
void Zufallszahlen();
int* GanzBoeseFunktion();

int main()
{
#ifdef DEBUG
	std::cout << "Programm started in debug mode @ Line: " << __LINE__ << std::endl << std::endl;
#endif

	//Strings();

	//Arrays();

	//Zufallszahlen();

	//Zeiger Fail:
	int* nichtNachMachen = GanzBoeseFunktion();
	std::cout << "nichtNachMachen: " << *nichtNachMachen << std::endl; //Wert koennte ueberschrieben werden
	std::cout << "nichtNachMachen: " << *nichtNachMachen << std::endl; //Wert koennte ueberschrieben werden

	//Speicheroptimierung (Alignment)
	std::cout << "sizeof short: " << sizeof(short) << std::endl;
	std::cout << "sizeof int: " << sizeof(int) << std::endl;
	std::cout << "sizeof GroessenTest1: " << sizeof(GroessenTest1) << std::endl;
	std::cout << "sizeof GroessenTest2: " << sizeof(GroessenTest2) << std::endl;
	std::cout << "sizeof GroessenTest3: " << sizeof(GroessenTest3) << std::endl;
	std::cout << "alignment of short: " << std::alignment_of<short>() << std::endl;
	//...

	//Standard Array
	std::array<int, 10> elements;

	for (size_t i = 0; i < elements.size(); i++)
	{
		elements[i] = i+1;
	}
	for (size_t i = 0; i < elements.size(); i++)
	{
		std::cout << elements[i] << std::endl;
	}

	return 0;
}

int* GanzBoeseFunktion() 
{
	int zahl = 27;
	return &zahl;
}

void Strings()
{
	//const char*
	const char* string_01 = "const char*\n==========";
	cout << string_01 << endl;

	//Erstes Zeichen ausgeben
	cout << "Erstes Zeichen: " << *string_01 << endl;

	//Letztes Zeichen ausgeben 
	string_01 += strlen(string_01) - 1;
	cout << "Letztes Zeichen: " << *string_01 << endl;

	//Endezeichen
	string_01++;
	if (*string_01 == '\0')
	{
		cout << "Endezeichen gefunden!" << endl;
	}

	//std::string:
	string string_02 = "std::string\n===========";
	cout << endl << string_02 << endl;

	//Erstes Zeichen ausgeben
	cout << "Erstes Zeichen: " << string_02.at(0) << endl;

	//Letztes Zeichen ausgeben
	cout << "Letztes Zeichen: " << string_02.at(string_02.length() -1) << endl;
	cout << endl;
	system(string_02.c_str());
}

void Arrays() 
{
	int* array = new int[100];
	delete[] array;
}

void Zufallszahlen()
{
	//Linearer Kongruenzgenerator:
	cout << "Maximale Groesse: " << RAND_MAX << endl;
	srand(time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		cout << rand() % 27 << endl;
	}
}