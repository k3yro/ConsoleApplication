#include <iostream>
#include <assert.h>

void assertFunktion(int zahl) 
{
	assert(zahl > 0);
	assert(zahl < 10);
	std::cout << "Zahl ist zwischen 0 und 10: " << zahl << std::endl;
}

//Eigene Fehlerklasse:
class eigeneException : public std::exception
{
	const char* nachricht;
public:
	eigeneException(const char* nachricht) : nachricht(nachricht) {}
	virtual /*siehe Vererbung*/ const char* what() const/*nicht schreibender zugriff (siehe what() definition)*/ throw()/*keine Exception werfen*/ override/*throw() ueberschreiben*/
	{
		return nachricht;
	}
};

//Exception weiterreichen
void gibExceptionWeiter1() throw(int, char*, eigeneException) //Viele Parameter
{
	//throw 42; //int
	//throw "Eigene Fehlerbeschreibung in Funktion 1"; //char*
	throw eigeneException("Eigene Exception"); //eigene
}

void gibExceptionWeiter2() throw(std::ios_base::failure) //1 Parameter
{
	throw std::ios_base::failure("Eigene Fehlerbeschreibung in Funktion 2");
}

int main()
{
	//Assert:
	assertFunktion(9);

	//Input fail:
	int input;
	std::cout << "Zahl eingeben: ";
	std::cin >> input;
	if (std::cin.fail())
	{
		std::cout << "Falsche Benutzereingabe." << std::endl;
		/*cin zuruecksetzen, damit naechste eingabe 
		stattfinden kann (z.b. in while schleife):*/
		std::cin.clear();
		std::cin.ignore();
	}

	//cin exceptions anschalten:
	std::cin.exceptions(std::ios_base::failbit);	
	try
	{
		std::cout << std::endl << "Zahl eingeben2: ";
		std::cin >> input;
	}
	catch (const std::ios_base::failure& e)
	{
		std::cout << "Falsche Benutzereingabe2. (ios_base fehler)" << std::endl << "e.what(): " << e.what() << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	catch (const std::exception& e)
	{
		std::cout << "Falsche Benutzereingabe2. (standard fehler)" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	catch (int e)
	{
		std::cout << "Falsche Benutzereingabe2. (int fehler)" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	catch (char* e)
	{
		std::cout << "Falsche Benutzereingabe2. (char* fehler)" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	catch (...)
	{
		std::cout << "Falsche Benutzereingabe2. (irgendein fehler)" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	
	//Exception weiterreichen:
	try
	{
		gibExceptionWeiter1();
		//gibExceptionWeiter2();
	}
	catch (const int e)
	{
		std::cout << "e: " << e << std::endl;
	}
	catch (const char* e)
	{
		std::cout << "e: " << e << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "e.what(): " << e.what() << std::endl;
	}

	std::cout << "Ende..." << std::endl;
	return 0;
}