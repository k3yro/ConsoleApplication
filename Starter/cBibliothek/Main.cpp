#include <iostream>
#include <cassert>	//entspricht <assert.h>*
#include <cstdio>	//entspricht <stdio.h>*
#include <string.h>	//entspricht <cstring>*
#include <cstdlib>	//...
//* In C++ beide Schreibweisen moeglich.

#pragma warning(disable:4996) //unsichere Funktionen erlauben

//doppelte Freigabe des dynamischen Speicherbereichs vermeiden:
//free() ueberschreiben, um nullptr exception auszuloesen:
#define free(X)		\
{					\
	assert(X);		\
	std::free(X);	\
}

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
	file = fopen("Document.txt", "rb"); //b ... Binaermodus (besser immer verwenden)
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

	if (fprintf(file, ""/*"Streng geheime Nachricht.\n"*/) < 0)
	{
		perror("Fehler beim Schreiben in die Datei Secret.txt");
	}
	fclose(file);

	//Array erstellen in C (<cstdlib>)
	void* memory = malloc(10); //10 Bytes reservieren | C++: int* array = new int[100]
	if (nullptr == memory)
	{
		perror("Could not allocate memory\n");
		return 1;
	}

	// Malloc
	int* intArray = (int*/*int statt void pointer (Info fuer Compiler: 4 Byte gross)*/)malloc(sizeof(int) * 10); //Reserviere Platz für 10 int
	
	// Calloc
	int* intArrayCleared = (int*)calloc(10/*Anzahl Eintraege*/, sizeof(int)/*Groesse eines Eintrags*/); //Calloc -> mit 0 gefüllt

	// Speicher erweitern:
	intArray = (int*)realloc(intArray, sizeof(int) * 27);
	if (intArray == nullptr)
	{
		//Kein Speicher verfuegbar
		perror("Could not reallocate memory\n");
		return 1;
	}

	free(memory);			//malloc -> free() | C++: new -> delete
	free(intArray);
	free(intArrayCleared);
	//free(nullptr);

	//###############################################
	//#  Weitere Befehle mit dyn. Speicher:			#
	//#  memcpy - Speicherbereiche kopieren			#
	//#  memset - Speicherbereich auf Null setzen	#
	//#  ... calloc ist ein melloc + memset			#
	//###############################################

	//Unendlich grosse Datei auslesen:
	FILE* bigFile;
	bigFile = fopen("document.txt","rb");
	if (nullptr == bigFile)
	{
		perror("Fehler beim Lesen von bigFile");
	}
	//Groesse der Datei rausfinden
	fseek(bigFile, 0, SEEK_END);		//Gehe an das Dateiende
	long fileLength = ftell(bigFile);	//Hole Dateigroesse
	rewind(bigFile);					//Gehe zum Dateianfang

	char* bigBuffer = (char*)malloc(sizeof(char) * (fileLength + 1/*Endezeichen*/));
	if (nullptr == bigBuffer)
	{
		fclose(bigFile);
		perror("Fehler beim Oeffnen einer unendlich grossen Datei.\n");
		return 1;
	}

	size_t bytesRead = /*gibt Groesse zurueck*/fread(bigBuffer, sizeof(char), fileLength, bigFile);
	bigBuffer[bytesRead] = '\0'; //Falls das Ende-Zeichen vor dem Ende der Datei war, soll bigBuffer hier auch vorzeitig enden.
	printf("\n\nUndendliche Datei:\n%s\n", bigBuffer);

	fclose(bigFile);
	free(bigBuffer);
}