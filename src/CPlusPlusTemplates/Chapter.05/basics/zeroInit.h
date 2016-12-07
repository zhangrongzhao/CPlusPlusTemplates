#include "../stdafx.h"

//void foo(){
//	int x;//x没有初始化，具有一个不确定的值
//	int* ptr;//ptr指针未初始化，指向某块内存。（并非无所指）
//}


//template<typename T>
//void foo(){
//	T x;//如果T是内建类型，那么X本身是一个不确定的值。
//}

//template<typename T>
//void foo(){
//	T x = T();//如果T是内建类型，则调用其默认构造参数，初始化为0或者false。
//}

template<typename T>
class MyClass{
private:
	T x;
	T y;
public:
	MyClass():x(),y(){//调用x的默认构造函数进行初始化，内建类型对象也是如此。
	}
};
