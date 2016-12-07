#include "stdafx.h"
#include <iostream>
#include "objectCounter.h"

template<typename charT>
class MyString :public ObjectCounter<MyString<charT>>{

};

void test_counter(){
	MyString<char> s1, s2;
	MyString<wchar_t> ws;

	std::cout << "number of MyString<char>: " << MyString<char>::live() << std::endl;

	std::cout << "number of MyString<wchar_t>:" << MyString<wchar_t>::live() << std::endl;
}