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
	#include "../../map.hpp"
#endif


void speedTest(){

	ft::map<int, int> testBigMap;
	for(int i = 0, j = 10000; i < 10000; i++, j--){
		testBigMap[i] = j;
	}

	ft::map<std::string, std::string> testBigMap2;
	for(int i = 0; i < 10000; i++){
		testBigMap2["test"] = "TEST";
	}

	ft::map<std::string, int> testMap;

	testMap.empty();

	testMap["K"] = 100;
	testMap["A"] = 10;
	testMap["P"] = 22;
	testMap["R"] = 12;
	testMap["V"] = 31;
	testMap["C"] = 20;
	testMap["N"] = 28;
	testMap["I"] = 1;
	testMap["D"] = 3;
	testMap["B"] = 15;
	testMap["T"] = 14;
	testMap["E"] = 12;
	testMap["G"] = 14;
	testMap["Q"] = 21;
	testMap["Z"] = 33;
	testMap["L"] = 45;
	testMap["H"] = 31;
	testMap["J"] = 7;
	testMap["M"] = 14;
	testMap["O"] = 45;
	testMap["F"] = 30;
	testMap["S"] = 30;
	testMap["U"] = 21;
	testMap["W"] = 7;


	int val = testMap["O"];
	testMap.size();
	testMap.max_size();
	val = testMap["A"];
	testMap["A"] = 25;

	testMap.insert(ft::pair<std::string,int>("X", 100));
	testMap.insert(ft::pair<std::string,int>("Y", 200));
	val = testMap["X"];
	val = testMap["Y"];
	val = testMap["Z"];
	testMap.erase("M");

	testMap.insert(testMap.begin(), ft::pair<std::string,int>("G", 500));

	// PAIR CONSTRUCTOR TESTS
	ft::pair <std::string,double> product1;                     // default constructor
	ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
	ft::pair <std::string,double> product3 (product2);          // copy constructor

	product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

	product2.first = "pencils";                  // the type of first is string
	product2.second = 39.90;                   // the type of second is double

	std::string val_str = product1.first;
	float val_float = product1.second;
	val_str = product2.first;
	val_float = product2.second;
	val_str = product3.first;
	val_float = product3.second;

	// PAIR RELATIONAL COMPARE
	bool val_bool = product1 == product2;
	ft::pair <std::string,double> product4 (product2);
	val_bool = product4 == product2;
	val_bool =product3 != product2;
	val_bool = product2 < product1;
	val_bool = product4 <= product2;
	val_bool = product1 > product1;
	val_bool = product2 >= product1;


	ft::map<int, char> testMap2;
	testMap2[10] = 'a';
	testMap2[18] = 'b';
	testMap2[7] = 'c';
	testMap2[15] = 'd';
	testMap2[16] = 'e';
	testMap2[30] = 'f';
	testMap2[25] = 'g';
	testMap2[40] = 'h';
	testMap2[60] = 'i';
	testMap2[2] = 'j';
	testMap2[1] = 'k';
	testMap2[70] = 'l';
	
	testMap2.erase(16);
	testMap2.erase(16);

	//--- MAP ITERATOR TESTS --"
	ft::map<std::string, int>::iterator it = testMap.begin();
	ft::pair <std::string, int> testPair = *it;
	val_str = it->first;
	val = it->second;
	++it;
	val_str = it->first;
	val = it->second;
	it++, it++, it++;
	val_str = it->first;
	val = it->second;
	it--;
	val_str = it->first;
	val = it->second;



	//--- TEST SECOND CONSTRUCTOR (fill with iterator range)
	ft::map<int, char>::iterator ite = testMap2.begin();
	ite++, ite++, ite++;
	ft::map<int, char> testMap3(ite, testMap2.end());
	for (ft::map<int, char>::iterator it = testMap3.begin(); it != testMap3.end(); ) {
		it++;
	}

	// //testMap3.printInOrder();

	// tests << "--- TEST ERASE WITH ITERATORS--" << std::endl;
	// ft::map<int, char>::iterator iter = testMap3.begin();
	// iter++, iter++;
	// testMap3.erase(iter, testMap3.end());
	// for (ft::map<int, char>::iterator it = testMap3.begin(); it != testMap3.end(); it++) {
	// 	tests << it->first << " = " << it->second << "; ";
	// }
	// tests << '\n';

	// //testMap3.printInOrder();



	// ft::pair<ft::map<std::string,int>::iterator,bool> ret;
	// ret = testMap.insert(ft::pair<std::string,int>("X", 500));
	// if(ret.second == false) {
	// 	tests << "element 'X' already existed";
	// 	tests << " with a value of " << ret.first->second << '\n';
	// }


	// tests << "  Swap TESTS\n";
	// ft::map<int, char>::iterator it_testMemory = testMap2.begin();
	// tests << "begin map 2 before swap: " << it_testMemory->first << ", " << it_testMemory->second << std::endl;
	// tests << "Size map 2 before swap: " << testMap2.size() << std::endl;
	// tests << "Map 2 before swap: ";
	// for (ft::map<int, char>::iterator it = testMap2.begin(); it != testMap2.end(); it++) {
	// 	tests << it->first << " = " << it->second << "; ";
	// }
	// tests << '\n';
	// ft::map<int, char>::iterator it_testMemory2 = testMap3.begin();
	// tests << "begin map 3 before swap: " << it_testMemory2->first << ", " << it_testMemory2->second << std::endl;
	// tests << "Size map 3 before swap: " << testMap3.size() << std::endl;
	// tests << "Map 3 before swap:";
	// for (ft::map<int, char>::iterator it = testMap3.begin(); it != testMap3.end(); it++) {
	// 	tests << it->first << " = " << it->second << "; ";
	// }
	// tests << '\n';
	// testMap2.swap(testMap3);
	// tests << "begin map 2 after swap: " << it_testMemory->first << ", " << it_testMemory->second << std::endl;
	// tests << "Size map 2 after swap: " << testMap2.size() << std::endl;
	// tests << "Map 2 after swap: ";
	// for (ft::map<int, char>::iterator it = testMap2.begin(); it != testMap2.end(); it++) {
	// 	tests << it->first << " = " << it->second << "; ";
	// }
	// tests << '\n';
	// tests << "begin map 3 after swap: " << it_testMemory2->first << ", " << it_testMemory2->second << std::endl;
	// tests << "Size map 3 after swap: " << testMap3.size() << std::endl;
	// tests << "Map 3 after swap:";
	// for (ft::map<int, char>::iterator it = testMap3.begin(); it != testMap3.end(); it++) {
	// 	tests << it->first << " = " << it->second << "; ";
	// }
	// tests << '\n';


	// tests << "Value Compare TEST:\n";
	// ft::map<char,int> mymap;
	// mymap['x']=1001;
	// mymap['y']=2002;
	// mymap['z']=3003;
	// ft::pair<char,int> highest = *mymap.rbegin();
	// for(ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++){
	// 	tests << std::boolalpha << mymap.value_comp()(*it, highest);
	// 	tests << " " << it->first << " => " << it->second << '\n';
	// }



	// tests << "Operations TESTS" << std::endl;
	// tests << "Testmap 3 contains: ";
	// for (ft::map<int, char>::iterator it = testMap3.begin(); it != testMap3.end(); it++) {
	// 	tests << it->first << " = " << it->second << "; ";
	// }
	// ft::map<int, char>::iterator test_it = testMap3.find(10);  			//should be in tree
	// tests << "found key " << test_it->first << " value: " << test_it->second << std::endl;
	// test_it = testMap3.find(-1);  //is not in this tree
	// if(test_it != testMap3.end())
	// 	tests << "found key " << test_it->first << " value: " << test_it->second << std::endl;
	// else
	// 	tests << "key was not found\n";
	// ft::map<int, char>::const_iterator test_const_it = testMap3.find(10);
	// tests << "found key " << test_const_it->first << " value: " << test_const_it->second << std::endl;

	// tests << "is key in map: " << testMap3.count(10) << std::endl;
	// tests << "is key in map: " << testMap3.count(-1) << std::endl;

	// test_it = testMap3.lower_bound(25);
	// tests << "lowerbound of key " << test_it->first << " value: " << test_it->second << std::endl;
	// 	test_it = testMap3.lower_bound(32);
	// tests << "lowerbound of key " << test_it->first << " value: " << test_it->second << std::endl;
	// 	test_const_it = testMap3.lower_bound(32);
	// tests << "compare it and const it: " << std::boolalpha << (test_it == test_const_it) << std::endl;
	// tests << "lowerbound of key " << test_const_it->first << " value: " << test_const_it->second << std::endl;
	// test_it = testMap3.lower_bound(80);
	// if(test_it != testMap3.end())
	// 	tests << "lowerbound of key " << test_it->first << " value: " << test_it->second << std::endl;
	// else
	// 	tests << "No lowerbound for this key\n";

	// test_it = testMap3.upper_bound(25);
	// tests << "upper_bound of key " << test_it->first << " value: " << test_it->second << std::endl;
	// 	test_it = testMap3.upper_bound(32);
	// tests << "upper_bound of key " << test_it->first << " value: " << test_it->second << std::endl;
	// test_it = testMap3.upper_bound(80);
	// if(test_it != testMap3.end())
	// 	tests << "upper_bound of key " << test_it->first << " value: " << test_it->second << std::endl;
	// else
	// 	tests << "No upper_bound for this key\n";

	
	// ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator> pair_of_its = testMap3.equal_range(25);
	// tests << "range from key " << pair_of_its.first->first << " to key: " << pair_of_its.second->first << std::endl;
	// pair_of_its = testMap3.equal_range(32);		//key not in tree, so range 0
	// tests << "range from key " << pair_of_its.first->first << " to key: " << pair_of_its.second->first << std::endl;
	// ft::pair<ft::map<int, char>::const_iterator, ft::map<int, char>::const_iterator> pair_of_const_its = testMap3.equal_range(7);
	// tests << "range from key " << pair_of_const_its.first->first << " to key: " << pair_of_const_its.second->first << std::endl;


	// tests << "Assignment operator and Copy constructor" << std::endl;
	// tests << "Map 2 before assignment\n";
	// printMap(testMap2, tests);
	// tests << "Map 3 before assignment\n";
	// printMap(testMap3, tests);
	// testMap3 = testMap2;
	// tests << "Map 3 after assignment\n";
	// printMap(testMap3, tests);
	// testMap3.erase(10);
	// tests << "Map 3 after erase\n";
	// printMap(testMap3, tests);
	// tests << "element map 2 has not been erased\n";
	// printMap(testMap2, tests);

	// testMap2[30] = 'o'; testMap2[-90] = 'H'; testMap2[6000] = 'p';
	// ft::map<int, char> copyMap(testMap2);
	// tests << "Map 2 contains\n";
	// printMap(testMap2, tests);
	// tests << "CopyMap contains\n";
	// printMap(copyMap, tests);
	// copyMap.erase(-90);
	// tests << "CopyMap after erase\n";
	// printMap(copyMap, tests);
	// tests << "Map 2 not affected by erase\n";
	// printMap(testMap2, tests);


	testMap.clear();
}

