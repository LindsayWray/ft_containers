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



void printStack(ft::stack<std::string> stack, std::ofstream& tests)
{
	tests << "(" << stack.size() << " elements)\n";

	while(!stack.empty()){
		tests << stack.top() << " ";
		stack.pop();
	}
	tests << '\n';
}


void stringStackTests(std::ofstream& tests){

	(void)tests;
	tests << "--- INT STACK GENERAL --" << std::endl;
	ft::stack<std::string> testStack;

	tests << "is empty?		" << testStack.empty() << std::endl;
	testStack.push("one");
	testStack.push("two");
	testStack.push("three");
	testStack.push("four");
	testStack.push("five");
	testStack.push("six");
	testStack.push("seven");
	testStack.push("eight");
	testStack.push("nine");
	testStack.push("ten");
	testStack.push("eleven");
	testStack.push("twelve");
	for(int i = 12; i < 20; i++){
		testStack.push("testing");
	}
	tests << "is empty?		" << testStack.empty() << std::endl;
	printStack(testStack, tests);
	tests << "size			" << testStack.size() << std::endl;
	tests << "last element		" << testStack.top() << std::endl;
	tests << "as const		" << static_cast<const ft::stack<std::string> >(testStack).top() << std::endl;



	tests << "--- TEST COPY STACK --" << std::endl;
	ft::stack<std::string> copyVec(testStack);

	tests << "is empty?		" << copyVec.empty() << std::endl;
	printStack(testStack, tests);
	tests << "size			" << copyVec.size() << std::endl;
	tests << "last element		" << copyVec.top() << std::endl;
	tests << "as const		" << static_cast<const ft::stack<std::string> >(copyVec).top() << std::endl;


	copyVec.pop();
	tests << "vector after pop_back:	";
	printStack(copyVec, tests);
	copyVec.pop();
	copyVec.push("hundred");
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