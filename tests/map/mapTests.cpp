#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#if STD_CONTAINER
	#include <map>
	#include <stack>
	#include <vector>
	#include <iostream>
	namespace ft = std;
#else
	#include "../../map.hpp"
#endif


template<class T1, class T2>
void printTree(ft::map<T1, T2>& map, std::ofstream& tests){
	(void)tests;
	for (typename ft::map<T1, T2>::const_iterator it = map.begin(); it != map.end(); it++) {
		tests << it->first << " = " << it->second << "; ";
	}
	tests << '\n';
}

// void printTreeterminal(std::string_view comment, const std::map<std::string, int>& m)
// {
// 	tests << comment ;
// 	for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++) {
// 		tests << it->first << " = " << it->second << "; ";
// 	}
// 	tests << '\n';
// }




#include <list>
typedef ft::pair<const int, std::string> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param) {
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	std::cout << "size map *-*-* " << mp.size() << std::endl;
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2) {
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	std::cout << "size map **** " << mp.size() << std::endl;
}

void		erase_test() {
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	ft::map<int, std::string> mp(lst.begin(), lst.end());

	std::cout << "size map * " << mp.size() << std::endl;

	ft_erase(mp, ++mp.begin());

	ft_erase(mp, mp.begin());
	ft_erase(mp, --mp.end());

	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	//ft_erase(mp, --(--(--mp.end())), --mp.end());

	mp[10] = "Hello";
	mp[11] = "Hi there";

	std::cout << "size map ** " << mp.size() << std::endl;
	// ft_erase(mp, --(--(--mp.end())), mp.end());

	mp[12] = "ONE";
	mp[13] = "TWO";
	mp[14] = "THREE";
	mp[15] = "FOUR";

	std::cout << "size map*** " << mp.size() << std::endl;
	ft_erase(mp, mp.begin(), mp.end());

}








template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};






// #define T1 char
// #define T2 foo<float>
// typedef ft::map<T1, T2> _map;
// typedef _map::const_iterator const_it;

// static unsigned int i = 0;

// void	ft_comp(const _map &mp, const const_it &it1, const const_it &it2) {
// 	bool res[2];

// 	std::cout << "\t-- [" << ++i << "] --" << std::endl;
// 	res[0] = mp.key_comp()(it1->first, it2->first);
// 	res[1] = mp.value_comp()(*it1, *it2);
// 	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
// 	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
// }


// void		test_comp() {
// 	_map	mp;

// 	mp['a'] = 2.3;
// 	mp['b'] = 1.4;
// 	mp['c'] = 0.3;
// 	mp['d'] = 4.2;
// 	//printSize(mp);
// 	std::cout << "size map: " << mp.size() << std::endl;

// 	for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
// 		for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
// 			ft_comp(mp, it1, it2);

// 	//printSize(mp);
// 	std::cout << "size map: " << mp.size() << std::endl;
// }





void mapTests(std::ofstream& tests){

	tests << "\n--- MAP GENERAL TESTS --" << std::endl;

	ft::map<std::string, int> testMap;

	tests << std::boolalpha << "Is map empty: " << testMap.empty() << std::endl;
	ft::map<std::string, int>::iterator empty_it = testMap.begin();
	if(empty_it == testMap.end())
		tests << "iterator on empty map\n";

	testMap["K"] = 100;
	testMap["A"] = 10;
	testMap["P"] = 22;
	testMap["R"] = 12;
	testMap["V"] = 31;
	testMap["C"] = 20;
	testMap["N"] = 28;
	testMap["I"] = 1;
	testMap["D"] = 3;
	testMap["B"] = 15;
	testMap["T"] = 14;
	testMap["E"] = 12;
	testMap["G"] = 14;
	testMap["Q"] = 21;
	testMap["Z"] = 33;
	testMap["L"] = 45;
	testMap["H"] = 31;
	testMap["J"] = 7;
	testMap["M"] = 14;
	testMap["O"] = 45;
	testMap["F"] = 30;
	testMap["S"] = 30;
	testMap["U"] = 21;
	testMap["W"] = 7;

	//testMap.printTree();

	tests << "Value O is: " << testMap["O"] << std::endl;
	tests << "The map size is: " << testMap.size() << std::endl;
	tests << "The max size is: " << testMap.max_size() << std::endl;
	tests << "Value A before: " << testMap["A"] << std::endl;
	testMap["A"] = 25;  // update an existing value
	tests << "Value A after: " << testMap["A"] << std::endl;

	testMap.insert(ft::pair<std::string,int>("X", 100));
	testMap.insert(ft::pair<std::string,int>("Y", 200));
	tests << "Value X is: " << testMap["X"] << std::endl;
	tests << "Value Y is: " << testMap["Y"] << std::endl;
	tests << "Value Z is: " << testMap["Z"] << std::endl;
	//testMap.erase("M");

	testMap.insert(testMap.begin(), ft::pair<std::string,int>("G", 500));

	// PAIR CONSTRUCTOR TESTS
	ft::pair <std::string,double> product1;                     // default constructor
	ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
	ft::pair <std::string,double> product3 (product2);          // copy constructor

	product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

	product2.first = "pencils";                  // the type of first is string
	product2.second = 39.90;                   // the type of second is double

	tests << "The price of " << product1.first << " is $" << product1.second << '\n';
	tests << "The price of " << product2.first << " is $" << product2.second << '\n';
	tests << "The price of " << product3.first << " is $" << product3.second << '\n';

	// PAIR RELATIONAL COMPARE
	tests << std::boolalpha << "is equal		" << (product1 == product2) << std::endl;
	ft::pair <std::string,double> product4 (product2);
	tests << std::boolalpha << "is equal		" << (product4 == product2) << std::endl;
	tests << std::boolalpha << "not equal		" << (product3 != product2) << std::endl;
	tests << std::boolalpha << "is smaller		" << (product2 < product1) << std::endl;
	tests << std::boolalpha << "is smaller or equal	" << (product4 <= product2) << std::endl;
	tests << std::boolalpha << "is bigger		" << (product1 > product1) << std::endl;
	tests << std::boolalpha << "is bigger or equal	" << (product2 >= product1) << std::endl;



	ft::map<int, char> testMap2;
	testMap2[10] = 'a';
	testMap2[18] = 'b';
	testMap2[7] = 'c';
	testMap2[15] = 'd';
	testMap2[16] = 'e';
	testMap2[30] = 'f';
	testMap2[25] = 'g';
	testMap2[40] = 'h';
	testMap2[60] = 'i';
	testMap2[2] = 'j';
	testMap2[1] = 'k';
	testMap2[70] = 'l';
	


	//testMap2.printTree();
	testMap2.erase(16);
	//testMap2.printTree();
	testMap2.erase(16);
	//testMap2.printTree();



	//-------------------------------------------------------------------------------------------------------


	tests << "\n--- MAP ITERATOR TESTS --" << std::endl;
	ft::map<std::string, int>::iterator it = testMap.begin();
	ft::pair <std::string, int> testPair = *it;
	tests << "--- TEST INCREMENT --" << std::endl;
	tests << "points to key: " << it->first << std::endl;
	tests << "points to value: " << it->second << std::endl;
	++it;
	tests << "points to key: " << it->first << std::endl;
	tests << "points to value: " << it->second << std::endl;
	it++, it++, it++;
	tests << "points to key: " << it->first << std::endl;
	tests << "points to value: " << it->second << std::endl;
	tests << "--- TEST DECREMENT --" << std::endl;
	it--;
	tests << "points to key: " << it->first << std::endl;
	tests << "points to value: " << it->second << std::endl;
	it--;
	tests << "points to key: " << it->first << std::endl;
	tests << "points to value: " << it->second << std::endl;
	it--;
	tests << "points to key: " << it->first << std::endl;
	tests << "points to value: " << it->second << std::endl;
	it = testMap.end();
	it--;
	tests << " begin: " << it->second << std::endl;




	// tests << "Map contains" << std::endl;
	// for (ft::map<std::string, int>::iterator it = testMap.begin(); it != testMap.end(); it++) {
	// 	tests << it->first << " = " << it->second << "; ";
	// }
	// tests << '\n';
	// tests << "Map backwards" << std::endl;
	// for (ft::map<std::string, int>::reverse_iterator it = testMap.rbegin(); it != testMap.rend(); it++) {
	// 	tests << it->first << " = " << it->second << "; ";
	// }
	// tests << '\n';


	// tests << "Const iterate" << std::endl;
	// for (ft::map<std::string, int>::const_iterator it = testMap.begin(); it != testMap.end(); it++) {
	// 	tests << it->first << " = " << it->second << "; ";
	// }
	// tests << '\n';
	// tests << "Const iterate backwards" << std::endl;
	// for (ft::map<std::string, int>::const_reverse_iterator it = testMap.rbegin(); it != testMap.rend(); it++) {
	// 	tests << it->first << " = " << it->second << "; ";
	// }
	// tests << '\n';




	tests << "\n--- CONST ITERATOR COMPARE --" << std::endl;
	ft::map<std::string, int>::iterator const_it = testMap.begin(); 
	it = testMap.begin();
	it++, it++, it++;
	tests << std::boolalpha << "is equal			" << (it == const_it) << std::endl;
	tests << std::boolalpha << "is not equal			" << (it != const_it) << std::endl;
	tests << std::boolalpha << "is equal			" << (const_it == it) << std::endl;
	tests << std::boolalpha << "is not equal			" << (const_it != it) << std::endl;
	tests << "look up key  " << const_it->first << " and value " << const_it->second << std::endl;


	tests << "--- TEST SECOND CONSTRUCTOR (fill with iterator range) --" << std::endl;
	ft::map<int, char>::iterator ite = testMap2.begin();
	ite++, ite++, ite++;
	ft::map<int, char> testMap3(ite, testMap2.end());
	for (ft::map<int, char>::iterator it = testMap3.begin(); it != testMap3.end(); it++) {
		tests << it->first << " = " << it->second << "; ";
	}
	tests << '\n';

	//testMap3.printTree();

	tests << "--- TEST ERASE WITH ITERATORS--" << std::endl;
	ft::map<int, char>::iterator iter = testMap3.begin();
	iter++, iter++;
	testMap3.erase(iter, testMap3.end());
	for (ft::map<int, char>::iterator it = testMap3.begin(); it != testMap3.end(); it++) {
		tests << it->first << " = " << it->second << "; ";
	}
	tests << '\n';

	//testMap3.printTree();



	ft::pair<ft::map<std::string,int>::iterator,bool> ret;
	ret = testMap.insert(ft::pair<std::string,int>("X", 500));
	if(ret.second == false) {
		tests << "element 'X' already existed";
		tests << " with a value of " << ret.first->second << '\n';
	}


	tests << "  Swap TESTS\n";
	ft::map<int, char>::iterator it_testMemory = testMap2.begin();
	tests << "begin map 2 before swap: " << it_testMemory->first << ", " << it_testMemory->second << std::endl;
	tests << "Size map 2 before swap: " << testMap2.size() << std::endl;
	tests << "Map 2 before swap: ";
	printTree(testMap2, tests);
	ft::map<int, char>::iterator it_testMemory2 = testMap3.begin();
	tests << "begin map 3 before swap: " << it_testMemory2->first << ", " << it_testMemory2->second << std::endl;
	tests << "Size map 3 before swap: " << testMap3.size() << std::endl;
	tests << "Map 3 before swap:";
	printTree(testMap3, tests);

	testMap2.swap(testMap3);
	tests << "begin map 2 after swap: " << it_testMemory->first << ", " << it_testMemory->second << std::endl;
	tests << "Size map 2 after swap: " << testMap2.size() << std::endl;
	tests << "Map 2 after swap: ";
	printTree(testMap2, tests);

	tests << "begin map 3 after swap: " << it_testMemory2->first << ", " << it_testMemory2->second << std::endl;
	tests << "Size map 3 after swap: " << testMap3.size() << std::endl;
	tests << "Map 3 after swap:";
	printTree(testMap3, tests);


	tests << "Value Compare TEST:\n";
	ft::map<char,int> mymap;
	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;
	ft::pair<char,int> highest = *mymap.rbegin();
	for(ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++){
		tests << std::boolalpha << mymap.value_comp()(*it, highest);
		tests << " " << it->first << " => " << it->second << '\n';
	}



	tests << "Operations TESTS" << std::endl;
	tests << "Testmap 3 contains: ";
	for (ft::map<int, char>::iterator it = testMap3.begin(); it != testMap3.end(); it++) {
		tests << it->first << " = " << it->second << "; ";
	}
	ft::map<int, char>::iterator test_it = testMap3.find(10);  			//should be in tree
	tests << "found key " << test_it->first << " value: " << test_it->second << std::endl;
	test_it = testMap3.find(-1);  //is not in this tree
	if(test_it != testMap3.end())
		tests << "found key " << test_it->first << " value: " << test_it->second << std::endl;
	else
		tests << "key was not found\n";
	ft::map<int, char>::const_iterator test_const_it = testMap3.find(10);
	tests << "found key " << test_const_it->first << " value: " << test_const_it->second << std::endl;

	tests << "is key in map: " << testMap3.count(10) << std::endl;
	tests << "is key in map: " << testMap3.count(-1) << std::endl;

	test_it = testMap3.lower_bound(25);
	tests << "lowerbound of key " << test_it->first << " value: " << test_it->second << std::endl;
		test_it = testMap3.lower_bound(32);
	tests << "lowerbound of key " << test_it->first << " value: " << test_it->second << std::endl;
		test_const_it = testMap3.lower_bound(32);
	tests << "compare it and const it: " << std::boolalpha << (test_it == test_const_it) << std::endl;
	tests << "lowerbound of key " << test_const_it->first << " value: " << test_const_it->second << std::endl;
	test_it = testMap3.lower_bound(80);
	if(test_it != testMap3.end())
		tests << "lowerbound of key " << test_it->first << " value: " << test_it->second << std::endl;
	else
		tests << "No lowerbound for this key\n";

	test_it = testMap3.upper_bound(25);
	tests << "upper_bound of key " << test_it->first << " value: " << test_it->second << std::endl;
		test_it = testMap3.upper_bound(32);
	tests << "upper_bound of key " << test_it->first << " value: " << test_it->second << std::endl;
	test_it = testMap3.upper_bound(80);
	if(test_it != testMap3.end())
		tests << "upper_bound of key " << test_it->first << " value: " << test_it->second << std::endl;
	else
		tests << "No upper_bound for this key\n";

	
	ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator> pair_of_its = testMap3.equal_range(25);
	tests << "range from key " << pair_of_its.first->first << " to key: " << pair_of_its.second->first << std::endl;
	pair_of_its = testMap3.equal_range(32);		//key not in tree, so range 0
	tests << "range from key " << pair_of_its.first->first << " to key: " << pair_of_its.second->first << std::endl;
	ft::pair<ft::map<int, char>::const_iterator, ft::map<int, char>::const_iterator> pair_of_const_its = testMap3.equal_range(7);
	tests << "range from key " << pair_of_const_its.first->first << " to key: " << pair_of_const_its.second->first << std::endl;


	tests << "Assignment operator and Copy constructor" << std::endl;
	tests << "Map 2 before assignment\n";
	printTree(testMap2, tests);
	tests << "Map 3 before assignment\n";
	printTree(testMap3, tests);
	testMap3 = testMap2;
	tests << "Map 3 after assignment\n";
	printTree(testMap3, tests);
	testMap3.erase(10);
	tests << "Map 3 after erase\n";
	printTree(testMap3, tests);
	tests << "element map 2 has not been erased\n";
	printTree(testMap2, tests);

	testMap2[30] = 'o'; testMap2[-90] = 'H'; testMap2[6000] = 'p';
	ft::map<int, char> copyMap(testMap2);
	tests << "Map 2 contains\n";
	printTree(testMap2, tests);
	tests << "CopyMap contains\n";
	printTree(copyMap, tests);
	copyMap.erase(-90);
	tests << "CopyMap after erase\n";
	printTree(copyMap, tests);
	tests << "Map 2 not affected by erase\n";
	printTree(testMap2, tests);


	testMap.clear();
	tests << std::boolalpha << "Map empty after clear: " << testMap.empty() << '\n';

	//test_comp();
	erase_test();

}

