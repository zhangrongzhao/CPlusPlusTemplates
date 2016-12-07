
#include "stdafx.h"
#include "MemberFunctionPointer.h"

//void main(){
//
//	//普通成员函数调用
//	D obj;
//	obj.mf1();
//	obj.mf2();//进行指针调整
//}


//int main(){
//	D obj;
//	D* ptr = new D();
// 	call_memfun(obj,&D::mf1);
//	call_memfun(obj,&D::mf2);
//
//	//对成员函数指针进行强制类型转换，地址调整会发生改变。
//	void(D::*pmf_a)() = &D::mf2;//地址调整为+4个字节
//	void(B2::*pmf_b)() = (void(B2::*)())pmf_a;//又变成原来的地址，即地址调整为0
//
//	//成员函数指针取引用运算符：.*  ->*
//	(obj.*pmf_a)();//调用位于obj中的pmf所引用的成员函数
//	(ptr->*pmf_b)();//调用位于ptr指针所引用的对象的pmf_b所引用的成员函数。
//
//	//通过指针访问一个普通函数是一个一元操作
//	//(*ptr)();
//
//}

