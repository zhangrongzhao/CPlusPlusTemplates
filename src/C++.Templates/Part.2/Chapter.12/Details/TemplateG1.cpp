#include "stdafx.h"

//基本模板
template<typename T>
int g(T, T x = 42){ return x; }


//特化:这里只声明不定义，告知编译器不再使用基本模板，使用特化模板。也避免在不同单元对特化模板重复定义。
template<>
int g(int, int);
