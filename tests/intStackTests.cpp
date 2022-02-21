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
	#include "../stack.hpp"
	//#include "../vector.hpp"
#endif



void printStack(ft::stack<int> stack, std::ofstream& tests)
{
	tests << "(" << stack.size() << " elements)\n";

	while(!stack.empty()){
		tests << stack.top() << " ";
		stack.pop();
	}
	tests << '\n';
}


void intStackTests(std::ofstream& tests){

	tests << "--- INT STACK GENERAL --" << std::endl;
	ft::stack<int> testStack;

	tests << "is empty?		" << testStack.empty() << std::endl;
	for(int i = 0; i < 30; i++){
		testStack.push(i);
	}
	tests << "is empty?		" << testStack.empty() << std::endl;
	printStack(testStack, tests);
	tests << "size			" << testStack.size() << std::endl;
	tests << "last element		" << testStack.top() << std::endl;
	tests << "as const		" << static_cast<const ft::stack<int> >(testStack).top() << std::endl;


	testStack.pop();
	tests << "vector pop_back:	";
	printStack(testStack, tests);


	tests << "--- TEST COPY STACK --" << std::endl;
	ft::stack<int> copyVec(testStack);

	tests << "is empty?		" << copyVec.empty() << std::endl;
	printStack(testStack,tests);
	tests << "size			" << copyVec.size() << std::endl;
	tests << "last element		" << copyVec.top() << std::endl;
	tests << "as const		" << static_cast<const ft::stack<int> >(copyVec).top() << std::endl;


	copyVec.pop();
	tests << "vector pop_back:	";
	printStack(copyVec, tests);
}
