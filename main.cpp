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

	{
		Timer timer("int vector speed: ");
		intVectorTests(tests);
	}
	
	{
		Timer timer("string vector speed: ");
		stringVectorTests(tests);
	}
	
	{
		Timer timer("int stack speed: ");
		intStackTests(tests);
	}

	{
		Timer timer("string stack speed: ");
		stringStackTests(tests);
	}

	{
		Timer timer("map speed: ");
		mapTests(tests);
	}

	{
		Timer timer("set speed: ");
		setTests(tests);
	}

	//system("leaks ft_containers");

	// int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	// int* ret = std::find(&arr[0], &arr[9], 6);
	// std::cout << *ret << std::endl;

}
