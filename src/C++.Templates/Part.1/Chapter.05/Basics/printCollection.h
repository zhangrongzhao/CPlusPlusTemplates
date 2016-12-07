#include "../stdafx.h"

#ifndef PRINT_COLLECTION_H
#define PRINT_COLLECTION_H

#include <iostream>
#include <bitset>
template<typename T>
void printCollection(T const& collection){
	typename T::const_iterator pos;//用于collection的迭代器
	typename T::const_iterator end(collection.end());//结束位置

	for (pos = collection.begin(); pos != end;++pos){
		std::cout << *pos << "";
	}
	std::cout << std::endl;
}

//class stlContainer{
//	typedef ... iterator;//读写迭代器
//	typedef ... const_iterator;//只读迭代器
//};

////相似的构造
//template<int N>
//void printBitset(std::bitset<N> const& bs){
//	std::cout << bs.template to_string<char,char_trait<char>,allocator<char> >();//bs是依赖于模板参数N的构造，.template告知编译器to_string是依赖于模板参数N的对象bs的成员函数模板。
//}


template<typename T>
class Base{
public:
	exit();
};

template<typename T>
class Derived:Base<T>{
public:
	void foo(){
		//Base<T>::exit();
		this->exit();//使用Base<T>,或者this->限定对成员函数的访问。
	}
}





#endif//PRINT_COLLECTION_H