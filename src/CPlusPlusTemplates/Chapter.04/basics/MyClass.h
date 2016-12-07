#include "../stdafx.h"

//primary template:基本模板
template<typename T1,typename T2>
class MyClass{};

//局部特化1：两个模板参数具有相同类型
template<typename T>
class MyClass <T,T> {};

//同类型指针的特化
template<typename T>
class MyClass <T*,T*> {};

//局部特化2：第二个模板参数类型是int
template<typename T>
class MyClass <T,int> {};

//局部特化2：两个模板参数都是指针类型
template<typename T1,typename T2>
class MyClass <T1*, T2*> {};