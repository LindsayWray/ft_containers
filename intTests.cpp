#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "vector.hpp"

void intVectorTests(){

std::cout << "--- INT VECTOR TESTS --" << std::endl;
	std::cout << "--- MY VECTOR --" << std::endl;
	ft::vector<int> vector_int;

	for(int i = 0; i < 300; i++){
		vector_int.push_back(i);
	}
	
	std::cout << "size			" << vector_int.size() << std::endl;
	std::cout << "capacity		" << vector_int.capacity() << std::endl;
	std::cout << "first element		" << vector_int.front() << std::endl;
	std::cout << "as const		" << static_cast<const ft::vector<int> >(vector_int).front() << std::endl;
	std::cout << "last element		" << vector_int.back() << std::endl;
	std::cout << "as const		" << static_cast<const ft::vector<int> >(vector_int).back() << std::endl;
	std::cout << "[] operator		" << vector_int[10] << std::endl;
	std::cout << "as const		" << static_cast<const ft::vector<int> >(vector_int)[100] << std::endl;
	std::cout << "out of bounds		" << vector_int[500] << std::endl;
	try{
		std::cout << "at func test		" << vector_int.at(10) << std::endl;
		std::cout << "as const		" << static_cast<const ft::vector<int> >(vector_int).at(100) << std::endl;
		std::cout << "out of bounds		" << vector_int.at(300) << std::endl;
	}
	catch(std::out_of_range& e){
		std::cout << e.what() << std::endl;
	}

	vector_int.resize(50);
	std::cout << "size after smaller resize	" << vector_int.size() << std::endl;
	std::cout << "capacity after smaller resize	" << vector_int.capacity() << std::endl;
	
	vector_int.resize(200);
	std::cout << "size after bigger resize	" << vector_int.size() << std::endl;
	std::cout << "capacity after bigger resize	" << vector_int.capacity() << std::endl;
	std::cout << "[] operator		" << vector_int[51] << std::endl;
	std::cout << "[] operator		" << vector_int[199] << std::endl;
	std::cout << "[] operator		" << vector_int[200] << std::endl;
	vector_int.resize(400, 99);
	std::cout << "size after bigger resize	" << vector_int.size() << std::endl;
	std::cout << "capacity after bigger resize	" << vector_int.capacity() << std::endl;
	std::cout << "[] operator		" << vector_int[51] << std::endl;
	std::cout << "[] operator		" << vector_int[399] << std::endl;
	std::cout << "[] operator		" << vector_int[300] << std::endl;

	std::cout << "max capacity		" << vector_int.max_size() << std::endl;
	vector_int.reserve(300);
	std::cout << "reserve capacity		" << vector_int.capacity() << std::endl;
	vector_int.reserve(1000);
	std::cout << "reserve capacity		" << vector_int.capacity() << std::endl;


	// std::cout << "myvector contains:";
	// for (ft::vector<int>::iterator it = vector_int.begin() ; it != vector_int.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	vector_int.resize(50);
	std::cout << "realvector contains:";
	for (ft::vector<int>::iterator it = vector_int.begin() ; it != vector_int.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	std::cout << "\n--- ITERATOR TESTS --" << std::endl;
	ft::vector<int>::iterator it = vector_int.begin();
	std::cout << "is equal			" << (it == vector_int.end()) << std::endl;
	std::cout << "is not equal			" << (it != vector_int.end()) << std::endl;
	std::cout << "is not equal			" << (it != vector_int.end()) << std::endl;
	std::cout << "is smaller			" << (it < vector_int.end()) << std::endl;
	std::cout << "is smaller			" << (vector_int.end() < it) << std::endl;
	std::cout << "is bigger			" << (it > vector_int.end()) << std::endl;
	std::cout << "is bigger			" << (vector_int.end() > it) << std::endl;
	std::cout << "is smaller or equal		" << (it <= vector_int.end()) << std::endl;
	std::cout << "is smaller or equal		" << (vector_int.end() <= vector_int.end()) << std::endl;
	std::cout << "is bigger or equal		" << (it >= vector_int.end()) << std::endl;
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

	ft::vector<int>::iterator itr = vector_int.begin();
	std::cout << "size			" << vector_int.size() << std::endl;
	it += 30;
	itr += 3;
	std::cout << "value			" << *it << std::endl;
	std::cout << "value			" << *itr << std::endl;
	//std::cout << "subtract iterators		" << it - itr << std::endl;
	std::cout << "decrement with three		" << *(it - 3) << std::endl;
	it += 10;
	std::cout << "after increment ten		" << *it << std::endl;
	it -= 4;
	std::cout << "after decrement four		" << *it << std::endl;
	std::cout << "look at index eight		" << it[8] << std::endl;

	std::cout << "\n--- REVERSE ITERATOR TESTS --" << std::endl;
	ft::vector<int>::reverse_iterator rit = vector_int.rbegin();
	std::cout << "begin value " << *rit << std::endl;
	std::cout << "end value " << *(vector_int.rend()) << std::endl;

	std::cout << "myvector contains:";
	for (ft::vector<int>::reverse_iterator rit = vector_int.rbegin(); rit != vector_int.rend(); ++rit){
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
	std::vector<int> testVec;

	for(int i = 0; i < 300; i++){
		testVec.push_back(i);
	}
	std::cout << "size			" << testVec.size() << std::endl;
	std::cout << "capacity		" << testVec.capacity() << std::endl;
	std::cout << "first element		" << testVec.front() << std::endl;
	std::cout << "as const		" << static_cast<const std::vector<int> >(testVec).front() << std::endl;
	std::cout << "last element		" << testVec.back() << std::endl;
	std::cout << "as const		" << static_cast<const std::vector<int> >(testVec).back() << std::endl;
	std::cout << "[] operator		" << testVec[10] << std::endl;
	std::cout << "as const		" << static_cast<const std::vector<int> >(testVec)[100] << std::endl;
	std::cout << "out of bounds		" << testVec[500] << std::endl;
	try{
		std::cout << "at func test		" << testVec.at(10) << std::endl;
		std::cout << "as const		" << static_cast<const std::vector<int> >(testVec).at(100) << std::endl;
		std::cout << "out of bounds		" << std::cout << testVec.at(301) << std::endl;
	}
	catch(std::out_of_range& e){
		std::cout << e.what() << std::endl;
	}


	testVec.resize(50);
	std::cout << "size after smaller resize	" << testVec.size() << std::endl;
	std::cout << "capacity after smaller resize	" << testVec.capacity() << std::endl;
	
	testVec.resize(200);
	std::cout << "size after bigger resize	" << testVec.size() << std::endl;
	std::cout << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	std::cout << "[] operator		" << testVec[51] << std::endl;
	std::cout << "[] operator		" << testVec[199] << std::endl;
	std::cout << "[] operator		" << testVec[200] << std::endl;
	testVec.resize(400, 99);
	std::cout << "size after bigger resize	" << testVec.size() << std::endl;
	std::cout << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	std::cout << "[] operator		" << testVec[51] << std::endl;
	std::cout << "[] operator		" << testVec[399] << std::endl;
	std::cout << "[] operator		" << testVec[300] << std::endl;

	std::cout << "max capacity		" << testVec.max_size() << std::endl;
	testVec.reserve(300);
	std::cout << "reserve capacity		" << testVec.capacity() << std::endl;
	testVec.reserve(1000);
	std::cout << "reserve capacity		" << testVec.capacity() << std::endl;
	
	// std::cout << "realvector contains:";
	// for (std::vector<int>::iterator it = testVec.begin() ; it != testVec.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	testVec.resize(50);
	std::cout << "realvector contains:";
	for (std::vector<int>::iterator ite = testVec.begin() ; ite != testVec.end(); ++ite)
		std::cout << ' ' << *ite;
	std::cout << '\n';

	std::cout << "\n--- ITERATOR TESTS --" << std::endl;
	std::vector<int>::iterator ite = testVec.begin();
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
	std::cout << "increment with eight		" << *(8 + ite) << std::endl;

	std::vector<int>::iterator iter = testVec.begin();
	std::cout << "size				" << testVec.size() << std::endl;
	ite += 30;
	iter += 3;
	std::cout << "value				" << *ite << std::endl;
	std::cout << "value				" << *iter << std::endl;
	//std::cout << "subtract iterators		" << iter - ite << std::endl;
	std::cout << "decrement with three		" << *(ite - 3) << std::endl;
	ite += 10;
	std::cout << "after increment ten		" << *ite << std::endl;
	ite -= 4;
	std::cout << "after decrement four		" << *ite << std::endl;
	std::cout << "look at index eight		" << ite[8] << std::endl;


	std::cout << "\n--- REVERSE ITERATOR TESTS --" << std::endl;
	std::vector<int>::reverse_iterator rite = testVec.rbegin();
	std::cout << "begin value " << *rite << std::endl;
	std::cout << "end value " << *(testVec.rend()) << std::endl;


	std::cout << "realvector contains:";
	for (std::vector<int>::reverse_iterator rite = testVec.rbegin(); rite != testVec.rend(); ++rite){
		std::cout << ' ' << *rite;
	}
	std::cout << '\n';

	// std::cout << "is equal			" << (rite == testVec.end()) << std::endl;
	// std::cout << "is not equal			" << (rite != testVec.end()) << std::endl;
	// std::cout << "is not equal			" << (rite != testVec.end()) << std::endl;
	// std::cout << "is smaller			" << (testVec.end() < rite) << std::endl;
	// std::cout << "is bigger			" << (rite > testVec.end()) << std::endl;
	// std::cout << "is bigger			" << (testVec.end() > rite) << std::endl;
	// std::cout << "is smaller or equal		" << (rite <= testVec.end()) << std::endl;
	// std::cout << "is smaller or equal		" << (testVec.end() <= testVec.end()) << std::endl;
	// std::cout << "is bigger or equal		" << (rite >= testVec.end()) << std::endl;
	// std::cout << "is bigger or equal		" << (rite >= rite) << std::endl;

	//https://en.cppreference.com/w/cpp/iterator/reverse_iterator     comparison is non member and should work

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
