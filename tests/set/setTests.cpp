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
	#include "../../Containers/set.hpp"
	#include "../../Containers/vector.hpp"
	#include "../../Utils/RBtree.hpp"
	#include "../RBTValidationTest.hpp"
#endif

template<class T>
// void printSet(ft::set<T>& set, std::ofstream& tests){
// 	for (typename ft::set<T>::iterator it = set.begin(); it != set.end(); it++) {
// 		tests << *it << "; ";
// 	}
// 	tests << '\n';
// }

void printSet(ft::set<T>& set, std::ofstream& tests){
	(void)tests;
;	for (typename ft::set<T>::iterator it = set.begin(); it != set.end(); it++) {
		tests << *it << "; ";
	}
	tests << '\n';
}



void setTests(std::ofstream& tests){
	tests << "******************** SET TESTS ********************\n";
	tests << "******************** SET INT TESTS ********************\n";
	ft::set<int> testSet;

	tests << std::boolalpha << "Is set empty: " << testSet.empty() << std::endl;
	ft::set<int>::iterator empty_it = testSet.begin();
	if(empty_it == testSet.end())
		tests << "iterator on empty set\n";
	
	testSet.insert(20);
	testSet.insert(20); // double test
	testSet.insert(5);
	testSet.insert(-300);
	testSet.insert(8);
	printSet(testSet, tests);

	tests << "current size " << testSet.size() << std::endl;
	//tests << "max size " << testSet.max_size() << std::endl;

	for(int i = 0; i < 100; i++){
		testSet.insert(i * 3);
	}
	tests << "current size " << testSet.size() << std::endl;

	std::cout << "Is valid Red Black Tree: " << ft::validRB(testSet.getTreeForTesting(), testSet.value_comp()) << std::endl;

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
	testSet2.erase("test");
	printSet(testSet2, tests);

	tests << "current size " << testSet2.size() << std::endl;
	//tests << "max size " << testSet2.max_size() << std::endl;

	std::cout << "Is valid Red Black Tree: " << ft::validRB(testSet2.getTreeForTesting(), testSet2.value_comp()) << std::endl;


	tests << "--- TEST SECOND CONSTRUCTOR (fill with iterator range) --" << std::endl;
	ft::set<int>::iterator ite = testSet.begin();
	ite++, ite++, ite++, ite++;
	ft::set<int> testSet3(ite, testSet.end());
	printSet(testSet3, tests);

	tests << "--- TEST ERASE WITH ITERATORS--" << std::endl;
	ite = testSet3.begin();
	ite++, ite++, ite++, ite++, ite++, ite++, ite++, ite++;
	testSet3.erase(ite, testSet3.end());
	tests << "testset 3 contains\n";
	printSet(testSet3, tests);

	//testSet3.printTree();
	std::cout << "Is valid Red Black Tree: " << ft::validRB(testSet3.getTreeForTesting(), testSet3.value_comp()) << std::endl;

	tests << "Set contains" << std::endl;
	printSet(testSet, tests);
	// tests << "Set backwards" << std::endl;
	// for (ft::set<int>::reverse_iterator it = testSet.rbegin(); it != testSet.rend(); it++) {
	// 	tests << *it << "; ";
	// }
	// tests << '\n';

	// tests << "Const iterate" << std::endl;
	// for (ft::set<std::string>::const_iterator it = testSet2.begin(); it != testSet2.end(); it++) {
	// 	tests << *it << "; ";
	// }
	// tests << '\n';
	// tests << "Const iterate backwards" << std::endl;
	// for (ft::set<std::string>::const_reverse_iterator it = testSet2.rbegin(); it != testSet2.rend(); it++) {
	// 	tests << *it << "; ";
	// }
	// tests << '\n';


	tests << "\n--- CONST ITERATOR COMPARE --" << std::endl;
	ft::set<int>::iterator const_it = testSet.begin(); 
	ite = testSet.begin();
	ite++, ite++, ite++;
	tests << std::boolalpha << "is equal			" << (ite == const_it) << std::endl;
	tests << std::boolalpha << "is not equal			" << (ite != const_it) << std::endl;
	tests << std::boolalpha << "is equal			" << (const_it == ite) << std::endl;
	tests << std::boolalpha << "is not equal			" << (const_it != ite) << std::endl;
	tests << "get key  " << *const_it << std::endl;



	tests << "  Swap TESTS\n";
	ft::set<int, char>::iterator it_testMemory = testSet.begin();
	tests << "begin set 2 before swap: " << *it_testMemory << std::endl;
	tests << "Size set 2 before swap: " << testSet.size() << std::endl;
	tests << "Set 2 before swap: ";
	printSet(testSet, tests);
	ft::set<int, char>::iterator it_testMemory2 = testSet3.begin();
	tests << "begin set 3 before swap: " << *it_testMemory2 << std::endl;
	tests << "Size set 3 before swap: " << testSet3.size() << std::endl;
	tests << "Set 3 before swap:";
	printSet(testSet3, tests);

	testSet.swap(testSet3);

	tests << "begin set 2 after swap: " << *it_testMemory << std::endl;
	tests << "Size set 2 after swap: " << testSet.size() << std::endl;
	tests << "Set 2 after swap: ";
	printSet(testSet, tests);

	tests << "begin set 3 after swap: " << *it_testMemory2 << std::endl;
	tests << "Size set 3 after swap: " << testSet3.size() << std::endl;
	tests << "Set 3 after swap:";
	printSet(testSet3, tests);


	tests << "Value Compare TEST:\n";
	ft::set<char> myset;
	myset.insert('x');
	myset.insert('z');
	myset.insert('y');
	char highest = *myset.rbegin();
	for(ft::set<char>::iterator it = myset.begin(); it != myset.end(); it++){
		tests << std::boolalpha << myset.value_comp()(*it, highest);
		tests << " " << *it << '\n';
	}


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