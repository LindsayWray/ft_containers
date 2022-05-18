#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <list>

#if STD_CONTAINER
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "../../vector.hpp"
#endif


void printVector(ft::vector<int> testVec, std::ofstream& tests) {
	for (ft::vector<int>::const_iterator it = testVec.begin() ; it != testVec.end(); ++it)
		tests << ' ' << *it;
	tests << '\n';
}

// void printVector(ft::vector<int> testVec, std::ofstream& tests) {
// 	for (ft::vector<int>::iterator it = testVec.begin() ; it != testVec.end();  ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';
// }


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
	try{
		tests << "at func test		" << testVec.at(10) << std::endl;
		tests << "as const		" << static_cast<const ft::vector<int> >(testVec).at(100) << std::endl;
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

	//tests << "max capacity		" << testVec.max_size() << std::endl;
	testVec.reserve(300);
	tests << "reserve capacity		" << testVec.capacity() << std::endl;
	testVec.reserve(1000);
	tests << "reserve capacity		" << testVec.capacity() << std::endl;
	

	testVec.resize(50);
	tests << "vector contains:";
	printVector(testVec, tests);
	


	tests << "SECOND VECTOR CONSTRUCTOR\n"; 
	ft::vector<int> testVec2 (7,100);
	tests << "vector constructor with input:";
	printVector(testVec2, tests);
	tests << "capacity	" << testVec2.capacity() << std::endl;

	tests << "------------------------------------------------" << std::endl;
	tests << "THIRD VECTOR CONSTRUCTOR\n";
	ft::vector<int> testVec3 (testVec2.begin(), (testVec2.end() - 3));
	tests << "vector constructor with range contains:";
	printVector(testVec3, tests);
	tests << "size	" << testVec3.size() << std::endl;
	tests << "capacity " << testVec3.capacity() << std::endl;
	tests << "------------------------------------------------" << std::endl;


	tests << "test SFINAE proofness of third constructor\n";
	ft::vector<int> testVecFaulty ("hi", "hello");
	tests << "value: " << testVecFaulty.front() << std::endl;

	testVec.resize(10);
	tests << "original state: ";
	printVector(testVec, tests);


	testVec.insert(testVec.end(), 900);
	tests << "vector after end insert:	";
	printVector(testVec, tests);
	ft::vector<int>::iterator iterat = testVec.begin();
	iterat += 4;
	testVec.insert(iterat, 300);
	tests << "vector after middle insert: ";
	printVector(testVec, tests);
	testVec.insert(iterat, 3, 200);
	tests << "vector after n inserts: ";
	printVector(testVec, tests);
	testVec.insert(iterat, testVec2.begin(), testVec2.end());
	tests << "vector after iterator range insert:	";
	printVector(testVec, tests);

	testVec.pop_back();
	tests << "vector pop_back:	";
	printVector(testVec, tests);


	ft::vector<int> poptest;
	tests << " is empty: " << poptest.empty() << std::endl;
	poptest.pop_back();



	tests << "  Erase TESTS\n";
	tests << "vector contains: ";
	printVector(testVec, tests);
	tests << "size before erase: " << testVec.size() << std::endl;
	testVec.erase(testVec.begin() + 3);
	tests << "vector contains: ";
	printVector(testVec, tests);
	tests << "size after erase: " << testVec.size() << std::endl;
	testVec.erase((testVec.begin() + 4), (testVec.begin() + 10));
	tests << "vector contains: ";
	printVector(testVec, tests);
	tests << "size after mass erase: " << testVec.size() << std::endl;

	tests << "  Assign TESTS\n";
	tests << "vector contains: ";
	printVector(testVec2, tests);
	tests << "capacity before assign: " << testVec2.capacity() << std::endl;
	testVec2.assign(testVec.begin(), testVec.end());
	printVector(testVec, tests);
	tests << "vector after assign: ";
	printVector(testVec2, tests);
	tests << "capacity after assign: " << testVec2.capacity() << std::endl;
	testVec2.assign(6, 33);
	tests << "vector after assign: ";
	printVector(testVec2, tests);
	tests << "capacity after assign: " << testVec2.capacity() << std::endl;


	tests << "  Swap TESTS\n";
	ft::vector<int>::iterator it_testMemory = testVec2.begin();
	tests << "vectorA contains: ";
		tests << testVec.size() << std::endl;
	printVector(testVec, tests);
	tests << "vectorB contains: ";
	tests << testVec2.size() << std::endl;
	printVector(testVec2, tests);
	tests << *it_testMemory << std::endl;
	testVec.swap(testVec2);
	tests << "vectorA after swap: ";
	printVector(testVec, tests);
	tests << "vectorB after swap: ";
	printVector(testVec2, tests);
	tests << *it_testMemory << std::endl;


	ft::vector<int> copyVec(testVec);
	tests << "  Clear TESTS\n";
	tests << "vector contains: ";
	printVector(testVec, tests);
	tests << "size before clear: " << testVec.size() << std::endl;
	tests << "capacity before clear: " << testVec.capacity() << std::endl;
	testVec.clear();
	tests << "size after clear: " << testVec.size() << std::endl;
	tests << "capacity after clear: " << testVec.capacity() << std::endl;
	tests << "vector after clear: ";
	printVector(testVec, tests);
	testVec = copyVec;

	tests << "  non-member TESTS\n";
	ft::swap(testVec, testVec2);
	tests << "vectorA contains: ";
		tests << testVec.size() << std::endl; 
	printVector(testVec, tests);
	tests << "vectorB contains: ";
	tests << testVec2.size() << std::endl;
	printVector(testVec2, tests);




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





	tests << "\n--- CONST ITERATOR COMPARE --" << std::endl;
	ft::vector<int>::iterator const_it = testVec.begin();
	ite = testVec.begin() + 5;

	tests << std::boolalpha << "is equal			" << (ite == const_it) << std::endl;
	tests << std::boolalpha << "is not equal			" << (ite != const_it) << std::endl;
	tests << std::boolalpha << "is smaller			" << (const_it < ite) << std::endl;
	tests << std::boolalpha << "is bigger			" << (const_it > ite) << std::endl;
	tests << std::boolalpha << "is smaller or equal		" << (const_it + 5 <= testVec.end()) << std::endl;
	tests << std::boolalpha << "is bigger or equal		" << (const_it >= testVec.end()) << std::endl;
	tests << "look up index		" << const_it[2] << std::endl;
	tests << "subtract iterators		" << ite - const_it << std::endl;
	tests << "subtract iterators		" << const_it - ite << std::endl;



	tests << "\n--- INT VECTOR REVERSE ITERATOR TESTS --" << std::endl;
	ft::vector<int>::reverse_iterator rite = testVec.rbegin();
	tests << "begin value " << *rite << std::endl;
	tests << "end value " << *(--testVec.rend()) << std::endl;


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
	tests << "subtract riterators		" << rite - testVec.rend() << std::endl;


	printVector(testVec, tests);
	printVector(testVec2, tests);
	printVector(testVec3, tests);
	printVector(copyVec, tests);
	tests << "relational operators testing\n";
	tests << "is equal			" << (testVec2 == copyVec) << std::endl;
	tests << "is equal			" << (testVec == testVec3) << std::endl;
	tests << "is not equal			" << (testVec != copyVec) << std::endl;
	tests << "is smaller			" << (testVec2 < testVec3) << std::endl;
	tests << "is bigger			" << (testVec3 > testVec) << std::endl;
	tests << "is bigger			" << (testVec2 > testVec) << std::endl;
	tests << "is smaller or equal		" << (testVec2 <= testVec2) << std::endl;
	tests << "is smaller or equal		" << (testVec3 <= testVec) << std::endl;
	tests << "is bigger or equal		" << (copyVec >= testVec) << std::endl;
	tests << "is bigger or equal		" << (testVec3 >= testVec2) << std::endl;


	{
		std::list<int> lst;
		std::list<int>::iterator lst_it;
		for (int i = 1; i < 5; ++i)
			lst.push_back(i * 3);

		ft::vector<int> vct(lst.begin(), lst.end());
		std::cout << "size " << vct.size() << std::endl;

		lst_it = lst.begin();
		for (int i = 1; lst_it != lst.end(); ++i)
			*lst_it++ = i * 5;
		vct.assign(lst.begin(), lst.end());
		std::cout << "size " << vct.size() << std::endl;

		vct.insert(vct.end(), lst.rbegin(), lst.rend());
		std::cout << "size " << vct.size() << std::endl;
	}
	

	{
		// ft::vector<int> vct(10);
		// ft::vector<int> vct2;

		// for (unsigned long int i = 0; i < vct.size(); ++i)
		// 	vct[i] = (vct.size() - i) * 3;
		// std::cout << "size " << vct.size() << std::endl;

		// vct2.insert(vct2.end(), 42);

		// for (ft::vector<int>::iterator it = vct2.begin() ; it != vct2.end();  ++it)
		// 	std::cout << ' ' << *it;
		// std::cout << '\n';

		// vct2.insert(vct2.begin(), 2, 21);
		// std::cout << "size " << vct2.size() << std::endl;

		// vct2.insert(vct2.end() - 2, 42);
		// std::cout << "size " << vct2.size() << std::endl;

		// vct2.insert(vct2.end(), 2, 84);
		// std::cout << "size " << vct2.size() << std::endl;

		// vct2.resize(4);
		// std::cout << "size " << vct2.size() << std::endl;

		// vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
		// vct.clear();
		// std::cout << "size " << vct2.size() << std::endl;

		// std::cout << "size " << vct.size() << std::endl;
	}
	std::cout << std::endl;

}
