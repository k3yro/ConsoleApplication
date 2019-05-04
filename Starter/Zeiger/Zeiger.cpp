#include <iostream>

#pragma execution_character_set( "utf-8" )

using namespace std;

//Definitionen
typedef unsigned int uint;

//Uebergabe Zeiger an Funktion
void setVariable1(int* pntVar1);

//Funktion mit 2 Rueckgabewerten:
void euklidischeDivision(uint divident, uint divisor, uint* quotient, uint* rest);

int main()
{
	//Initialisierung
	int variable_1 = 10;
	int* pointer_1 = &variable_1;
	cout << "Speicheraddresse: " << &variable_1 << endl; //Analog: pointer_1 

	//Wertzuweisung
	variable_1 = 42;
	cout << "Wert: " << variable_1 << endl << endl; //Analog: *pointer_1 

	//Funktionsuebergabe
	cout << "Nach Funktionsaufruf:" << endl;
	setVariable1(&variable_1); //Analog: pointer_1
	cout << "Speicheraddresse: " << &variable_1 << endl << "Wert: " << variable_1 << endl << endl;

	//Funktionsbeispiel mit 2 Rueckgabewerten
	uint euklDiv[] = { 20 /*Divident*/, 7/*Divisor*/, 0/*Rückgabewert 1*/, 0/*Rückgabewert 2*/ };
	euklidischeDivision(euklDiv[0], euklDiv[1], &euklDiv[2], &euklDiv[3]);
	cout << "Die Zahl " << euklDiv[1] << " passt " << euklDiv[2] << " mal in die Zahl " << euklDiv[0] << ". Der Rest ist " << euklDiv[3] << "." << endl;

	return 0;
}

void setVariable1(int *pntVar1)
{
	*pntVar1 = 53;
}

void euklidischeDivision(uint divident, uint divisor, uint* quotient, uint* rest) 
{
	*quotient = (uint)divident / divisor;
	*rest = divident % divisor;
}