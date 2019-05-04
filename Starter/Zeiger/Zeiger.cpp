#include <iostream>

using namespace std;

//Definitionen
typedef unsigned int uint;
typedef char* string;

//Uebergabe Zeiger an Funktion
void setVariable1(int* pntVar1);

//Funktion mit 2 Rueckgabewerten:
int euklidischeDivision(uint divident, uint divisor, uint* quotient, uint* rest);

/*
pointer_1 = Zeiger auf Variable
pointer_2 = Zeiger auf Arrayelement
pointer_3 = Zeiger auf Funktion
*/
int main()
{
	//Initialisierung
	cout << "Initialisierung und Wertzuweisung:" << endl;
	int variable_1 = 10;
	int* pointer_1 = &variable_1; //Erstelle Zeiger auf variable_1
	cout << "Speicheraddresse: " << &variable_1/* Analog: pointer_1 */ << endl; 

	//Wertzuweisung
	variable_1 = 42; //Analog: *pointer_1 = 45;
	cout << "Wert: " << variable_1 << endl << endl; 

	//Funktionsuebergabe
	cout << "Nach Funktionsaufruf:" << endl;
	setVariable1(&variable_1); //Analog: pointer_1
	cout << "Speicheraddresse: " << &variable_1 << endl << "Wert: " << variable_1 << endl << endl;

	//Funktionsbeispiel mit 2 Rueckgabewerten
	cout << "Euklidische Division:" << endl;
	uint euklDiv[] = { 20 /*Divident*/, 7/*Divisor*/, 0/*Rückgabewert 1*/, 0/*Rückgabewert 2*/ };
	euklidischeDivision(euklDiv[0], euklDiv[1], &euklDiv[2], &euklDiv[3]);
	cout << "Die Zahl " << euklDiv[1] << " passt " << euklDiv[2] << " mal in die Zahl " << euklDiv[0] << ". Der Rest ist " << euklDiv[3] << "." << endl << endl;

	//Zeiger auf Array
	cout << "Arrayzeiger:" << endl;
	int array_2[] = { 55,100,200,300,400 };	//Array = Zeiger (auf erstes Element)
	int* pointer_2 = nullptr;		//Ungleicher Typ bei Array (Falsch: int[]*)
	pointer_2 = array_2;			//Analog: pointer_2 = &array_2[0];
	cout << "Erstes Element: " << *pointer_2 << endl;
	pointer_2++;
	cout << "Zweites Element: " << *pointer_2 << endl;
	pointer_2 += 3;
	cout << "Letztes Element: " << *pointer_2 << endl << endl;

	//Funktionszeiger (z.B. fuer Events)
	cout << "Funktionszeiger:" << endl;
	void (*pointer_3)(int*) = setVariable1; //Zeiger auf Funktion
	pointer_3(&array_2[1]); //Funktion ausfuehren
	for (size_t i = 0; i < (sizeof(array_2) / sizeof(array_2[0])); i++)
	{
		cout << "Element "<< i << ": " << array_2[i] << endl;
	}

	return 0;
}

void setVariable1(int *pntVar1)
{
	*pntVar1 = 53;
}

int euklidischeDivision(uint divident, uint divisor, uint* quotient, uint* rest) 
{
	if (divisor == 0)
	{
		return -1;
	}

	*quotient = (uint)divident / divisor;
	*rest = divident % divisor;

	return 0;
}