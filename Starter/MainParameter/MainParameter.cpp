#include <iostream>

void printHelp(char *name) 
{
	std::cout << "Prints numbers from 1 to [num] \nUsage: " << name << "[num]\n";
}

int main(int argc, char** argv) 
{
	if (argc <= 1)
	{
		printHelp(argv[0]);
	}
	else
	{
		// atoi - konvertiert char * to int
		int end = std::atoi(argv[1]);
		if (end <= 0)
		{
			std::cout << "Please input a number above 0" << std::endl;
		}
		else
		{
			for (size_t i = 0; i <= end; i++)
			{
				std::cout << i << std::endl;
			}
		}
	}
	return 0;
}