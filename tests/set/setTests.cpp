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
	tests << "max size " << testSet.max_size() << std::endl;

}