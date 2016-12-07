#include "../stdafx.h"

#ifndef TYPENAME_H
#define TYPENAME_H

//typename:模板内部的标识符可是以一个类型

template<typename T>
class MyClass{
private:
	typename T::SubType* ptr;//SubType是定义于T内部的一种类型。ptr是指向T::SubType类型的指针。如果不使用typename关键字，SubType被视为T类型的静态成员。
};

#endif//TYPENAME_H