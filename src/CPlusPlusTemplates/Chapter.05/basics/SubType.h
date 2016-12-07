#include "../stdafx.h"

template<typename T>
class MyClass{
public:
   //typeaname标示SubType为模板参数T的内部类型
   //如果SubType前不适用关键字typename,*会被认为是乘号，变成乘积表达式。
   typename T::SubType *pointer;
};