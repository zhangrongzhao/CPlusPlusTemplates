#include "../stdafx.h"

#ifndef NON_TEMPLATE_H
#define NON_TEMPLATE_H
#include <string>
#include <iostream>
template<typename T>
std::string f(T){
	return "Template;"
}

std::string f(int&){
	return "NonTemplate;";
}

void test(){
	int x = 7;
	std::cout << f(x) << std::endl;
}

#endif//NON_TEMPLATE_H