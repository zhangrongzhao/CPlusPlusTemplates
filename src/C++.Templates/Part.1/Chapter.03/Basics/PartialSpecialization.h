#include "../stdafx.h"

#ifndef PARTIAL_SPECIALIZATION_1_H
#define PARTIAL_SPECIALIZATION_1_H
/*类模板的局部特化*/

//基本模板
template<typename T1,typename T2>
class MyClass{  };

//partial specialization:局部特化
template<typename T>
class MyClass<T, T>{ };

template<typename T>
class MyClass<T,int>{ };

template<typename T>
class MyClass<T*, T*>{ };

template<typename T1,typename T2>
class MyClass<T1*,T2*>{ };
#endif//PARTIAL_SPECIALIZATION_1_H