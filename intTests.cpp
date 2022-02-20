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


void intVectorTests(std::ofstream& tests){


	tests << "--- INT VECTOR GENERAL TESTS --" << std::endl;
	ft::vector<int> testVec;

	for(int i = 0; i < 300; i++){
		testVec.push_back(i);
	}
	tests << "size			" << testVec.size() << std::endl;
	tests << "capacity		" << testVec.capacity() << std::endl;
	tests << "first element		" << testVec.front() << std::endl;
	tests << "as const		" << static_cast<const ft::vector<int> >(testVec).front() << std::endl;
	tests << "last element		" << testVec.back() << std::endl;
	tests << "as const		" << static_cast<const ft::vector<int> >(testVec).back() << std::endl;
	tests << "[] operator		" << testVec[10] << std::endl;
	tests << "as const		" << static_cast<const ft::vector<int> >(testVec)[100] << std::endl;
	tests << "out of bounds		" << testVec[500] << std::endl;
	try{
		tests << "at func test		" << testVec.at(10) << std::endl;
		tests << "as const		" << static_cast<const ft::vector<int> >(testVec).at(100) << std::endl;
		tests << "out of bounds		" << tests << testVec.at(301) << std::endl;
	}
	catch(std::out_of_range& e){
		tests << e.what() << std::endl;
	}

	testVec.resize(50);
	tests << "size after smaller resize	" << testVec.size() << std::endl;
	tests << "capacity after smaller resize	" << testVec.capacity() << std::endl;
	
	testVec.resize(200);
	tests << "size after bigger resize	" << testVec.size() << std::endl;
	tests << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	tests << "[] operator		" << testVec[51] << std::endl;
	tests << "[] operator		" << testVec[199] << std::endl;
	tests << "[] operator		" << testVec[200] << std::endl;
	testVec.resize(400, 99);
	tests << "size after bigger resize	" << testVec.size() << std::endl;
	tests << "capacity after bigger resize	" << testVec.capacity() << std::endl;
	tests << "[] operator		" << testVec[51] << std::endl;
	tests << "[] operator		" << testVec[399] << std::endl;
	tests << "[] operator		" << testVec[300] << std::endl;

	tests << "max capacity		" << testVec.max_size() << std::endl;
	testVec.reserve(300);
	tests << "reserve capacity		" << testVec.capacity() << std::endl;
	testVec.reserve(1000);
	tests << "reserve capacity		" << testVec.capacity() << std::endl;
	
	// tests << "realvector contains:";
	// for (ft::vector<int>::iterator it = testVec.begin() ; it != testVec.end(); ++it)
	// 	tests << ' ' << *it;
	// tests << '\n';

	testVec.resize(50);
	tests << "vector contains:";
	for (ft::vector<int>::iterator ite = testVec.begin() ; ite != testVec.end(); ++ite)
		tests << ' ' << *ite;
	tests << '\n';
	




	tests << "------------------------------------------------" << std::endl;

	// SECOND VECTOR CONSTRUCTOR 
	ft::vector<int> testVec2 (7,100);
	tests << "vector constructor with input:";
	for (ft::vector<int>::iterator it = testVec2.begin(); it != testVec2.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "capacity	" << testVec2.capacity() << std::endl;

	tests << "------------------------------------------------" << std::endl;
	//THIRD VECTOR CONSTRUCTOR
	ft::vector<int> testVec3 (testVec2.begin(), (testVec2.end() - 3));
	tests << "vector constructor with range contains:";
	for (ft::vector<int>::iterator it = testVec3.begin(); it != (testVec3.end()) ; ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "size	" << testVec3.size() << std::endl;
	tests << "capacity " << testVec3.capacity() << std::endl;
	tests << "------------------------------------------------" << std::endl;

	testVec.resize(10);
	tests << "original state: ";
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';


	testVec.insert(testVec.end(), 900);
	tests << "vector after end insert:	";
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	ft::vector<int>::iterator iterat = testVec.begin();
	iterat += 4;
	testVec.insert(iterat, 300);
	tests << "vector after middle insert: ";
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	testVec.insert(iterat, 3, 200);
	tests << "vector after n inserts: ";
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	testVec.insert(iterat, testVec2.begin(), testVec2.end());
	tests << "vector after iterator range insert:	";
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	testVec.pop_back();
	tests << "vector pop_back:	";
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';


	tests << "------------------------------------------------" << std::endl;

	tests << "  Erase TESTS\n";
	tests << "vector contains: ";
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "size before erase: " << testVec.size() << std::endl;
	testVec.erase(testVec.begin() + 3);
	tests << "vector contains: ";
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "size after erase: " << testVec.size() << std::endl;
	testVec.erase((testVec.begin() + 4), (testVec.begin() + 10));
	tests << "vector contains: ";
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "size after mass erase: " << testVec.size() << std::endl;

	tests << "  Assign TESTS\n";
	tests << "vector contains: ";
	for (ft::vector<int>::iterator it = testVec2.begin(); it != testVec2.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "capacity before assign: " << testVec2.capacity() << std::endl;
	testVec2.assign(testVec.begin(), testVec.end());
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "vector after assign: ";
	for (ft::vector<int>::iterator it = testVec2.begin(); it != testVec2.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "capacity after assign: " << testVec2.capacity() << std::endl;
	testVec2.assign(6, 33);
	tests << "vector after assign: ";
	for (ft::vector<int>::iterator it = testVec2.begin(); it != testVec2.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "capacity after assign: " << testVec2.capacity() << std::endl;


	std::cout << "  Swap TESTS\n";
	ft::vector<int>::iterator it_testMemory = testVec2.begin();
	std::cout << "vectorA contains: ";
		std::cout << testVec.size() << std::endl; 
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "vectorB contains: ";
	std::cout << testVec2.size() << std::endl;
	for (ft::vector<int>::iterator it = testVec2.begin(); it != testVec2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << *it_testMemory << std::endl;
	testVec.swap(testVec2);
	std::cout << "vectorA after swap: ";
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "vectorB after swap: ";
	for (ft::vector<int>::iterator it = testVec2.begin(); it != testVec2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << *it_testMemory << std::endl;


	ft::vector<int> copyVec(testVec);
	tests << "  Clear TESTS\n";
	tests << "vector contains: ";
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	tests << "size before clear: " << testVec.size() << std::endl;
	tests << "capacity before clear: " << testVec.capacity() << std::endl;
	testVec.clear();
	tests << "size after clear: " << testVec.size() << std::endl;
	tests << "capacity after clear: " << testVec.capacity() << std::endl;
	tests << "vector after clear: ";
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
	testVec = copyVec;

	std::cout << "  non-member TESTS\n";
	ft::swap(testVec, testVec2);
	std::cout << "vectorA contains: ";
		std::cout << testVec.size() << std::endl; 
	for (ft::vector<int>::iterator it = testVec.begin(); it != testVec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "vectorB contains: ";
	std::cout << testVec2.size() << std::endl;
	for (ft::vector<int>::iterator it = testVec2.begin(); it != testVec2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';



	std::cout << "------------------------------------------------" << std::endl;



	//-------------------------------------------------------------------------------------------------------


	tests << "\n--- INT VECTOR ITERATOR TESTS --" << std::endl;;
	ft::vector<int>::iterator ite = testVec.begin();
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
	tests << "increment with eight		" << *(8 + ite) << std::endl;

	ft::vector<int>::iterator iter = testVec.begin();
	tests << "size				" << testVec.size() << std::endl;
	ite += 30;
	iter += 3;
	tests << "value				" << *ite << std::endl;
	tests << "value				" << *iter << std::endl;
	tests << "subtract iterators		" << ite - iter << std::endl;
	tests << "subtract iterators		" << iter - ite << std::endl;
	tests << "decrement with three		" << *(ite - 3) << std::endl;
	ite += 10;
	tests << "after increment ten		" << *ite << std::endl;
	ite -= 4;
	tests << "after decrement four		" << *ite << std::endl;
	tests << "look at index eight		" << ite[8] << std::endl;






	//-------------------------------------------------------------------------------------------------------



	tests << "\n--- INT VECTOR REVERSE ITERATOR TESTS --" << std::endl;
	ft::vector<int>::reverse_iterator rite = testVec.rbegin();
	tests << "begin value " << *rite << std::endl;
	tests << "end value " << *(testVec.rend()) << std::endl;


	tests << "vector contains:";
	for (ft::vector<int>::reverse_iterator rite = testVec.rbegin(); rite != testVec.rend(); ++rite){
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
	tests << "increment with eight		" << *(8 + rite) << std::endl;


	tests << "------------------------------------------------" << std::endl;
	tests << "------------------------------------------------" << std::endl;
	tests << "------------------------------------------------" << std::endl;


}
