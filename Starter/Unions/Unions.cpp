#include <iostream>

struct Value/*Standard: Alles public*/
{
	Value(int i) 
	{
		type = INT;
		this->value.i = i;
	}
	Value(float f)
	{
		type = FLOAT;
		this->value.f = f;
	}

	enum Type {FLOAT, INT};
	union UnionValue
	{
		int i;
		float f;
	};

	Type type;
	UnionValue value;
};

union AllesVomGleichenTyp
{
	signed char c;
	unsigned char uc;

	signed short s;
	unsigned short us;

	signed int i;
	unsigned int ui;

	signed long long ll;
	unsigned long long ull;

	float f;
	double d;
};

int main() 
{
	/*std::cout << sizeof(AllesVomGleichenTyp) << std::endl;

	AllesVomGleichenTyp nr = AllesVomGleichenTyp();
	nr.c = 48;
	std::cout << nr.i << std::endl;*/

	Value value = Value(10.0f);

	switch (value.type)
	{
	case (Value::INT):
		std::cout << "Wert entspricht int." << std::endl;
		break;
	case (Value::FLOAT):
		std::cout << "Wert entspricht float." << std::endl;
		break;
	}
}