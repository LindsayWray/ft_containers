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
	#include "../../vector.hpp"
	#include "../../map.hpp"
#endif


void speedTestVector(){
	ft::vector<int> largeIntVec;
	for(int i = 0; i < 10000; i++){
		largeIntVec.push_back(i);
	}

	ft::vector<std::string> largeStringVec;
	for(int i = 0; i < 10000; i++){
		largeStringVec.push_back("TEST");
	}

	int val = largeIntVec.size();
	val = largeIntVec.capacity();
	val = largeIntVec.front();
	std::string val_str = largeStringVec.front();
	val = largeIntVec.back();
	val_str = largeStringVec[10];

	ft::vector<std::string> copyVecString(largeStringVec);
	ft::vector<int> copyVecInt(largeIntVec);


	for (ft::vector<int>::const_iterator ite = largeIntVec.begin() ; ite != largeIntVec.end(); ){ ++ite; }
	for (ft::vector<std::string>::const_iterator ite = largeStringVec.begin() ; ite != largeStringVec.end(); ){ ++ite; }

	largeIntVec.resize(800);
	largeStringVec.resize(800);
}

void speedTestMap(){

	ft::map<int, int> testBigMap;
	for(int i = 0, j = 10000; i < 10000; i++, j--){
		testBigMap[i] = j;
	}

	ft::map<int, int> copyBigMap(testBigMap);

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



	// Swap TESTS\n";
	ft::map<int, char>::iterator it_testMemory = testMap2.begin();
	val = it_testMemory->first;
	char val_char = it_testMemory->second;
	val = testMap2.size();
	for (ft::map<int, char>::iterator it = testMap2.begin(); it != testMap2.end(); ) {
		it++;
	}
	ft::map<int, char>::iterator it_testMemory2 = testMap3.begin();
	val = it_testMemory2->first;
	val_char = it_testMemory2->second;
	val = testMap3.size();
	for (ft::map<int, char>::iterator it = testMap3.begin(); it != testMap3.end(); ){
		it++;
	}

	testMap.clear();
}

