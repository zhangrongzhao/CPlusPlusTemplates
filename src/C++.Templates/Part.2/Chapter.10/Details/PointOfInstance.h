#include "../stdafx.h"

#ifndef POINT_OF_INSTANCE_H
#define POINT_OF_INSTANCE_H

//����ģ���POI
//class MyInt{
//public:
//	MyInt(int i){}
//};
//
//MyInt operator-(MyInt const&);
//bool operator>(MyInt const&,MyInt const&);
//
//typedef MyInt Int;
//
//template<typename T>
//void f(T i){
//	if (i > 0){
//		g(-i);
//	}
//}
//
////(1)
//void g(Int){
//    //(2)
//	f<Int>(42);
//	//(3)
//}
////(4)

///*��ģ���ʵ������*/
//template<typename T>
//class S{
//public:
//	T m;
//};
//
////(5)
//unsigned long h(){
//    //(6)
//	return (unsigned long) sizeof(S<int>);
//	//(7)
//}
////(8)

////����ʵ����
//template<typename T>
//class S{
//public:
//	typedef int I;
//};
//
////(1)
//template<typename T>
//void f(){
//	S<char>::I var1 = 41;
//	typename S<T>::I var2 = 42;
//}
//
//int test(){
//	f<double>();
//}
////(2):(2a),(2b)


////��ʾʵ����
//template<typename T>
//void f(T) throw (T){ }
//
//template void f<int>(int) throw (int);
//template void f<>(float) throw (float);
//template void f(long) throw(long);
//template void f(char);
//
//template<typename T>
//class S{
//public:
//	void f(){};
//};
//
//template void S<int>::f();
//template class S<void>;



#endif//POINT_OF_INSTANCE_H