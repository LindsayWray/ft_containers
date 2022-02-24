#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#if STD_CONTAINER
	#include <map>
	#include <stack>
	#include <vector>
	#include <iostream>
	namespace ft = std;
#else
	#include "../map.hpp"
	//#include <stack.hpp>
	//#include "../vector.hpp"
#endif


// void printMap(std::string_view comment, const std::map<std::string, int>& m, std::ofstream& tests)
// {
// 	std::cout << comment ;
// 	for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++) {
// 		tests << it->first << " = " << it->second << "; ";
// 	}
// 	tests << '\n';
// }

// void printMapterminal(std::string_view comment, const std::map<std::string, int>& m)
// {
// 	std::cout << comment ;
// 	for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++) {
// 		std::cout << it->first << " = " << it->second << "; ";
// 	}
// 	std::cout << '\n';
// }


void mapTests(std::ofstream& tests){

	tests << "--- MAP GENERAL TESTS --" << std::endl;

	ft::map<std::string, int> testMap;
	(void) testMap;

	// Create a map of three (strings, int) pairs
	testMap["A"] = 10;
	testMap["B"] = 15;
	testMap["C"] = 20;
	std::cout << "Value B is: " << testMap["B"] << std::endl;
	// printMapterminal("1) Initial map: ", testMap);

	// testMap["A"] = 25;  // update an existing value
	// testMap["D"] = 30;  // insert a new value
	// printMapterminal("2) Updated map: ", testMap);

	// // using operator[] with non-existent key always performs an insert
	// std::cout << "3) m[X] = " << testMap["X"] << '\n';
	// printMapterminal("4) Updated map: ", testMap);

	// testMap.erase("B");
	// printMapterminal("5) After erase: ", testMap);

	// testMap.clear();
	// std::cout << std::boolalpha << "8) Map is empty: " << testMap.empty() << '\n';
}

