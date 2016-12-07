#include "../stdafx.h"

#ifndef CURIOUSLY_RECURRING_TEMPLATE_PATTERN_H
#define CURIOUSLY_RECURRING_TEMPLATE_PATTERN_H
//template<typename Derived>
//class CuriousBase{ };
//
//////派生类将本身作为模板参数传递给基类。
////class Cursious :public CuriousBase<Cursious>{ };
//
//template<typename T>
//class CuriousTemplate :public CuriousBase<CuriousTemplate<T> > {};
//
//template<template<typename> class Derived>
//class MoreCuriousBase{};
//
//template<typename T>
//class MoreCurious :public MoreCuriousBase<MoreCurious>{ };

#include <stddef.h>
#include <iostream>
template<typename CountedType>
class ObjectCounter{
private:
	static size_t count;
public:
	ObjectCounter(){
		++ObjectCounter<CountedType>::count;
	}

	ObjectCounter(ObjectCounter const& ){
		++ObjectCounter<CountedType>::count;
	}

public:
	static size_t live(){
		return ObjectCounter<CountedType>::count;
	}
};

template<typename CountedType>
size_t ObjectCounter<CountedType>::count = 0;

template<typename CharT>
class MyString :public ObjectCounter<MyString<CharT> >{};

void test_ObjectCounter(){
	MyString<char> s1, s2;
	MyString<wchar_t> ws;

	std::cout << "number of MyString<char>:" << MyString<char>::live() << std::endl;
	std::cout << "number of MyString<wchar_t>:" << ws.live() << std::endl;
}


#endif//CURIOUSLY_RECURRING_TEMPLATE_PATTERN_H