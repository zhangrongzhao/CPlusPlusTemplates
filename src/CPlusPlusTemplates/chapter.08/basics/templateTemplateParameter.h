#include "../stdafx.h"
#include <deque>

//template<template<typename X> 
//         class C>
//void f(C<int>* p);

//template<template<typename X>union C>//��֧��unionģ����������벻��ͨ��
//void f(C<int>* p);

//template<template<typename X>struct C>//��֧��structģ����������벻��ͨ����
//void f(C<int>* p);


////��ģ���ģ������б��У���ģ��������Ծ���ȱʡģ��ʵ�Ρ�
//template<template<typename T,typename A=MyAllocator> 
//         class Container
//>
//class Adaptation{
//	Container<int> storage;//���ṩ�ڶ�������,ʹ���ṩ��Ĭ�ϲ�������ʽ��ͬ��Container<int,MyAllocator>
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
//	static T* storage;//��ģ���ģ������б��У���Ϊ��������ģ�壬����ģ�����������ģ������ڲ�ʹ�ã����ⲿ����ģ�岻�ɼ�������ʹ�á�
//
//};

//
////��ģ����Ϊģ�����������ģ��������ᱻ��Χ�������ģ��ʹ�ã�����ʡ�Բ�д��
//template<template<typename,typename=MyAllocator> 
//         class Container
//>
//class Adaptation{
//	Container<int> storage;
//};

////ȱʡģ��ʵ�Σ���������������Ĳ�����ֻ��������ǰ��Ĳ�����
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
////ȱʡʵ�β����ظ�����
//template<typename T=void>
//class Value;
//
//template<typename T=void>
//class Value;