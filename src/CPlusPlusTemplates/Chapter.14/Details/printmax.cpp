#include "stdafx.h"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include "DynamicPolymorphism_Bridge.h"

/*
template<typename T>
void print_max(T const& collection){
    //声明一个局部的容器迭代器
	typename T::const_iterator pos;

	//计算出最大值的位置
	pos = standard::max_element(collection.begin(),collection.end());

	//输出最大元素的值
	if (pos != collection.end()){
		std::cout << *pos << std::endl;
	}
	else{
		std::cout << "empty" << std::endl;
	}
}

class MyClass{};

void test_print_max(){
	//standard::vector<MyClass> c1;
	//standard::List<MyClass> c2;

}
*/
