#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#if STD_CONTAINER
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	//#include <map.hpp>
	//#include <stack.hpp>
	#include "../vector.hpp"
#endif


void printMap(std::string_view comment, const std::map<std::string, int>& m, std::ofstream& tests)
{
	std::cout << comment ;
	for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++) {
		tests << it->first << " = " << it->second << "; ";
	}
    tests << '\n';
}

void printMapterminal(std::string_view comment, const std::map<std::string, int>& m)
{
	std::cout << comment ;
	for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << " = " << it->second << "; ";
	}
    std::cout << '\n';
}


void mapTests(std::ofstream& tests){

	tests << "--- MAP GENERAL TESTS --" << std::endl;

    // Create a map of three (strings, int) pairs
    std::map<std::string, int> m;
	 m["CPU"] = 10;
	 m["GPU"] = 15;
	 m["RAM"] = 20;
 
    printMapterminal("1) Initial map: ", m);
 
    m["CPU"] = 25;  // update an existing value
    m["SSD"] = 30;  // insert a new value
    printMapterminal("2) Updated map: ", m);
 
    // using operator[] with non-existent key always performs an insert
    std::cout << "3) m[UPS] = " << m["UPS"] << '\n';
    printMapterminal("4) Updated map: ", m);
 
    m.erase("GPU");
    printMapterminal("5) After erase: ", m);
 
    std::erase_if(m, [](const auto& pair){ return pair.second > 25; });
    printMapterminal("6) After erase: ", m);
    std::cout << "7) m.size() = " << m.size() << '\n';
 
    m.clear();
    std::cout << std::boolalpha << "8) Map is empty: " << m.empty() << '\n';
}

