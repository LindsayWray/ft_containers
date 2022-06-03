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
void 	speedTestSet();
void	speedTestVector();

#if STD_CONTAINER
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
	std::string file = "TestOutput/std_output";
#else
	#include "Containers/map.hpp"
	#include "Containers/stack.hpp"
	#include "Containers/vector.hpp"
	#include "Containers/set.hpp"
	std::string file = "TestOutput/my_output";
#endif


class Timer {
public:
	Timer(std::string title) : _title(title) { _startTimepoint = std::chrono::high_resolution_clock::now(); }

	~Timer() { Stop(); }

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

int main() {
	std::ofstream tests(file, std::ios_base::trunc);

	// {
	// 	Timer timer("Vector speed: ");
	// 	speedTestVector();
	// }
	// {
	// 	Timer timer("Map speed: ");
	// 	speedTestMap();
	// }
	// {
	// 	Timer timer("Set speed: ");
	// 	speedTestSet();
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
