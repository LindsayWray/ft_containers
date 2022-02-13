#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "vector.hpp"

void	stringVectorTests(){
	std::cout << "\n--- STRING VECTOR TESTS --" << std::endl;
	std::cout << "--- MY VECTOR --" << std::endl;
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
	
	std::cout << "size			" << vector_string.size() << std::endl;
	std::cout << "capacity		" << vector_string.capacity() << std::endl;
	std::cout << "first element		" << vector_string.front() << std::endl;
	std::cout << "as const		" << static_cast<const ft::vector<std::string> >(vector_string).front() << std::endl;
	std::cout << "last element		" << vector_string.back() << std::endl;
	std::cout << "as const		" << static_cast<const ft::vector<std::string> >(vector_string).back() << std::endl;
	std::cout << "[] operator		" << vector_string[10] << std::endl;
	std::cout << "as const		" << static_cast<const ft::vector<std::string> >(vector_string)[100] << std::endl;
	std::cout << "out of bounds		" << vector_string[500] << std::endl;
	try{
		std::cout << "at func test		" << vector_string.at(10) << std::endl;
		std::cout << "as const		" << static_cast<const ft::vector<std::string> >(vector_string).at(100) << std::endl;
		std::cout << "out of bounds		" << vector_string.at(300) << std::endl;
	}
	catch(std::out_of_range& e){
		std::cout << e.what() << std::endl;
	}


	ft::vector<std::string> copy_vector(vector_string);
	copy_vector.push_back("test copy constructor");
	std::cout << "size original		" << vector_string.size() << std::endl;
	std::cout << "size copy		" << copy_vector.size() << std::endl;
	vector_string = copy_vector;
	std::cout << "last original		" << vector_string.back() << std::endl;
	std::cout << "last copy		" << copy_vector.back() << std::endl;

	vector_string.resize(50);
	std::cout << "size after smaller resize	" << vector_string.size() << std::endl;
	std::cout << "capacity after smaller resize	" << vector_string.capacity() << std::endl;
	try{
		std::cout << "on index 49			" << vector_string.at(49) << std::endl;
		std::cout << "on index 50			" << vector_string.at(50) << std::endl;
	}
	catch(std::out_of_range& e){
		std::cout << e.what() << std::endl;
	}
	
	vector_string.resize(200);
	std::cout << "size after bigger resize	" << vector_string.size() << std::endl;
	std::cout << "capacity after bigger resize	" << vector_string.capacity() << std::endl;
	std::cout << "[] operator		"<< vector_string[50] << std::endl;
	std::cout << "[] operator		" << vector_string[199] << std::endl;
	std::cout << "[] operator		" << vector_string[49] << std::endl;
	vector_string.resize(400, "more test");
	std::cout << "size after bigger resize	" << vector_string.size() << std::endl;
	std::cout << "capacity after bigger resize	" << vector_string.capacity() << std::endl;
	std::cout << "[] operator		"<< vector_string[199] << std::endl;
	std::cout << "[] operator		"<< vector_string[200] << std::endl;
	std::cout << "[] operator		" << vector_string[399] << std::endl;
	std::cout << "[] operator		" << vector_string[50] << std::endl;
	vector_string.resize(400);
	std::cout << "size after equal	" << vector_string.size() << std::endl;
	std::cout << "capacity after equal	" << vector_string.capacity() << std::endl;

	std::cout << "max capacity		" << vector_string.max_size() << std::endl;
	vector_string.reserve(300);
	std::cout << "reserve capacity		" << vector_string.capacity() << std::endl;
	vector_string.reserve(1000);
	std::cout << "reserve capacity		" << vector_string.capacity() << std::endl;
	vector_string.resize(1000);
	vector_string.push_back("test");
	std::cout << "reserve capacity		" << vector_string.capacity() << std::endl;

	// std::cout << "myvector contains:";
	// for (ft::vector<std::string>::iterator it = vector_string.begin() ; it != vector_string.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	vector_string.resize(15);
	for (ft::vector<std::string>::iterator it = vector_string.begin() ; it != vector_string.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	std::cout << "\n--- ITERATOR TESTS --" << std::endl;
	ft::vector<std::string>::iterator it = vector_string.begin();
	std::cout << "on index 2: " << it->at(2) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << "is equal			" << (it == vector_string.end()) << std::endl;
	std::cout << "is not equal			" << (it != vector_string.end()) << std::endl;
	std::cout << "is not equal			" << (it != vector_string.end()) << std::endl;
	std::cout << "is smaller			" << (it < vector_string.end()) << std::endl;
	std::cout << "is smaller			" << (vector_string.end() < it) << std::endl;
	std::cout << "is bigger			" << (it > vector_string.end()) << std::endl;
	std::cout << "is bigger			" << (vector_string.end() > it) << std::endl;
	std::cout << "is smaller or equal		" << (it <= vector_string.end()) << std::endl;
	std::cout << "is smaller or equal		" << (vector_string.end() <= vector_string.end()) << std::endl;
	std::cout << "is bigger or equal		" << (it >= vector_string.end()) << std::endl;
	std::cout << "is bigger or equal		" << (it >= it) << std::endl;
	std::cout << "the value is			" << *it << std::endl;
	++it;
	it++;
	std::cout << "the value after increment	" << *it << std::endl;
	--it;
	it--;
	std::cout << "the value after decrement	" << *it << std::endl;
	std::cout << "dereference and increment	" << *it++ << std::endl;
	std::cout << "dereference and increment	" << *++it << std::endl;
	std::cout << "increment with five		" << *(it + 5) << std::endl;
	//std::cout << "increment with eight		" << *(8 + it) << std::endl;
	
	ft::vector<std::string>::iterator itr = vector_string.begin();
	std::cout << "size				" << vector_string.size() << std::endl;
	it += 8;
	itr += 3;
	std::cout << "value				" << *it << std::endl;
	std::cout << "value				" << *itr << std::endl;
	//std::cout << "subtract iterators		" << it - itr << std::endl;
	std::cout << "decrement	eight		" << *(it - 8) << std::endl;
	it -= 9;
	std::cout << "after decrement			" << *it << std::endl;
	it += 5;
	std::cout << "after increment			" << *it << std::endl;
	std::cout << "look at index eight		" << it[8] << std::endl;




	std::cout << "\n--- REVERSE ITERATOR TESTS --" << std::endl;
	ft::vector<std::string>::reverse_iterator rit = vector_string.rbegin();
	std::cout << "begin value " << *rit << std::endl;
	std::cout << "end value " << *(vector_string.rend()) << std::endl;
	std::cout << "on index 2: " << rit->at(2) << std::endl;
	std::cout << *rit++ << std::endl;	


	std::cout << "realvector contains:";
	for (ft::vector<std::string>::reverse_iterator rit = vector_string.rbegin(); rit != vector_string.rend(); ++rit){
		std::cout << ' ' << *rit;
	}
	std::cout << '\n';


	std::cout << "the value is			" << *rit << std::endl;
	++rit;
	rit++;
	std::cout << "the value after increment	" << *rit << std::endl;
	--rit;
	rit--;
	std::cout << "the value after decrement	" << *rit << std::endl;
	std::cout << "dereference and increment	" << *rit++ << std::endl;
	std::cout << "dereference and increment	" << *++rit << std::endl;
	std::cout << "increment with five		" << *(rit + 5) << std::endl;




	std::cout << "\n--- REAL VECTOR --" << std::endl;
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
	std::cout << "size			" << testVec.size() << std::endl;
	std::cout << "capacity		" << testVec.capacity() << std::endl;
	std::cout << "first element		" << testVec.front() << std::endl;
	std::cout << "as const		" << static_cast<const std::vector<std::string> >(testVec).front() << std::endl;
	std::cout << "last element		" << testVec.back() << std::endl;
	std::cout << "as const		" << static_cast<const std::vector<std::string> >(testVec).back() << std::endl;
	std::cout << "[] operator		" << testVec[10] << std::endl;
	std::cout << "as const		" << static_cast<const std::vector<std::string> >(testVec)[100] << std::endl;
	std::cout << "out of bounds		" << testVec[500] << std::endl;
	try{
		std::cout << "at func test		" << testVec.at(10) << std::endl;
		std::cout << "as const		" << static_cast<const std::vector<std::string> >(testVec).at(100) << std::endl;
		std::cout << "out of bounds		" << std::cout << testVec.at(301) << std::endl;
	}
	catch(std::out_of_range& e){
		std::cout << e.what() << std::endl;
	}


	std::vector<std::string> copyVector(testVec);
	copyVector.push_back("test copy constructor");
	std::cout << "size original		" << testVec.size() << std::endl;
	std::cout << "size copy		" << copyVector.size() << std::endl;
	testVec = copyVector;
	std::cout << "last original		" << testVec.back() << std::endl;
	std::cout << "last copy		" << copyVector.back() << std::endl;


	testVec.resize(50);
	std::cout << "size after smaller resize	" << testVec.size() << std::endl;
	std::cout << "capacity after smaller resize	" << testVec.capacity() << std::endl;
	try{
		std::cout << "on index 49			" << testVec.at(49) << std::endl;
		std::cout << "on index 50			" << testVec.at(50) << std::endl;
	}
	catch(std::out_of_range& e){
		std::cout << e.what() << std::endl;
	}
	
	testVec.resize(200);
	std::cout << "size after bigger resize	" << testVec.size() << std::endl;
	std::cout << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	std::cout << "[] operator			"<< testVec[50] << std::endl;
	std::cout << "[] operator			" << testVec[199] << std::endl;
	std::cout << "[] operator			" << testVec[49] << std::endl;
	testVec.resize(400, "more test");
	std::cout << "size after bigger resize	" << testVec.size() << std::endl;
	std::cout << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	std::cout << "[] operator		"<< testVec[199] << std::endl;
	std::cout << "[] operator		"<< testVec[200] << std::endl;
	std::cout << "[] operator		" << testVec[399] << std::endl;
	std::cout << "[] operator		" << testVec[50] << std::endl;
	testVec.resize(400);
	std::cout << "size after equal	" << testVec.size() << std::endl;
	std::cout << "capacity after equal	" << testVec.capacity() << std::endl;

	std::cout << "max capacity		" << testVec.max_size() << std::endl;
	testVec.reserve(300);
	std::cout << "reserve capacity		" << testVec.capacity() << std::endl;
	testVec.reserve(1000);
	std::cout << "reserve capacity		" << testVec.capacity() << std::endl;
	testVec.resize(1000);
	testVec.push_back("test");
	std::cout << "reserve capacity		" << testVec.capacity() << std::endl;

	// std::cout << "realvector contains:";
	// for (std::vector<std::string>::iterator it = testVec.begin() ; it != testVec.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';


	testVec.resize(15);
	for (std::vector<std::string>::iterator ite = testVec.begin() ; ite != testVec.end(); ++ite)
		std::cout << ' ' << *ite;
	std::cout << '\n';


	std::cout << "\n--- ITERATOR TESTS --" << std::endl;
	std::vector<std::string>::iterator ite = testVec.begin();
	std::cout << "on index 2: " << ite->at(2) << std::endl;
	std::cout << *ite++ << std::endl;

	std::cout << "is equal			" << (ite == testVec.end()) << std::endl;
	std::cout << "is not equal			" << (ite != testVec.end()) << std::endl;
	std::cout << "is not equal			" << (ite != testVec.end()) << std::endl;
	std::cout << "is smaller			" << (ite < testVec.end()) << std::endl;
	std::cout << "is smaller			" << (testVec.end() < ite) << std::endl;
	std::cout << "is bigger			" << (ite > testVec.end()) << std::endl;
	std::cout << "is bigger			" << (testVec.end() > ite) << std::endl;
	std::cout << "is smaller or equal		" << (ite <= testVec.end()) << std::endl;
	std::cout << "is smaller or equal		" << (testVec.end() <= testVec.end()) << std::endl;
	std::cout << "is bigger or equal		" << (ite >= testVec.end()) << std::endl;
	std::cout << "is bigger or equal		" << (ite >= ite) << std::endl;
	std::cout << "the value is			" << *ite << std::endl;
	++ite;
	ite++;
	std::cout << "the value after increment	" << *ite << std::endl;
	--ite;
	ite--;
	std::cout << "the value after decrement	" << *ite << std::endl;
	std::cout << "dereference and increment	" << *ite++ << std::endl;
	std::cout << "dereference and increment	" << *++ite << std::endl;
	std::cout << "increment with five		" << *(ite + 5) << std::endl;
	//std::cout << "increment with eight		" << *(8 + ite) << std::endl;

	std::vector<std::string>::iterator iter = testVec.begin();
	std::cout << "size				" << testVec.size() << std::endl;
	ite += 8;
	iter += 3;
	std::cout << "value				" << *ite << std::endl;
	std::cout << "value				" << *iter << std::endl;
	//std::cout << "subtract iterators		" << iter - ite << std::endl;
	std::cout << "decrement	eight		" << *(ite - 8) << std::endl;
	ite -= 9;
	std::cout << "after decrement			" << *ite << std::endl;
	ite += 5;
	std::cout << "after increment			" << *ite << std::endl;
	std::cout << "look at index eight		" << ite[8] << std::endl;


	std::cout << "\n--- REVERSE ITERATOR TESTS --" << std::endl;
	std::vector<std::string>::reverse_iterator rite = testVec.rbegin();
	std::cout << "begin value " << *rite << std::endl;
	std::cout << "end value " << *(testVec.rend()) << std::endl;
	std::cout << "on index 2: " << rite->at(2) << std::endl;
	std::cout << *rite++ << std::endl;	


	std::cout << "realvector contains:";
	for (std::vector<std::string>::reverse_iterator rite = testVec.rbegin(); rite != testVec.rend(); ++rite){
		std::cout << ' ' << *rite;
	}
	std::cout << '\n';


	std::cout << "the value is			" << *rite << std::endl;
	++rite;
	rite++;
	std::cout << "the value after increment	" << *rite << std::endl;
	--rite;
	rite--;
	std::cout << "the value after decrement	" << *rite << std::endl;
	std::cout << "dereference and increment	" << *rite++ << std::endl;
	std::cout << "dereference and increment	" << *++rite << std::endl;
	std::cout << "increment with five		" << *(rite + 5) << std::endl;
	//std::cout << "increment with eight		" << *(8 + rite) << std::endl;

}
