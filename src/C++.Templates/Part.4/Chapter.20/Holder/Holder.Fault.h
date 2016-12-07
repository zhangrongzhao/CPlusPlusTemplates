#include "../stdafx.h"

#ifndef HOLDER_FAULT_H
#define HOLDER_FAULT_H
#include "Holder.h"
//Holder的局限
class Something{ };
void read_something(Something*){}

////使用普通指针进行传入传出。
//Something* load_something(){
//	Something* result = new Something;
//	read_something(result);//位置1：将普通指针传递给read_something.
//	return result;//位置2：将普通指针返回给外部。
//}

//尝试Holder进行改造
Something* load_something(){
	//Something* result = new Something;
	Holder<Something> result(new Something);
	read_something(&(*result));//位置1：将普通指针传递给read_something.

	//Something* ret = result.operator->();//显示调用，是一种危险的操作。
	//result.release();//返回普通指针之前，Holder释放对象所有权。防止Holder析构函数调用时，将对象清除。

	return result.release();//位置2：将普通指针返回给外部。
}

//转移所有权
void test_Transfer_owner(){
	Holder<Something> h1(new Something);
	Holder<Something> h2(h1.release());
}

#endif//HOLDER_FAULT_H