#include "../stdafx.h"

extern "C++" template<typename T>//默认情况的标准链接,默认情况下可以不写
void normal();

//extern "C" template<typename T>
//void invalid();
//
//extern "Xroma" template<typename T>
//void xroma_link();

template<typename T>
void external();//作为一个声明，引用位于其他文件的相同名称的实体。即引用位于其他文件的external()函数模板，也称为前置声明。

template<typename T>
static void internal();//与其他文件中具有相同名称的模板没有关系，即不是外部链接。
