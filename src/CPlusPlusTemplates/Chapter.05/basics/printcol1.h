#include "../stdafx.h"
#include <iostream>

//打印STL容器的元素
template<typename T>
void printcol1(T const& col1){
	typename T::const_iterator pos;//用于迭代col1的迭代器
	typename T::const_iterator end(col1.end());//结束位置

	for (pos = col1.begin(); pos != end;++pos){
		std::cout << *pos << " ";
	}
	std::cout << std::endl;
}

//class stlcontainer{
//	//typedef ... iterator//可读写的迭代器
//	//typedef ... const_iterator//只能读访问的迭代器
//};

//template<int N>
//void printBitset(std::bitset<N> const& bs){
//	//bs是依赖于模板参数N的构造
//	std::cout << bs.template to_string<char.char_traits<char>,allocator<char>>();
//}
