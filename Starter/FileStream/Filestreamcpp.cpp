#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//Schreiben
	std::ofstream out;
	out.open("test.txt", std::ofstream::app);
	out << "Hello File" << std::endl;
	out.close();

	//Lesen
	std::ifstream in("Filestreamcpp.cpp");
	if (in.is_open())
	{
		std::string line;
		while (std::getline(in, line))
		{
			std::cout << line << std::endl;
		}
		in.close();
	}
	else
	{
		std::cout << "Datei existiert nicht." << std::endl;
	}

	return 0;
}