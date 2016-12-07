#include "../stdafx.h"

#ifndef ELEMENT_TYPE_H
#define ELEMENT_TYPE_H

#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <typeinfo>

//C容器类型定义了一个value_type.
template<typename C>
class ElmentT{
public:
	typedef typename C::value_type Type;
};

template<typename T>
class ElementT<std::vector<T>>{
public:
	typedef T Type;
};

template<typename T>
class ElementT<std::list<T>>{
public:
	typedef T Type;
};

template<typename T>
class ElementT<std::vector<T>> {
public:
	typedef T Type;
};



template<typename ContainerT>
void print_element_type(ContainerT const& c){
	std::cout << typeid(typename ElementT<ContainerT>::Type).name() << std::endl;;
}


#endif//ELEMENT_TYPE_H

