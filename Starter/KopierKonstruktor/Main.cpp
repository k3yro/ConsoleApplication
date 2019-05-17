#include <string.h>
#include <chrono>

//Dreierregel: Constructor, Copy Constructor, Destructor
//Rule of five: Destructor, Copy Constructor, CopyAssigment, Move, MoveAssigment
class HeapData {
private:
	char* data;
public:
	
	//Konstruktor
	HeapData() 
	{
		data = new char[42];
	}

	//Kopierkonstruktor
	HeapData(const HeapData& weitere) 
	{
		//shallow copy
		//data = weitere.data

		data = new char[42];
		memcpy(data, weitere.data, sizeof(char)*42);
	}//Bei Zeigern sicherheitshalber immer:
	//HeapData(const HeapData& weitere) = delete;

	//Zuweisungsoperator (CopyAssignment)
	HeapData& operator = (const HeapData& other)
	{
		char* tmp = new char[42];
		memcpy(tmp, other.data, sizeof(char) * 42);
		delete[] data;
		data = tmp;
		return *this;
	}

	//MoveKonstruktor
	HeapData(HeapData&& other)
	{
		//Zwei Zeiger umbiegen:
		data = other.data;
		other.data = nullptr;
	}

	//MoveAssignment
	HeapData& operator=(HeapData&& other)
	{
		//Pruefen ob other und this das gleiche Obj sind:
		if (this != &other)
		{
			delete[] data;
			data = other.data;
			other.data = nullptr;
		}
		return *this;
	}

	//Bei neuer Klasse immer löschen (sicherheitshalber):
	/*
	HeapData(const HeapData&) = delete;
	HeapData(HeapData&&) = delete;
	HeapData& operator = (const HeapData&) = delete;
	HeapData& operator = (HeapData&&) = delete;
	*/

	//Dekonstruktor
	virtual/*fuer eventuelle Vererbung*/ ~HeapData() 
	{
		delete[] data;
		data = nullptr;

	}
};

int main() 
{
	HeapData data1 = HeapData();
	HeapData data2 = data1; //Benoetigt Kopierkonstruktor

	//Kopierkonstruktor wird nur aufgerufen, wenn anderes Objekt noch nicht existiert! (siehe oben data2)
	data1 = data2; //Benoetigt Zuweisungsoperator (CopyAssigment)

	HeapData data3 = std::move(data1); //Benoetigt Verschiebungs Konstruktor (Move)
	data3 = std::move(data2); //Benoetigt MoveAssigment


}