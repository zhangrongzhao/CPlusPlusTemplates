#include "../stdafx.h"
#include <typeinfo>
#include <iostream>

template<typename T>
inline void nonref(T x){
	std::cout << "x in nonref(T):" << typeid(x).name() << std::endl;
}

template<typename T>
inline void ref(T const& x){
	std::cout << "x in ref(T const&):" << typeid(x).name() << std::endl;
}