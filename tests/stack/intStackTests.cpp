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
	#include "../../Containers/stack.hpp"
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

void printStackTerminal(ft::stack<int> stack)
{
	std::cout << "(" << stack.size() << " elements)\n";

	while(!stack.empty()){
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << '\n';
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
	tests << "vector after pop_back:	";
	printStack(copyVec, tests);
	copyVec.pop();
	copyVec.push(10000);
	printStack(copyVec, tests);
	printStack(testStack, tests);

	tests << "rl operators testing\n";
	tests << "is equal			" << (testStack == copyVec) << std::endl;
	tests << "is not equal			" << (testStack != copyVec) << std::endl;
	tests << "is smaller			" << (copyVec < testStack) << std::endl;
	tests << "is bigger			" << (copyVec > testStack) << std::endl;
	tests << "is smaller or equal		" << (copyVec<= testStack) << std::endl;
	tests << "is bigger or equal		" << (testStack >= testStack) << std::endl;
}
