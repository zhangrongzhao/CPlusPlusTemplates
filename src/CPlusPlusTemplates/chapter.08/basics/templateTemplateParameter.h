#include "../stdafx.h"
#include <deque>

//template<template<typename X> 
//         class C>
//void f(C<int>* p);

//template<template<typename X>union C>//不支持union模板参数，编译不能通过
//void f(C<int>* p);

//template<template<typename X>struct C>//不支持struct模板参数，编译不能通过。
//void f(C<int>* p);


////类模板的模板参数列表中，类模板参数可以具有缺省模板实参。
//template<template<typename T,typename A=MyAllocator> 
//         class Container
//>
//class Adaptation{
//	Container<int> storage;//不提供第二个参数,使用提供的默认参数。隐式等同于Container<int,MyAllocator>
//};


//template<template<typename T,T*> 
//         class Buf
//>
//class Lexer{
//	static char storage[5];
//	Buf<char, &Lexer<Buf>::storage[0]> buf;
//};


//template<template<typename T> 
//         class List
//>
//class Node{
//	static T* storage;//类模板的模板参数列表中，作为参数的类模板，它的模板参数仅在类模板参数内部使用，对外部的类模板不可见。不能使用。
//
//};

//
////类模板作为模板参数，它的模板参数不会被外围定义的类模板使用，可以省略不写。
//template<template<typename,typename=MyAllocator> 
//         class Container
//>
//class Adaptation{
//	Container<int> storage;
//};

////缺省模板实参，不能依赖于自身的参数，只能依赖于前面的参数。
//template<typename T,
//         typename Allocator=std::allocator<T>
//>
//class List;

//template<typename T1,
//		 typename T2,
//		 typename T3,
//		 typename T4,
//		 typename T5=char
//>
//class Quintuple;
//
//
//template<typename T1,
//	typename T2,
//	typename T3,
//	typename T4 = char,
//	typename T5
//>
//class Quintuple;
//
//template<typename T1 = char,
//	typename T2 ,
//	typename T3,
//	typename T4,
//	typename T5
//>
//class Quintuple;

//
////缺省实参不能重复声明
//template<typename T=void>
//class Value;
//
//template<typename T=void>
//class Value;