// Chapter.17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "metaprogramming\loop2.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {1,2,3};
	int b[] = {5,6,7};

	std::cout << "dot_product(3,a,b) = " << dot_product<3>(a, b) << std::endl;
	std::cout << "dot_product(3,a,a) = " << dot_product<3>(a, a) << std::endl;
	
	return 0;
}

