#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "vector.hpp"

void intVectorTests(std::ofstream& tests1, std::ofstream& tests2){

	// 	MY VECTOR
	tests1 << "--- INT VECTOR GENERAL TESTS --" << std::endl;
	ft::vector<int> vector_int;

	for(int i = 0; i < 300; i++){
		vector_int.push_back(i);
	}
	
	tests1 << "size			" << vector_int.size() << std::endl;
	tests1 << "capacity		" << vector_int.capacity() << std::endl;
	tests1 << "first element		" << vector_int.front() << std::endl;
	tests1 << "as const		" << static_cast<const ft::vector<int> >(vector_int).front() << std::endl;
	tests1 << "last element		" << vector_int.back() << std::endl;
	tests1 << "as const		" << static_cast<const ft::vector<int> >(vector_int).back() << std::endl;
	tests1 << "[] operator		" << vector_int[10] << std::endl;
	tests1 << "as const		" << static_cast<const ft::vector<int> >(vector_int)[100] << std::endl;
	tests1 << "out of bounds		" << vector_int[500] << std::endl;
	try{
		tests1 << "at func test		" << vector_int.at(10) << std::endl;
		tests1 << "as const		" << static_cast<const ft::vector<int> >(vector_int).at(100) << std::endl;
		tests1 << "out of bounds		" << vector_int.at(300) << std::endl;
	}
	catch(std::out_of_range& e){
		tests1 << e.what() << std::endl;
	}

	vector_int.resize(50);
	tests1 << "size after smaller resize	" << vector_int.size() << std::endl;
	tests1 << "capacity after smaller resize	" << vector_int.capacity() << std::endl;
	
	vector_int.resize(200);
	tests1 << "size after bigger resize	" << vector_int.size() << std::endl;
	tests1 << "capacity after bigger resize	" << vector_int.capacity() << std::endl;
	tests1 << "[] operator		" << vector_int[51] << std::endl;
	tests1 << "[] operator		" << vector_int[199] << std::endl;
	tests1 << "[] operator		" << vector_int[200] << std::endl;
	vector_int.resize(400, 99);
	tests1 << "size after bigger resize	" << vector_int.size() << std::endl;
	tests1 << "capacity after bigger resize	" << vector_int.capacity() << std::endl;
	tests1 << "[] operator		" << vector_int[51] << std::endl;
	tests1 << "[] operator		" << vector_int[399] << std::endl;
	tests1 << "[] operator		" << vector_int[300] << std::endl;

	tests1 << "max capacity		" << vector_int.max_size() << std::endl;
	vector_int.reserve(300);
	tests1 << "reserve capacity		" << vector_int.capacity() << std::endl;
	vector_int.reserve(1000);
	tests1 << "reserve capacity		" << vector_int.capacity() << std::endl;

	// tests1 << "myvector contains:";
	// for (ft::vector<int>::iterator it = vector_int.begin() ; it != vector_int.end(); ++it)
	// 	tests1 << ' ' << *it;
	// tests1 << '\n';

	vector_int.resize(50);
	tests1 << "vector contains:";
	for (ft::vector<int>::iterator it = vector_int.begin() ; it != vector_int.end(); ++it)
		tests1 << ' ' << *it;
	tests1 << '\n';

	std::cout << "------------------------------------------------" << std::endl;

 	ft::vector<int> vector_int2 (7,100);
	std::cout << "vector constructor with input:";
	for (ft::vector<int>::iterator it = vector_int2.begin(); it != vector_int2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "capacity	" << vector_int2.capacity() << std::endl;


	//IN PROGRESS
	// ft::vector<int> vector_int3 (vector_int.begin(), vector_int.end());
	// std::cout << "vector constructor with range contains:";
	// for (ft::vector<int>::iterator it = vector_int3.begin(); it != vector_int3.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	
	vector_int.resize(10);
	std::cout << "original state: ";
	for (ft::vector<int>::iterator it = vector_int.begin(); it != vector_int.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	vector_int.insert(vector_int.end(), 900);
	std::cout << "my vector after end insert:	";
	for (ft::vector<int>::iterator it = vector_int.begin(); it != vector_int.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	ft::vector<int>::iterator itera = vector_int.begin();
		itera += 4;
	vector_int.insert(itera, 300);
	std::cout << "my vector after middle insert:	";
	for (ft::vector<int>::iterator it = vector_int.begin(); it != vector_int.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	vector_int.insert(itera, 3, 200);
	std::cout << "my vector after n inserts: ";
	for (ft::vector<int>::iterator it = vector_int.begin(); it != vector_int.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	vector_int.insert(itera, vector_int2.begin(), vector_int2.end());
	std::cout << "my vector after iterator range insert:	";
	for (ft::vector<int>::iterator it = vector_int.begin(); it != vector_int.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	vector_int.pop_back();
	std::cout << "vector pop_back:	";
	for (ft::vector<int>::iterator it = vector_int.begin(); it != vector_int.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	
	




	// 	REAL VECTOR
	tests2 << "--- INT VECTOR GENERAL TESTS --" << std::endl;
	std::vector<int> testVec;

	for(int i = 0; i < 300; i++){
		testVec.push_back(i);
	}
	tests2 << "size			" << testVec.size() << std::endl;
	tests2 << "capacity		" << testVec.capacity() << std::endl;
	tests2 << "first element		" << testVec.front() << std::endl;
	tests2 << "as const		" << static_cast<const std::vector<int> >(testVec).front() << std::endl;
	tests2 << "last element		" << testVec.back() << std::endl;
	tests2 << "as const		" << static_cast<const std::vector<int> >(testVec).back() << std::endl;
	tests2 << "[] operator		" << testVec[10] << std::endl;
	tests2 << "as const		" << static_cast<const std::vector<int> >(testVec)[100] << std::endl;
	tests2 << "out of bounds		" << testVec[500] << std::endl;
	try{
		tests2 << "at func test		" << testVec.at(10) << std::endl;
		tests2 << "as const		" << static_cast<const std::vector<int> >(testVec).at(100) << std::endl;
		tests2 << "out of bounds		" << tests2 << testVec.at(301) << std::endl;
	}
	catch(std::out_of_range& e){
		tests2 << e.what() << std::endl;
	}

	testVec.resize(50);
	tests2 << "size after smaller resize	" << testVec.size() << std::endl;
	tests2 << "capacity after smaller resize	" << testVec.capacity() << std::endl;
	
	testVec.resize(200);
	tests2 << "size after bigger resize	" << testVec.size() << std::endl;
	tests2 << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	tests2 << "[] operator		" << testVec[51] << std::endl;
	tests2 << "[] operator		" << testVec[199] << std::endl;
	tests2 << "[] operator		" << testVec[200] << std::endl;
	testVec.resize(400, 99);
	tests2 << "size after bigger resize	" << testVec.size() << std::endl;
	tests2 << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	tests2 << "[] operator		" << testVec[51] << std::endl;
	tests2 << "[] operator		" << testVec[399] << std::endl;
	tests2 << "[] operator		" << testVec[300] << std::endl;

	tests2 << "max capacity		" << testVec.max_size() << std::endl;
	testVec.reserve(300);
	tests2 << "reserve capacity		" << testVec.capacity() << std::endl;
	testVec.reserve(1000);
	tests2 << "reserve capacity		" << testVec.capacity() << std::endl;
	
	// tests2 << "realvector contains:";
	// for (std::vector<int>::iterator it = testVec.begin() ; it != testVec.end(); ++it)
	// 	tests2 << ' ' << *it;
	// tests2 << '\n';

	testVec.resize(50);
	tests2 << "vector contains:";
	for (std::vector<int>::iterator ite = testVec.begin() ; ite != testVec.end(); ++ite)
		tests2 << ' ' << *ite;
	tests2 << '\n';
	






	std::cout << "------------------------------------------------" << std::endl;

	// SECOND VECTOR CONSTRUCTOR 
	std::vector<int> testVec2 (7,100);
	std::cout << "vector constructor with input:";
	for (std::vector<int>::iterator it = testVec2.begin(); it != testVec2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "capacity	" << testVec2.capacity() << std::endl;


	//IN PROGRESS
	// std::vector<int> testVec3 (testVec.begin(), testVec.end());
	// std::cout << "vector constructor with range contains:";
	// for (std::vector<int>::iterator it = testVec3.begin(); it != testVec3.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	testVec.resize(10);
	std::cout << "original state ";
	for (std::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	testVec.insert(testVec.end(), 900);
	std::cout << "real vector after end insert:	";
	for (std::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::vector<int>::iterator iterat = testVec.begin();
	iterat += 4;
	testVec.insert(iterat, 300);
	std::cout << "real vector after middle insert: ";
	for (std::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	testVec.insert(iterat, 3, 200);
	std::cout << "real vector after n inserts: ";
	for (std::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	testVec.insert(iterat, testVec2.begin(), testVec2.end());
	std::cout << "vector after iterator range insert:	";
	for (std::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	testVec.pop_back();
	std::cout << "vector pop_back:	";
	for (std::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';






	//-------------------------------------------------------------------------------------------------------



	// 	MY VECTOR
	tests1 << "\n--- INT VECTOR ITERATOR TESTS --" << std::endl;
	ft::vector<int>::iterator it = vector_int.begin();
	tests1 << "is equal			" << (it == vector_int.end()) << std::endl;
	tests1 << "is not equal			" << (it != vector_int.end()) << std::endl;
	tests1 << "is not equal			" << (it != vector_int.end()) << std::endl;
	tests1 << "is smaller			" << (it < vector_int.end()) << std::endl;
	tests1 << "is smaller			" << (vector_int.end() < it) << std::endl;
	tests1 << "is bigger			" << (it > vector_int.end()) << std::endl;
	tests1 << "is bigger			" << (vector_int.end() > it) << std::endl;
	tests1 << "is smaller or equal		" << (it <= vector_int.end()) << std::endl;
	tests1 << "is smaller or equal		" << (vector_int.end() <= vector_int.end()) << std::endl;
	tests1 << "is bigger or equal		" << (it >= vector_int.end()) << std::endl;
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
	tests1 << "increment with eight		" << *(8 + it) << std::endl;

	ft::vector<int>::iterator itr = vector_int.begin();
	tests1 << "size				" << vector_int.size() << std::endl;
	it += 30;
	itr += 3;
	tests1 << "value				" << *it << std::endl;
	tests1 << "value				" << *itr << std::endl;
	tests1 << "subtract iterators		" << it - itr << std::endl;
	tests1 << "subtract iterators		" << itr - it << std::endl;
	tests1 << "decrement with three		" << *(it - 3) << std::endl;
	it += 10;
	tests1 << "after increment ten		" << *it << std::endl;
	it -= 4;
	tests1 << "after decrement four		" << *it << std::endl;
	tests1 << "look at index eight		" << it[8] << std::endl;



	// --- REAL VECTOR --
	tests2 << "\n--- INT VECTOR ITERATOR TESTS --" << std::endl;;
	std::vector<int>::iterator ite = testVec.begin();
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

	std::vector<int>::iterator iter = testVec.begin();
	tests2 << "size				" << testVec.size() << std::endl;
	ite += 30;
	iter += 3;
	tests2 << "value				" << *ite << std::endl;
	tests2 << "value				" << *iter << std::endl;
	tests2 << "subtract iterators		" << ite - iter << std::endl;
	tests2 << "subtract iterators		" << iter - ite << std::endl;
	tests2 << "decrement with three		" << *(ite - 3) << std::endl;
	ite += 10;
	tests2 << "after increment ten		" << *ite << std::endl;
	ite -= 4;
	tests2 << "after decrement four		" << *ite << std::endl;
	tests2 << "look at index eight		" << ite[8] << std::endl;






	//-------------------------------------------------------------------------------------------------------




	//  MY VECTOR
	tests1 << "\n--- INT VECTOR REVERSE ITERATOR TESTS --" << std::endl;
	ft::vector<int>::reverse_iterator rit = vector_int.rbegin();
	tests1 << "begin value " << *rit << std::endl;
	tests1 << "end value " << *(vector_int.rend()) << std::endl;

	tests1 << "vector contains:";
	for (ft::vector<int>::reverse_iterator rit = vector_int.rbegin(); rit != vector_int.rend(); ++rit){
		tests1 << ' ' << *rit;
	}
	tests1 << '\n';

	tests1 << "is equal			" << (rit == vector_int.rend()) << std::endl;
	tests1 << "is not equal			" << (rit != vector_int.rend()) << std::endl;
	tests1 << "is smaller			" << (vector_int.rend() < rit) << std::endl;
	tests1 << "is bigger			" << (rit > vector_int.rend()) << std::endl;
	tests1 << "is bigger			" << (vector_int.rend() > rit) << std::endl;
	tests1 << "is smaller or equal		" << (rit <= vector_int.rend()) << std::endl;
	tests1 << "is smaller or equal		" << (vector_int.rend() <= vector_int.rend()) << std::endl;
	tests1 << "is bigger or equal		" << (rit >= vector_int.rend()) << std::endl;
	tests1 << "is bigger or equal		" << (rit >= rit) << std::endl;


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
	tests1 << "increment with eight		" << *(8 + rit) << std::endl;



	// REAL VECTOR
	tests2 << "\n--- INT VECTOR REVERSE ITERATOR TESTS --" << std::endl;
	std::vector<int>::reverse_iterator rite = testVec.rbegin();
	tests2 << "begin value " << *rite << std::endl;
	tests2 << "end value " << *(testVec.rend()) << std::endl;


	tests2 << "vector contains:";
	for (std::vector<int>::reverse_iterator rite = testVec.rbegin(); rite != testVec.rend(); ++rite){
		tests2 << ' ' << *rite;
	}
	tests2 << '\n';

	tests2 << "is equal			" << (rite == testVec.rend()) << std::endl;
	tests2 << "is not equal			" << (rite != testVec.rend()) << std::endl;
	tests2 << "is smaller			" << (testVec.rend() < rite) << std::endl;
	tests2 << "is bigger			" << (rite > testVec.rend()) << std::endl;
	tests2 << "is bigger			" << (testVec.rend() > rite) << std::endl;
	tests2 << "is smaller or equal		" << (rite <= testVec.rend()) << std::endl;
	tests2 << "is smaller or equal		" << (testVec.rend() <= testVec.rend()) << std::endl;
	tests2 << "is bigger or equal		" << (rite >= testVec.rend()) << std::endl;
	tests2 << "is bigger or equal		" << (rite >= rite) << std::endl;


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
	tests2 << "increment with eight		" << *(8 + rite) << std::endl;
}
