#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>

void	stringVectorTests(std::ofstream& tests);
void	intVectorTests(std::ofstream& tests);
void	intStackTests(std::ofstream& tests);
void	stringStackTests(std::ofstream& tests);
void	mapTests(std::ofstream& tests);
void	setTests(std::ofstream& tests);
void 	speedTestMap();
void	speedTestVector();

#if STD_CONTAINER
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
	std::string file = "TestOutput/std_output";
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#include "set.hpp"
	std::string file = "TestOutput/my_output";
#endif


class Timer{
public:
	Timer(std::string title) : _title(title){
		_startTimepoint = std::chrono::high_resolution_clock::now();
	}
	~Timer(){
		Stop();
	}

	void Stop(){
		std::chrono::time_point< std::chrono::high_resolution_clock> _endTimepoint = std::chrono::high_resolution_clock::now();
		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(_startTimepoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(_endTimepoint).time_since_epoch().count();
	
		long long duration = end - start;
		double ms = duration * 0.001;
		std::cout << _title << duration << "us (" << ms << "ms)\n\n";
	}

private:
	std::chrono::time_point< std::chrono::high_resolution_clock > _startTimepoint;
	std::string _title;
};

int main(){
	std::ofstream tests(file, std::ios_base::trunc);

	// {
	// 	Timer timer("Vector speed: ");
	// 	speedTestVector();
	// }
	
	// {
	// 	Timer timer("string vector speed: ");
	// 	stringVectorTests(tests);
	// }
	
	// {
	// 	Timer timer("int stack speed: ");
	// 	intStackTests(tests);
	// }

	// {
	// 	Timer timer("string stack speed: ");
	// 	stringStackTests(tests);
	// }

	// {
	// 	Timer timer("Map speed: ");
	// 	speedTestMap();
	// }

	// {
	// 	Timer timer("set speed: ");
	// 	setTests(tests);
	// }

	//*****************   GENERAL FUNCTIONALITY TESTS   ******************
	stringVectorTests(tests);
	intVectorTests(tests);
	intStackTests(tests);
	stringStackTests(tests);
	mapTests(tests);
	setTests(tests);

	//system("leaks ft_containers");

}









//************************** SUBJECT MAIN ************************************



// #include <iostream>
// #include <string>
// #include <deque>
// #if 1
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include "map.hpp"
// 	#include "stack.hpp"
// 	#include "vector.hpp"
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 		std::cout << "all went well\n";
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 100; i++)
// 	{
// 		int access = rand();

// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }