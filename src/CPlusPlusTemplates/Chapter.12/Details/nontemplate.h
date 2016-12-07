#include "../stdafx.h"
#include <string>

template<typename T>
std::string f(T){
	return "Template";
}


std::string f(int&){
	return "NonTemplate";
}
