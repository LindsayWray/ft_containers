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
	#include "vector.hpp"
#endif

void	stringVectorTests(std::ofstream& tests){

	tests << "\n--- STRING VECTOR GENERAL TESTS --" << std::endl;
	ft::vector<std::string> testVec;

	testVec.push_back("one");
	testVec.push_back("two");
	testVec.push_back("three");
	testVec.push_back("four");
	testVec.push_back("five");
	testVec.push_back("six");
	testVec.push_back("seven");
	testVec.push_back("eight");
	testVec.push_back("nine");
	testVec.push_back("ten");
	testVec.push_back("eleven");
	testVec.push_back("twelve");
	for(int i = 12; i < 300; i++){
		testVec.push_back("test");
	}
	tests << "size			" << testVec.size() << std::endl;
	tests << "capacity		" << testVec.capacity() << std::endl;
	tests << "first element		" << testVec.front() << std::endl;
	tests << "as const		" << static_cast<const ft::vector<std::string> >(testVec).front() << std::endl;
	tests << "last element		" << testVec.back() << std::endl;
	tests << "as const		" << static_cast<const ft::vector<std::string> >(testVec).back() << std::endl;
	tests << "[] operator		" << testVec[10] << std::endl;
	tests << "as const		" << static_cast<const ft::vector<std::string> >(testVec)[100] << std::endl;
	//tests << "out of bounds		" << testVec[500] << std::endl;
	try{
		tests << "at func test		" << testVec.at(10) << std::endl;
		tests << "as const		" << static_cast<const ft::vector<std::string> >(testVec).at(100) << std::endl;
		tests << "out of bounds		" << tests << testVec.at(301) << std::endl;
	}
	catch(std::out_of_range& e){
		tests << e.what() << std::endl;
	}


	ft::vector<std::string> copyVector(testVec);
	copyVector.push_back("test copy constructor");
	tests << "size original		" << testVec.size() << std::endl;
	tests << "size copy		" << copyVector.size() << std::endl;
	testVec = copyVector;
	tests << "last original		" << testVec.back() << std::endl;
	tests << "last copy		" << copyVector.back() << std::endl;


	testVec.resize(50);
	tests << "size after smaller resize	" << testVec.size() << std::endl;
	tests << "capacity after smaller resize	" << testVec.capacity() << std::endl;
	try{
		tests << "on index 49			" << testVec.at(49) << std::endl;
		//tests << "on index 50			" << testVec.at(50) << std::endl;
	}
	catch(std::out_of_range& e){
		tests << e.what() << std::endl;
	}
	
	testVec.resize(200);
	tests << "size after bigger resize	" << testVec.size() << std::endl;
	tests << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	tests << "[] operator		"<< testVec[50] << std::endl;
	tests << "[] operator		" << testVec[199] << std::endl;
	tests << "[] operator		" << testVec[49] << std::endl;
	testVec.resize(400, "more test");
	tests << "size after bigger resize	" << testVec.size() << std::endl;
	tests << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	tests << "[] operator		"<< testVec[199] << std::endl;
	tests << "[] operator		"<< testVec[200] << std::endl;
	tests << "[] operator		" << testVec[399] << std::endl;
	tests << "[] operator		" << testVec[50] << std::endl;
	testVec.resize(400);
	tests << "size after equal	" << testVec.size() << std::endl;
	tests << "capacity after equal	" << testVec.capacity() << std::endl;

	tests << "max capacity		" << testVec.max_size() << std::endl;
	testVec.reserve(300);
	tests << "reserve capacity		" << testVec.capacity() << std::endl;
	testVec.reserve(1000);
	tests << "reserve capacity		" << testVec.capacity() << std::endl;
	testVec.resize(1000);
	testVec.push_back("test");
	tests << "reserve capacity		" << testVec.capacity() << std::endl;

	// tests << "realvector contains:";
	// for (ft::vector<std::string>::iterator it = testVec.begin() ; it != testVec.end(); ++it)
	// 	tests << ' ' << *it;
	// tests << '\n';



	tests << "------------------------------------------------" << std::endl;

	testVec.resize(15);
	for (ft::vector<std::string>::iterator ite = testVec.begin() ; ite != testVec.end(); ++ite)
		tests << ' ' << *ite;
	tests << '\n';



	// SECOND VECTOR CONSTRUCTOR 
	ft::vector<std::string> testVec2 (4,"constructor_test");
	tests << "vector constructor with input:";
	for (ft::vector<std::string>::iterator it = testVec2.begin(); it != testVec2.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "capacity	" << testVec2.capacity() << std::endl;

	//IN PROGRESS
	// std::vector<std::string> testVec3 (testVec.begin(), testVec.end());
	//	tests << "vector constructor with range contains:";
	// for (std::vector<std::string>::iterator it = testVec3.begin(); it != testVec3.end(); ++it)
	// 	tests << ' ' << *it;
	//	tests << '\n';

	ft::vector<std::string>::iterator iterat = testVec.begin();
	iterat += 4;
	testVec.insert(iterat, "inserted_string");
	tests << "vector after single insert: ";
	for (ft::vector<std::string>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	testVec.insert(testVec.end(), testVec2.begin(), testVec2.end());
	
	testVec.insert(iterat, 3, "more_inserts");
	tests << "vector after n inserts: ";
	for (ft::vector<std::string>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "vector after iterator insert: ";
	for (ft::vector<std::string>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	testVec.pop_back();
	tests << "vector pop_back:	";
	for (ft::vector<std::string>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';





	tests << "  Erase TESTS\n";
	tests << "vector contains: ";
	for (ft::vector<std::string>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "size before erase: " << testVec.size() << std::endl;
	testVec.erase(testVec.begin() + 3);
	tests << "vector contains: ";
	for (ft::vector<std::string>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "size after erase: " << testVec.size() << std::endl;
	testVec.erase((testVec.begin() + 4), (testVec.begin() + 10));
	tests << "vector contains: ";
	for (ft::vector<std::string>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "size after mass erase: " << testVec.size() << std::endl;

	tests << "  Assign TESTS\n";
	tests << "vector contains: ";
	for (ft::vector<std::string>::iterator it = testVec2.begin(); it != testVec2.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "capacity before assign: " << testVec2.capacity() << std::endl;
	testVec2.assign(testVec.begin(), testVec.end());
	for (ft::vector<std::string>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "vector after assign: ";
	for (ft::vector<std::string>::iterator it = testVec2.begin(); it != testVec2.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "capacity after assign: " << testVec2.capacity() << std::endl;
	testVec2.assign(6, "cats");
	tests << "vector after assign: ";
	for (ft::vector<std::string>::iterator it = testVec2.begin(); it != testVec2.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "capacity after assign: " << testVec2.capacity() << std::endl;


	ft::vector<std::string> copyVec(testVec);
	tests << "  Clear TESTS\n";
	tests << "vector contains: ";
	for (ft::vector<std::string>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "size before clear: " << testVec.size() << std::endl;
	tests << "capacity before clear: " << testVec.capacity() << std::endl;
	testVec.clear();
	tests << "size after clear: " << testVec.size() << std::endl;
	tests << "capacity after clear: " << testVec.capacity() << std::endl;
	tests << "vector after clear: ";
	for (ft::vector<std::string>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	testVec = copyVec;


	//-------------------------------------------------------------------------------------------------------




	tests << "------------------------------------------------" << std::endl;


	tests << "\n--- STRING VECTOR ITERATOR TESTS --" << std::endl;
	ft::vector<std::string>::iterator ite = testVec.begin();
	tests << "on index 2: " << ite->at(2) << std::endl;
	tests << *ite++ << std::endl;

	tests << "is equal			" << (ite == testVec.end()) << std::endl;
	tests << "is not equal			" << (ite != testVec.end()) << std::endl;
	tests << "is not equal			" << (ite != testVec.end()) << std::endl;
	tests << "is smaller			" << (ite < testVec.end()) << std::endl;
	tests << "is smaller			" << (testVec.end() < ite) << std::endl;
	tests << "is bigger			" << (ite > testVec.end()) << std::endl;
	tests << "is bigger			" << (testVec.end() > ite) << std::endl;
	tests << "is smaller or equal		" << (ite <= testVec.end()) << std::endl;
	tests << "is smaller or equal		" << (testVec.end() <= testVec.end()) << std::endl;
	tests << "is bigger or equal		" << (ite >= testVec.end()) << std::endl;
	tests << "is bigger or equal		" << (ite >= ite) << std::endl;
	tests << "the value is			" << *ite << std::endl;
	++ite;
	ite++;
	tests << "the value after increment	" << *ite << std::endl;
	--ite;
	ite--;
	tests << "the value after decrement	" << *ite << std::endl;
	tests << "dereference and increment	" << *ite++ << std::endl;
	tests << "dereference and increment	" << *++ite << std::endl;
	tests << "increment with five		" << *(ite + 5) << std::endl;
	tests << "std::string first increment		" << *(8 + ite) << std::endl;

	ft::vector<std::string>::iterator iter = testVec.begin();
	tests << "size				" << testVec.size() << std::endl;
	ite += 8;
	iter += 3;
	tests << "value				" << *ite << std::endl;
	tests << "value				" << *iter << std::endl;
	tests << "subtract iterators		" << ite - iter << std::endl;
	tests << "subtract iterators		" << iter - ite << std::endl;
	tests << "decrement	eight		" << *(ite - 8) << std::endl;
	ite -= 9;
	tests << "after decrement			" << *ite << std::endl;
	ite += 5;
	tests << "after increment			" << *ite << std::endl;
	tests << "look at index eight		" << ite[8] << std::endl;




	//-------------------------------------------------------------------------------------------------------


	tests << "\n--- STRING VECTOR REVERSE ITERATOR TESTS --" << std::endl;
	ft::vector<std::string>::reverse_iterator rite = testVec.rbegin();
	tests << "begin value " << *rite << std::endl;
	tests << "end value " << *(testVec.rend()) << std::endl;
	tests << "on index 2: " << rite->at(2) << std::endl;
	tests << *rite++ << std::endl;	


	tests << "vector contains:";
	for (ft::vector<std::string>::reverse_iterator rite = testVec.rbegin(); rite != testVec.rend(); ++rite){
		tests << ' ' << *rite;
	}
	tests << '\n';

	tests << "is equal			" << (rite == testVec.rend()) << std::endl;
	tests << "is not equal			" << (rite != testVec.rend()) << std::endl;
	tests << "is smaller			" << (testVec.rend() < rite) << std::endl;
	tests << "is bigger			" << (rite > testVec.rend()) << std::endl;
	tests << "is bigger			" << (testVec.rend() > rite) << std::endl;
	tests << "is smaller or equal		" << (rite <= testVec.rend()) << std::endl;
	tests << "is smaller or equal		" << (testVec.rend() <= testVec.rend()) << std::endl;
	tests << "is bigger or equal		" << (rite >= testVec.rend()) << std::endl;
	tests << "is bigger or equal		" << (rite >= rite) << std::endl;


	tests << "the value is			" << *rite << std::endl;
	++rite;
	rite++;
	tests << "the value after increment	" << *rite << std::endl;
	--rite;
	rite--;
	tests << "the value after decrement	" << *rite << std::endl;
	tests << "dereference and increment	" << *rite++ << std::endl;
	tests << "dereference and increment	" << *++rite << std::endl;
	tests << "increment with five		" << *(rite + 5) << std::endl;
	tests << "std::string first increment		" << *(8 + rite) << std::endl;
	tests << "subtract riterators		" << rite - testVec.rend() << std::endl;
	

}
