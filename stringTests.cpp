#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "vector.hpp"

void	stringVectorTests(){
	std::cout << "\n--- STRING VECTOR TESTS --" << std::endl;
	std::cout << "--- MY VECTOR --" << std::endl;
	ft::vector<std::string> vector_string;

	std::string str = "test";
	for(int i = 0; i < 300; i++){
		vector_string.push_back(str);
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


	std::cout << "\n--- REAL VECTOR --" << std::endl;
	std::vector<std::string> testVec;

	for(int i = 0; i < 300; i++){
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
	
	testVec.resize(400, "more test");
	std::cout << "size after bigger resize	" << testVec.size() << std::endl;
	std::cout << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	std::cout << "[] operator		" << testVec[51] << std::endl;
	std::cout << "[] operator		" << testVec[399] << std::endl;
	std::cout << "[] operator		" << testVec[400] << std::endl;
}
