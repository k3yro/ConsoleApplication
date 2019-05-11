#include <string.h>

class HeapData {
private:
	char* data;
public:
	//Dreierregel: Constructor, Copy Constructor, Destructor
	HeapData() 
	{
		data = new char[42];
	}

	HeapData(const HeapData& weitere) 
	{
		//shallow copy
		//data = weitere.data

		data = new char[42];
		memcpy(data, weitere.data, sizeof(char)*42);
	}//Bei Zeigern sicherheitshalber immer:
	//HeapData(const HeapData& weitere) = delete;

	~HeapData() 
	{
		delete data;
		data = nullptr;

	}
};

int main() 
{
	HeapData data1 = HeapData();
	HeapData data2 = data1;
}