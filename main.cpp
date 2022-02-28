#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

void	stringVectorTests(std::ofstream& tests);
void	intVectorTests(std::ofstream& tests);
void	intStackTests(std::ofstream& tests);
void	stringStackTests(std::ofstream& tests);
void	mapTests(std::ofstream& tests);

#if STD_CONTAINER
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
	std::string file = "TestOutput/realVectorOutput";
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	std::string file = "TestOutput/myVectorOutput";
#endif


int main(){
	std::ofstream tests(file, std::ios_base::trunc);
	intVectorTests(tests);
	stringVectorTests(tests);

	intStackTests(tests);
	stringStackTests(tests);

	mapTests(tests);

	//system("leaks containers");

	// int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	// int* ret = std::find(&arr[0], &arr[9], 6);
	// std::cout << *ret << std::endl;

}
