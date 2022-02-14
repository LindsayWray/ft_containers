#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

#include "vector.hpp"

void	stringVectorTests(std::ofstream& tests1, std::ofstream& tests2){

	//tests1 << "\n--- STRING VECTOR TESTS --" << std::endl;
	//tests1 << "--- MY VECTOR --" << std::endl;
	ft::vector<std::string> vector_string;

	//std::string str = "test";
		vector_string.push_back("one");
		vector_string.push_back("two");
		vector_string.push_back("three");
		vector_string.push_back("four");
		vector_string.push_back("five");
		vector_string.push_back("six");
		vector_string.push_back("seven");
		vector_string.push_back("eight");
		vector_string.push_back("nine");
		vector_string.push_back("ten");
		vector_string.push_back("eleven");
		vector_string.push_back("twelve");
	for(int i = 12; i < 300; i++){
		vector_string.push_back("test");
	}
	
	tests1 << "size			" << vector_string.size() << std::endl;
	tests1 << "capacity		" << vector_string.capacity() << std::endl;
	tests1 << "first element		" << vector_string.front() << std::endl;
	tests1 << "as const		" << static_cast<const ft::vector<std::string> >(vector_string).front() << std::endl;
	tests1 << "last element		" << vector_string.back() << std::endl;
	tests1 << "as const		" << static_cast<const ft::vector<std::string> >(vector_string).back() << std::endl;
	tests1 << "[] operator		" << vector_string[10] << std::endl;
	tests1 << "as const		" << static_cast<const ft::vector<std::string> >(vector_string)[100] << std::endl;
	// tests1 << "out of bounds		" << vector_string[500] << std::endl;   <--- LOOK INTO LATER
	try{
		tests1 << "at func test		" << vector_string.at(10) << std::endl;
		tests1 << "as const		" << static_cast<const ft::vector<std::string> >(vector_string).at(100) << std::endl;
		tests1 << "out of bounds		" << vector_string.at(301) << std::endl;
	}
	catch(std::out_of_range& e){
		tests1 << e.what() << std::endl;
	}


	ft::vector<std::string> copy_vector(vector_string);
	copy_vector.push_back("test copy constructor");
	tests1 << "size original		" << vector_string.size() << std::endl;
	tests1 << "size copy		" << copy_vector.size() << std::endl;
	vector_string = copy_vector;
	tests1 << "last original		" << vector_string.back() << std::endl;
	tests1 << "last copy		" << copy_vector.back() << std::endl;

	vector_string.resize(50);
	tests1 << "size after smaller resize	" << vector_string.size() << std::endl;
	tests1 << "capacity after smaller resize	" << vector_string.capacity() << std::endl;
	try{
		tests1 << "on index 49			" << vector_string.at(49) << std::endl;
		//tests1 << "on index 50			" << vector_string.at(50) << std::endl;  <--- LOOK INTO LATER
	}
	catch(std::out_of_range& e){
		tests1 << e.what() << std::endl;
	}
	
	vector_string.resize(200);
	tests1 << "size after bigger resize	" << vector_string.size() << std::endl;
	tests1 << "capacity after bigger resize	" << vector_string.capacity() << std::endl;
	tests1 << "[] operator		"<< vector_string[50] << std::endl;
	tests1 << "[] operator		" << vector_string[199] << std::endl;
	tests1 << "[] operator		" << vector_string[49] << std::endl;
	vector_string.resize(400, "more test");
	tests1 << "size after bigger resize	" << vector_string.size() << std::endl;
	tests1 << "capacity after bigger resize	" << vector_string.capacity() << std::endl;
	tests1 << "[] operator		"<< vector_string[199] << std::endl;
	tests1 << "[] operator		"<< vector_string[200] << std::endl;
	tests1 << "[] operator		" << vector_string[399] << std::endl;
	tests1 << "[] operator		" << vector_string[50] << std::endl;
	vector_string.resize(400);
	tests1 << "size after equal	" << vector_string.size() << std::endl;
	tests1 << "capacity after equal	" << vector_string.capacity() << std::endl;

	tests1 << "max capacity		" << vector_string.max_size() << std::endl;
	vector_string.reserve(300);
	tests1 << "reserve capacity		" << vector_string.capacity() << std::endl;
	vector_string.reserve(1000);
	tests1 << "reserve capacity		" << vector_string.capacity() << std::endl;
	vector_string.resize(1000);
	vector_string.push_back("test");
	tests1 << "reserve capacity		" << vector_string.capacity() << std::endl;

	// tests1 << "myvector contains:";
	// for (ft::vector<std::string>::iterator it = vector_string.begin() ; it != vector_string.end(); it++)
	// 	tests1 << ' ' << *it;
	// tests1 << '\n';

	vector_string.resize(15);
	for (ft::vector<std::string>::iterator it = vector_string.begin() ; it != vector_string.end(); ++it)
		tests1 << ' ' << *it;
	tests1 << '\n';


	tests1 << "\n--- ITERATOR TESTS --" << std::endl;
	ft::vector<std::string>::iterator it = vector_string.begin();
	tests1 << "on index 2: " << it->at(2) << std::endl;
	tests1 << *it++ << std::endl;
	tests1 << "is equal			" << (it == vector_string.end()) << std::endl;
	tests1 << "is not equal			" << (it != vector_string.end()) << std::endl;
	tests1 << "is not equal			" << (it != vector_string.end()) << std::endl;
	tests1 << "is smaller			" << (it < vector_string.end()) << std::endl;
	tests1 << "is smaller			" << (vector_string.end() < it) << std::endl;
	tests1 << "is bigger			" << (it > vector_string.end()) << std::endl;
	tests1 << "is bigger			" << (vector_string.end() > it) << std::endl;
	tests1 << "is smaller or equal		" << (it <= vector_string.end()) << std::endl;
	tests1 << "is smaller or equal		" << (vector_string.end() <= vector_string.end()) << std::endl;
	tests1 << "is bigger or equal		" << (it >= vector_string.end()) << std::endl;
	tests1 << "is bigger or equal		" << (it >= it) << std::endl;
	tests1 << "the value is			" << *it << std::endl;
	++it;
	it++;
	tests1 << "the value after increment	" << *it << std::endl;
	--it;
	it--;
	tests1 << "the value after decrement	" << *it << std::endl;
	tests1 << "dereference and increment	" << *it++ << std::endl;
	tests1 << "dereference and increment	" << *++it << std::endl;
	tests1 << "increment with five		" << *(it + 5) << std::endl;
	tests1 << "int first increment		" << *(8 + it) << std::endl;
	
	ft::vector<std::string>::iterator itr = vector_string.begin();
	tests1 << "size				" << vector_string.size() << std::endl;
	it += 8;
	itr += 3;
	tests1 << "value				" << *it << std::endl;
	tests1 << "value				" << *itr << std::endl;
	tests1 << "subtract iterators		" << it - itr << std::endl;
	tests1 << "subtract iterators		" << itr - it << std::endl;
	tests1 << "decrement	eight		" << *(it - 8) << std::endl;
	it -= 9;
	tests1 << "after decrement			" << *it << std::endl;
	it += 5;
	tests1 << "after increment			" << *it << std::endl;
	tests1 << "look at index eight		" << it[8] << std::endl;




	tests1 << "\n--- REVERSE ITERATOR TESTS --" << std::endl;
	ft::vector<std::string>::reverse_iterator rit = vector_string.rbegin();
	tests1 << "begin value " << *rit << std::endl;
	tests1 << "end value " << *(vector_string.rend()) << std::endl;
	tests1 << "on index 2: " << rit->at(2) << std::endl;
	tests1 << *rit++ << std::endl;	


	tests1 << "vector contains:";
	for (ft::vector<std::string>::reverse_iterator rit = vector_string.rbegin(); rit != vector_string.rend(); ++rit){
		tests1 << ' ' << *rit;
	}
	tests1 << '\n';


	tests1 << "the value is			" << *rit << std::endl;
	++rit;
	rit++;
	tests1 << "the value after increment	" << *rit << std::endl;
	--rit;
	rit--;
	tests1 << "the value after decrement	" << *rit << std::endl;
	tests1 << "dereference and increment	" << *rit++ << std::endl;
	tests1 << "dereference and increment	" << *++rit << std::endl;
	tests1 << "increment with five		" << *(rit + 5) << std::endl;
	tests1 << "int first increment		" << *(8 + rit) << std::endl;
	tests1 << "subtract riterators		" << rit - vector_string.rend() << std::endl;










	//tests2 << "\n--- REAL VECTOR --" << std::endl;

	std::vector<std::string> testVec;

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
	tests2 << "size			" << testVec.size() << std::endl;
	tests2 << "capacity		" << testVec.capacity() << std::endl;
	tests2 << "first element		" << testVec.front() << std::endl;
	tests2 << "as const		" << static_cast<const std::vector<std::string> >(testVec).front() << std::endl;
	tests2 << "last element		" << testVec.back() << std::endl;
	tests2 << "as const		" << static_cast<const std::vector<std::string> >(testVec).back() << std::endl;
	tests2 << "[] operator		" << testVec[10] << std::endl;
	tests2 << "as const		" << static_cast<const std::vector<std::string> >(testVec)[100] << std::endl;
	//tests2 << "out of bounds		" << testVec[500] << std::endl;
	try{
		tests2 << "at func test		" << testVec.at(10) << std::endl;
		tests2 << "as const		" << static_cast<const std::vector<std::string> >(testVec).at(100) << std::endl;
		tests2 << "out of bounds		" << tests1 << testVec.at(301) << std::endl;
	}
	catch(std::out_of_range& e){
		tests2 << e.what() << std::endl;
	}


	std::vector<std::string> copyVector(testVec);
	copyVector.push_back("test copy constructor");
	tests2 << "size original		" << testVec.size() << std::endl;
	tests2 << "size copy		" << copyVector.size() << std::endl;
	testVec = copyVector;
	tests2 << "last original		" << testVec.back() << std::endl;
	tests2 << "last copy		" << copyVector.back() << std::endl;


	testVec.resize(50);
	tests2 << "size after smaller resize	" << testVec.size() << std::endl;
	tests2 << "capacity after smaller resize	" << testVec.capacity() << std::endl;
	try{
		tests2 << "on index 49			" << testVec.at(49) << std::endl;
		//tests2 << "on index 50			" << testVec.at(50) << std::endl;
	}
	catch(std::out_of_range& e){
		tests2 << e.what() << std::endl;
	}
	
	testVec.resize(200);
	tests2 << "size after bigger resize	" << testVec.size() << std::endl;
	tests2 << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	tests2 << "[] operator		"<< testVec[50] << std::endl;
	tests2 << "[] operator		" << testVec[199] << std::endl;
	tests2 << "[] operator		" << testVec[49] << std::endl;
	testVec.resize(400, "more test");
	tests2 << "size after bigger resize	" << testVec.size() << std::endl;
	tests2 << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	tests2 << "[] operator		"<< testVec[199] << std::endl;
	tests2 << "[] operator		"<< testVec[200] << std::endl;
	tests2 << "[] operator		" << testVec[399] << std::endl;
	tests2 << "[] operator		" << testVec[50] << std::endl;
	testVec.resize(400);
	tests2 << "size after equal	" << testVec.size() << std::endl;
	tests2 << "capacity after equal	" << testVec.capacity() << std::endl;

	tests2 << "max capacity		" << testVec.max_size() << std::endl;
	testVec.reserve(300);
	tests2 << "reserve capacity		" << testVec.capacity() << std::endl;
	testVec.reserve(1000);
	tests2 << "reserve capacity		" << testVec.capacity() << std::endl;
	testVec.resize(1000);
	testVec.push_back("test");
	tests2 << "reserve capacity		" << testVec.capacity() << std::endl;

	// tests2 << "realvector contains:";
	// for (std::vector<std::string>::iterator it = testVec.begin() ; it != testVec.end(); ++it)
	// 	tests2 << ' ' << *it;
	// tests2 << '\n';


	testVec.resize(15);
	for (std::vector<std::string>::iterator ite = testVec.begin() ; ite != testVec.end(); ++ite)
		tests2 << ' ' << *ite;
	tests2 << '\n';


	tests2 << "\n--- ITERATOR TESTS --" << std::endl;
	std::vector<std::string>::iterator ite = testVec.begin();
	tests2 << "on index 2: " << ite->at(2) << std::endl;
	tests2 << *ite++ << std::endl;

	tests2 << "is equal			" << (ite == testVec.end()) << std::endl;
	tests2 << "is not equal			" << (ite != testVec.end()) << std::endl;
	tests2 << "is not equal			" << (ite != testVec.end()) << std::endl;
	tests2 << "is smaller			" << (ite < testVec.end()) << std::endl;
	tests2 << "is smaller			" << (testVec.end() < ite) << std::endl;
	tests2 << "is bigger			" << (ite > testVec.end()) << std::endl;
	tests2 << "is bigger			" << (testVec.end() > ite) << std::endl;
	tests2 << "is smaller or equal		" << (ite <= testVec.end()) << std::endl;
	tests2 << "is smaller or equal		" << (testVec.end() <= testVec.end()) << std::endl;
	tests2 << "is bigger or equal		" << (ite >= testVec.end()) << std::endl;
	tests2 << "is bigger or equal		" << (ite >= ite) << std::endl;
	tests2 << "the value is			" << *ite << std::endl;
	++ite;
	ite++;
	tests2 << "the value after increment	" << *ite << std::endl;
	--ite;
	ite--;
	tests2 << "the value after decrement	" << *ite << std::endl;
	tests2 << "dereference and increment	" << *ite++ << std::endl;
	tests2 << "dereference and increment	" << *++ite << std::endl;
	tests2 << "increment with five		" << *(ite + 5) << std::endl;
	tests2 << "increment with eight		" << *(8 + ite) << std::endl;

	std::vector<std::string>::iterator iter = testVec.begin();
	tests2 << "size				" << testVec.size() << std::endl;
	ite += 8;
	iter += 3;
	tests2 << "value				" << *ite << std::endl;
	tests2 << "value				" << *iter << std::endl;
	tests2 << "subtract iterators		" << ite - iter << std::endl;
	tests2 << "subtract iterators		" << iter - ite << std::endl;
	tests2 << "decrement	eight		" << *(ite - 8) << std::endl;
	ite -= 9;
	tests2 << "after decrement			" << *ite << std::endl;
	ite += 5;
	tests2 << "after increment			" << *ite << std::endl;
	tests2 << "look at index eight		" << ite[8] << std::endl;


	tests2 << "\n--- REVERSE ITERATOR TESTS --" << std::endl;
	std::vector<std::string>::reverse_iterator rite = testVec.rbegin();
	tests2 << "begin value " << *rite << std::endl;
	tests2 << "end value " << *(testVec.rend()) << std::endl;
	tests2 << "on index 2: " << rite->at(2) << std::endl;
	tests2 << *rite++ << std::endl;	


	tests2 << "vector contains:";
	for (std::vector<std::string>::reverse_iterator rite = testVec.rbegin(); rite != testVec.rend(); ++rite){
		tests2 << ' ' << *rite;
	}
	tests2 << '\n';


	tests2 << "the value is			" << *rite << std::endl;
	++rite;
	rite++;
	tests2 << "the value after increment	" << *rite << std::endl;
	--rite;
	rite--;
	tests2 << "the value after decrement	" << *rite << std::endl;
	tests2 << "dereference and increment	" << *rite++ << std::endl;
	tests2 << "dereference and increment	" << *++rite << std::endl;
	tests2 << "increment with five		" << *(rite + 5) << std::endl;
	tests2 << "int first increment		" << *(8 + rite) << std::endl;
	tests2 << "subtract riterators		" << rite - testVec.rend() << std::endl;
	


	//tests2 << "is equal			" << (rite == testVec.rend()) << std::endl;

}
