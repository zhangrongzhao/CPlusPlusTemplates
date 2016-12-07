#include "../stdafx.h"
#include <iostream>
#include <typeinfo>
#include "myFirstDec.h"

template<typename T>
void print_typeof(T const& x){
	std::cout << typeid(x).name() << std::endl;
}