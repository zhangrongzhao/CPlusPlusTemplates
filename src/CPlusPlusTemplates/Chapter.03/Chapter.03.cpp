// Chapter.03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <deque>
#include <string>
#include <cstdlib>

#include "basics\stack3.h"

int _tmain(int argc, _TCHAR* argv[])
{
	try{
		//int stack:use the default vector container to manage the elements.
		Stack<int> intStack;
	    
		//double栈，它使用std::deque来管理元素
		Stack<double, std::deque<double>> dblStack;

		intStack.push(7);
		std::cout << intStack.top() << std::endl;

		dblStack.push(42.42);
		std::cout << dblStack.top() << std::endl;
		dblStack.pop();
		dblStack.pop();

	}
	catch(std::exception const& ex){
		std::cerr << "Exception:" << ex.what() << std::endl;
		return EXIT_FAILURE;
	}
}

