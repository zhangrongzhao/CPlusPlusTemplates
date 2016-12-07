#include "../stdafx.h"

#ifndef LAZY_H
#define LAZY_H
//template<typename T>
//class Safe{};
//
//template<int N>
//class Danger{
//public:
//	typedef char Block[N];//如果N<0的话，将会出错。
//};
//
//template<typename T,int N>
//class Tricky{
//public:
//	virtual ~Tricky(){ }
//	//void no_body_here(Safe<T>=3);
//	void inclass(){
//		Danger<N> no_boom_yet;
//	}
//
//	//void error(){ Danger<0> boom; }//
//	//void unsafe(T(*p)[N]);
//
//	T operator->();
//
//	//virtual Safe<T> suspect(){ return *this; };//
//
//	struct Nested{
//		Danger<N> pfew;
//	};
//
//	union{
//		int align;
//		Safe<T> anonymous;
//	};
//};
//
//void test(){
//	Tricky<int, 0> ok;
//}

#endif//LAZY_H

