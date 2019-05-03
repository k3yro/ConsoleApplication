#include <iostream>
#include <cstdio>
#include <windows.h>

#pragma execution_character_set( "utf-8" )

using namespace std;

char input = 'q';	//Benutzereingabe (Hauptmenu)

#pragma region Funktionen
void menu();		//Hauptmenu
void handle();		//Controller
void rechne();		//Beispielfunktion
#pragma endregion

int main()
{
	SetConsoleOutputCP(65001); /*Sonderzeichen Terminal*/

	do
	{	
		menu();		//Hauptmenu ausgeben
		handle();	//Controller

	} while (input != 'q');

	return 0;
}

#pragma region Hauptmenu
void menu()
{
	system("cls");
	cout << "Rechner - Hauptmenü" << endl;
	cout << "===================" << endl << endl;
	cout << "Wähle eine Funktion:\n(1): Addieren\n(2): Subtrahieren\n(3): Multiplizieren\n(4): Dividieren\n(q): Beenden" << endl;

	cout << endl << "Eingabe: ";
	cin >> input;
}
#pragma endregion

#pragma region Benutzereingabe
void handle() 
{
	//Behandle Benutzereingabe
	switch (input)
	{
	case '1':
		system("cls");
		cout << "Modus - Addieren" << endl;
		cout << "================" << endl;
		rechne();
		break;
	case '2':
		system("cls");
		cout << "Modus - Subtrahieren" << endl;
		cout << "====================" << endl;
		rechne();
		break;
	case '3':
		system("cls");
		cout << "Modus - Multiplizieren" << endl;
		cout << "======================" << endl;
		rechne();
		break;
	case '4':
		system("cls");
		cout << "Modus - Dividieren" << endl;
		cout << "==================" << endl;
		rechne();
		break;
	}
}
#pragma endregion

#pragma region Beispiel
void rechne()
{
	char* modus;
	double zahl1 = 0;
	double zahl2 = 0;
	double ergebnis = 0;

	cout << endl << "Zahl1: ";
	cin >> zahl1;

	cout << endl << "Zahl2: ";
	cin >> zahl2;

	ergebnis = ((input == '1') ? zahl1 + zahl2 : 0);
	ergebnis = ((input == '2') ? zahl1 - zahl2 : ergebnis);
	ergebnis = ((input == '3') ? zahl1 * zahl2 : ergebnis);
	ergebnis = ((input == '4') ? zahl1 / zahl2 : ergebnis);

	cout << endl << "Ergebnis: " << ergebnis << endl << endl;
	system("pause");
}
#pragma endregion