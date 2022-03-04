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

	(void)tests;

	std::cout << "\n--- MAP GENERAL TESTS --" << std::endl;

	ft::map<std::string, int> testMap;
	(void) testMap;

	std::cout << std::boolalpha << "Is map empty: " << testMap.empty() << std::endl;

	// Create a map of (strings, int) pairs
	// using operator[] with non-existent key always performs an insert
	testMap["K"] = 100;
	testMap["A"] = 10;
	testMap["P"] = 22;
	// testMap["R"] = 12;
	// testMap["V"] = 31;
	// testMap["C"] = 20;
	// testMap["N"] = 28;
	// testMap["I"] = 1;
	// testMap["D"] = 3;
	// testMap["B"] = 15;
	// testMap["T"] = 14;
	// testMap["E"] = 12;
	// testMap["G"] = 14;
	// testMap["Q"] = 21;
	// testMap["Z"] = 45;
	// testMap["L"] = 45;
	// testMap["H"] = 31;
	// testMap["J"] = 7;
	// testMap["M"] = 14;
	// testMap["O"] = 45;
	// testMap["F"] = 30;
	// testMap["S"] = 30;
	// testMap["U"] = 21;
	// testMap["W"] = 7;



	std::cout << "Value O is: " << testMap["O"] << std::endl;
	std::cout << "The map size is: " << testMap.size() << std::endl;
	std::cout << "The max size is: " << testMap.max_size() << std::endl;
	std::cout << "Value A before: " << testMap["A"] << std::endl;
	testMap["A"] = 25;  // update an existing value
	std::cout << "Value A after: " << testMap["A"] << std::endl;

		// first insert function version (single parameter):
	testMap.insert(ft::pair<std::string,int>("X", 100));
	testMap.insert(ft::pair<std::string,int>("Y", 200));
	std::cout << "Value X is: " << testMap["X"] << std::endl; // insert a new value
	std::cout << "Value Y is: " << testMap["Y"] << std::endl;

	//testMap.erase("M");

	// PAIR CONSTRUCTOR TESTS
	ft::pair <std::string,double> product1;                     // default constructor
	ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
	ft::pair <std::string,double> product3 (product2);          // copy constructor

	product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

	product2.first = "shoes";                  // the type of first is string
	product2.second = 39.90;                   // the type of second is double

	std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
	std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
	std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';

	// PAIR RELATIONAL COMPARE
	std::cout << std::boolalpha << "is equal		" << (product1 == product2) << std::endl;
	ft::pair <std::string,double> product4 (product2);
	std::cout << std::boolalpha << "is equal		" << (product4 == product2) << std::endl;
	std::cout << std::boolalpha << "not equal		" << (product3 != product2) << std::endl;
	std::cout << std::boolalpha << "is smaller		" << (product2 < product1) << std::endl;
	std::cout << std::boolalpha << "is smaller or equal	" << (product4 <= product2) << std::endl;
	std::cout << std::boolalpha << "is bigger		" << (product1 > product1) << std::endl;
	std::cout << std::boolalpha << "is bigger or equal	" << (product2 >= product1) << std::endl;



	//-------------------------------------------------------------------------------------------------------


	std::cout << "\n--- MAP ITERATOR TESTS --" << std::endl;
	ft::map<std::string, int>::iterator it = testMap.begin();
	ft::pair <std::string, int> testPair = *it;
	std::cout << "--- TEST INCREMENT --" << std::endl;
	std::cout << "points to key: " << it->first << std::endl;
	std::cout << "points to value: " << it->second << std::endl;
	++it;
	std::cout << "points to key: " << it->first << std::endl;
	std::cout << "points to value: " << it->second << std::endl;
	//it += 4;	doesn't exist
	it++;
	it++;
	it++;
	std::cout << "points to key: " << it->first << std::endl;
	std::cout << "points to value: " << it->second << std::endl;
	// std::cout << "--- TEST DECREMENT --" << std::endl;
	// it--;
	// std::cout << "points to key: " << it->first << std::endl;
	// std::cout << "points to value: " << it->second << std::endl;
	// it--;
	// std::cout << "points to key: " << it->first << std::endl;
	// std::cout << "points to value: " << it->second << std::endl;
	// it--;
	// std::cout << "points to key: " << it->first << std::endl;
	// std::cout << "points to value: " << it->second << std::endl;




	// std::cout << "Map contains" << std::endl;
	// for (ft::map<std::string, int>::iterator it = testMap.begin(); it != testMap.end(); it++) {
	// 	std::cout << it->first << " = " << it->second << "; ";
	// 	it++;
	// 	std::cout << it->first << " = " << it->second << "; ";
	// }
	// std::cout << '\n';


	ft::map<std::string, int>::iterator ite = testMap.begin();
	std::cout << ite->first << " = " << ite->second << "; \n";
	ft::map<std::string, int>::iterator iter = testMap.end();
	iter--;
	std::cout << iter->first << " = " << iter->second << "; \n";

	//testMap.printInOrder();

	// std::cout << "--- CONTENTS TESTMAP --" << std::endl;
	// for (ft::map<std::string, int>::iterator it = testMap.begin(); it != testMap.end(); it++) {
	// 	std::cout << it->first << " = " << it->second << "; ";
	// }
	// std::cout << '\n';


	// std::cout << "--- TEST SECOND CONSTRUCTOR (fill with iterator range) --" << std::endl;
	// ft::map<std::string,int> testMap2 (it, testMap.end());
	// for (ft::map<std::string, int>::iterator it = testMap2.begin(); it != testMap2.end(); it++) {
	// 	std::cout << it->first << " = " << it->second << "; ";
	// }
	// std::cout << '\n';







	// std::pair<std::map<std::string,int>::iterator,bool> ret;
	// ret = testMap.insert(std::pair<std::string,int>("X", 500));
	// if(ret.second == false) {
	// 	std::cout << "element 'X' already existed";
	// 	std::cout << " with a value of " << ret.first->second << '\n';
	// }

	// bool ret = testMap.insert(std::pair<std::string,int>("X", 500));
	// if(ret == false) {
	// 	std::cout << "element 'X' already existed";
	// 	//std::cout << " with a value of " << ret.first->second << '\n';
	// }

	testMap.clear();
	std::cout << std::boolalpha << "Map empty after clear: " << testMap.empty() << '\n';



}

