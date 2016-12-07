#include "stdafx.h"

//template<int N>
//class X{
//public:
//	typedef int I;
//	void f(int){ }
//};
//
//template<int N>
//void fppm(void (X<N>::*p)(typename X<N>::I));
//
//void test(){
//	fppm(&X<33>::f);
//}
//
//template<typename T>
//void f(T,T);
//
//void(*pf)(char, char) = &f;
//
//
//class S{
//public:
//	template<typename T, int N> operator T[N]&();
//};