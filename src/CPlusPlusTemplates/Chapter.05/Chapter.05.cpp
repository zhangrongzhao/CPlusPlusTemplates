// Chapter.05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdexcept>
#include <iostream>
#include "basics\max5.h"

int _tmain(int argc, _TCHAR* argv[])
{
	try{
		 char const * const s1 = "apple";
		 char const * const s2 = "peach";
		 ::max(s1,s2);
	}
	catch (std::exception const& ex){
		std::cerr << "Exception:" << ex.what() << std::endl;
		//return EXIT_FAILURE;
	}
	return 0;
}

