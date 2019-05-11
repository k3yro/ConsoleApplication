#include <iostream>
#include <cassert>	//entspricht <assert.h>*
#include <cstdio>	//entspricht <stdio.h>*
#include <string.h> //entspricht <cstring>*
//* In C++ beide Schreibweisen moeglich.

#pragma warning(disable:4996) //use unsecure functions like scanf

int main()
{
	//printf/scanf
	/*
	char input[11];
	scanf("%10s", input);	//Eingabestring soll maximal 10 Zeichen haben.
	printf("Eingabe: %s\n", input);
	*/
	puts("Guten Tag\n");

	//Vergleichen
	assert(strcmp("", "") == 0/*0...!!!*/);

	//Laenge abfragen (Wert zwischenspeichern -> Performanz)
	assert(strlen("bla") == 3);//Aber: Das Array hat die Laenge 4 (\0 -> Stringende)

	//Herausfinden an wievielter Stelle ein Buchstabe auftaucht im String
	assert(strcspn("bla", "l") == 1);

	//String Aufteilung per definierten Zeichen (PHP -> explode)
	char str[] = "Ein,paar.Woerter,getrennt,durch.Punkt,und,Komma!";
	char* wort = strtok(str, ",.");
	while (wort != nullptr)
	{
		printf("%s ", wort);
		wort = strtok(nullptr, ",.");
	}
	putchar('\n');

	//Dateien lesen und schreiben <cstdio>
	FILE* file;
	file = fopen("Document.txt", "r");
	if (file == nullptr)
	{
		perror("Fehler beim Oeffnen der Datei Document.txt");
		return 1;
	}

	char buffer[100];

	if (fgets(buffer, 100, file) != nullptr) //Beenden, wenn mehr als 100 Zeichen eingelesen wurden
	{
		printf(buffer);
	}
	fclose(file);

	//Datei schreiben
	file = fopen("Secret.txt", "a");
	if (file == nullptr)
	{
		perror("Fehler beim Erzeugen der Datei Secret.txt");
		return 1;
	}

	if (fprintf(file, "Streng geheime Nachricht.\n") < 0)
	{
		perror("Fehler beim Schreiben in die Datei Secret.txt");
	}
	fclose(file);
}