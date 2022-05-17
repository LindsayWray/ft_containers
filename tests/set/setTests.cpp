#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#if STD_CONTAINER
	#include <set>
	#include <stack>
	#include <vector>
	#include <iostream>
	namespace ft = std;
#else
	#include "../../set.hpp"
	#include "../../vector.hpp"
#endif

template<class T>
void printSet(ft::set<T>& set, std::ofstream& tests){
	(void)tests;
	for (typename ft::set<T>::iterator it = set.begin(); it != set.end(); it++) {
		tests << *it << "; ";
	}
	tests << '\n';
}


void setTests(std::ofstream& tests){
	tests << "******************** SET TESTS ********************\n";
	tests << "******************** SET INT TESTS ********************\n";
	//(void)tests;
	ft::set<int> testSet;

	tests << std::boolalpha << "Is set empty: " << testSet.empty() << std::endl;
	ft::set<int>::iterator empty_it = testSet.begin();
	if(empty_it == testSet.end())
		tests << "iterator on empty set\n";
	
	testSet.insert(30);
	testSet.insert(30); // double test
	testSet.insert(2);
	testSet.insert(-300);
	testSet.insert(8);
	printSet(testSet, tests);

	tests << "current size " << testSet.size() << std::endl;
	//tests << "max size " << testSet.max_size() << std::endl;



	tests << "******************** SET STRING TESTS ********************\n";
	ft::set<std::string> testSet2;

	tests << std::boolalpha << "Is set empty: " << testSet2.empty() << std::endl;
	ft::set<std::string>::iterator empty_it2 = testSet2.begin();
	if(empty_it2 == testSet2.end())
		tests << "iterator on empty set\n";
	
	testSet2.insert("test");
	testSet2.insert("test more"); // double test
	testSet2.insert("TEST");
	testSet2.insert("testetestests");
	testSet2.insert("STET");
	testSet2.insert("test");
	testSet2.insert("testets");
	testSet2.insert("testing more");
	printSet(testSet2, tests);

	tests << "current size " << testSet2.size() << std::endl;
	//tests << "max size " << testSet2.max_size() << std::endl;


	tests << "--- TEST SECOND CONSTRUCTOR (fill with iterator range) --" << std::endl;
	ft::set<int>::iterator ite = testSet.begin();
	ite++, ite++;
	ft::set<int> testSet3(ite, testSet.end());
	printSet(testSet3, tests);





	tests << "--- TEST: construct set with vector range iterators --" << std::endl;
	ft::vector<int> testvec;
	for(int i = 300; i > 0; i--){
		testvec.push_back(i);
		testvec.push_back(i);
	}

	ft::set<int> testSet4(testvec.begin(), testvec.end());
	tests << " Set filled by vector iterator range";
	printSet(testSet4, tests);
	ft::vector<int> testvec2(testSet4.begin(), testSet4.end());
	for(ft::vector<int>::iterator it = testvec2.begin(); it != testvec2.end(); it++)
		tests << *it << "; ";
	tests << std::endl;
}