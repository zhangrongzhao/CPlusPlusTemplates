// Chapter.04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "basics\addvalue.h"


int _tmain(int argc, _TCHAR* argv[])
{
	try{
	   /*	Stack<int, 20> int20Stack;
		Stack<int, 40> int40Stack;
		Stack<std::string, 40>  string40Stack;

		int20Stack.push(7);
		std::cout << int20Stack.top() << std::endl;
		int20Stack.pop();

		string40Stack.push("hello");
		std::cout << string40Stack.top() << std::endl;
		string40Stack.pop();
		string40Stack.pop();*/

		//std::transform(source.begin(),source.end(),dest.begin(),(int (*)(int const&))addValue<int,5>);
	}
	catch (std::exception const& ex){
		std::cerr << "Exception:" << ex.what() << std::endl;
		return EXIT_FAILURE;
	}

	return 0;
}

