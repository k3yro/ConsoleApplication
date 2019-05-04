#include <iostream>
#include <stdio.h> /*Zufallszahlen*/
#include <time.h> /*Zufallszahlen*/

#pragma execution_character_set( "utf-8" )

using namespace std;

void Zufallszahlen();

int main()
{
	Zufallszahlen();
	return 0;
}

void Zufallszahlen()
{
	//Linearer Kongruenzgenerator
	cout << "Maximale Groesse: " << RAND_MAX << endl;
	srand(time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		cout << rand() % 27 << endl;
	}
}