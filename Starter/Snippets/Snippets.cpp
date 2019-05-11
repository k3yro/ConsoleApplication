#include <iostream>
#include <stdio.h> /*Zufallszahlen*/
#include <time.h> /*Zufallszahlen*/

#ifdef _DEBUG
	#define DEBUG
#else
	#define RELEASE
#endif // DEBUG


using namespace std;

void Strings();
void Arrays();
void Zufallszahlen();

int main()
{
#ifdef DEBUG
	std::cout << "Programm started in debug mode @ Line: " << __LINE__ << std::endl << std::endl;
#endif

	//Strings();
	//Zufallszahlen();

	Arrays();
	return 0;
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