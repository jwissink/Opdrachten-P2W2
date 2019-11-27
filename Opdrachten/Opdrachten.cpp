// Opdrachten.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <string>
#include <map>

int main()
{
	std::list<std::string> names{
		"Piet",
		"Henk",
		"Petra",
		"Pieter"
	};
	std::vector<std::string> heroNames{
		"Superman",
		"Batman",
		"Wonderwoman",
		"Hulk"
	};
	std::list<std::vector<std::string>> vecArray;
	std::vector<std::list<std::string>> listArray;
	names.push_back("Klaas");
	heroNames.push_back("Panther");

	std::list<std::string> combinedList;
	int i = 0;
	for (std::list<std::string>::iterator it = names.begin(); it != names.end(); ++it) {
		combinedList.push_back(*it + " " + heroNames.at(i));
		i++;
	}
	i = 0;
	for (std::string s : combinedList) {
		std::cout << i << " " << s << std::endl;
		i++;
	}
	
	i = 0;
	std::vector<std::string> tokens;
	std::map<std::string, std::string> namesMap;
	for (std::string s : combinedList) {
		std::istringstream ss(s);
		std::copy(std::istream_iterator<std::string>(ss),
			std::istream_iterator<std::string>(), 
			std::back_inserter(tokens));
	}
	for (std::string s : tokens) {
		std::cout << s << std::endl;
	}
	for (int i = 0; i < tokens.size();) {
		namesMap.insert(std::pair<std::string, std::string>(tokens.at(i), tokens.at(i + 1)));
		if (i + 2 < tokens.size()) {
			i += 2;
		}
		else {
			break;
		}
	}
	for (std::pair<std::string, std::string> p : namesMap) {
		std::cout << p.first << " " << p.second << std::endl;
	}
	
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
