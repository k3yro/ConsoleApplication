#include <iostream>
#include <list>

int main() 
{
	std::list<int> list;
	list.assign(4, 42); //Fuege 4 mal 42 ein
	list.push_front(6); //Fuege 6 am Anfang ein
	list.push_back(10); //Fuege 10 am Ende ein

	for (auto i = list.crbegin(); i != list.crend(); i++) //Liste rueckwaerts ausgeben
	{
		std::cout << *i << std::endl;
		//list.insert
		//if (*i == 42)
		//{
		//	list.erase(i);
		//	break;
		//}
	}

	//Doppelte Eintraege entfernen:
	list.unique();

	//Liste sortieren:
	list.sort();

	//Element entfernen
	list.remove(10);

}