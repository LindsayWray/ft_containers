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


	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = vector_int.begin() ; it != vector_int.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int>::iterator it = vector_int.begin();
	std::cout << "does equal work " << (it != vector_int.end()) << std::endl;







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

	std::cout << "realvector contains:";
	for (std::vector<int>::iterator it = testVec.begin() ; it != testVec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
