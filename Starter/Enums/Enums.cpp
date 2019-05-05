#include <iostream>

enum Wochentag
{
	Sonntag = 7, Montag = 1, Dienstag, Mittwoch, Donnerstag, Freitag, Samstag, Sonnabend = 6
};

std::string getInfoWochentag(Wochentag tag) 
{
	std::string output = "";
	switch (tag)
	{
	case Sonntag:
		output = "Sonne (engl.: Sunday)";
		break;
	case Montag:
		output = "Mond (engl.: Monday)";
		break;
	case Dienstag:
		output = "Tyr (engl.: Tuesday)";
		break;
	case Mittwoch:
		output = "Wodan (engl.: Wednesday)";
		break;
	case Donnerstag:
		output = "Thor (engl.: Thursday)";
		break;
	case Freitag:
		output = "Frija (engl.: Friday)";
		break;
	case Samstag:
		output = "Saturn (engl.: Saturday)";
		break;
	default:
		break;
	}
	return output;
}

int main()
{
	std::cout << getInfoWochentag(Sonnabend) << std::endl;

	return 0;
}