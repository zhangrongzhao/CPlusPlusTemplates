#include "../stdafx.h"
#include "baseMemberPair.h"


class Empty{
public:
	typedef int Int32;//typedef 成员并不会使类变成非空
};
/*
class EmptyToo :public Empty {

};

class NonEmpty :public Empty,public EmptyToo{


};

template<typename T1,typename T2>
class MyClass:private T1,private T2{//1.原生类型(int,union)2.T1,T2类型相同时3.修改了基类，改变了基类接口。
private:
	T1 a;
	T2 b;
};

void test(){
	MyClass<Empty, EmptyToo> oMyClass;//之一为空类，浪费一个字节的内存。
}
*/

/*
template<typename CustomClass>
class Optimizable{
private:
	CustomClass info;//可能为空
	void* storage;//
}
*/

template<typename CustomClass>
class Optimizable{
public:
	BaseMemberPair<CustomClass, void*> info_and_storage;
};

