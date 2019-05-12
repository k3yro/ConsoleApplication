#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	std::pair<std::string, int> name1;
	name1.first = "John";
	name1.second = 36;
	std::cout << name1.first << ", " << name1.second << std::endl;

	std::unordered_map<std::string, int> hashMap;
	hashMap.insert(std::pair<std::string, int>("Sue", 43));
	hashMap["Sue"]++;
	std::cout << hashMap["Sue"] << std::endl;

	unordered_map<string, string> adresse;
	adresse.insert(pair<string, string>("Strasse", "Am Holzweg 17"));
	cout << adresse["Strasse"] << endl;
	cout << "Key Strasse vorhanden: " << adresse.count("Strasse") << endl;
	cout << "Key strasse vorhanden: " << adresse.count("strasse") << endl;


	std::unordered_map<int, char> m = {
		{1, 'A'},
		{2, 'B'},
		{3, 'C'}
	};

	for (auto const pair : m) {
		std::cout << "{" << pair.first << ": " << pair.second << "}\n";
	}
	std::cout << std::endl;
	std::for_each(m.begin(), m.end(), [](const std::pair<int, char> & p) 
		{
			std::cout << "{" << p.first << ": " << p.second << "}\n";
		});
}