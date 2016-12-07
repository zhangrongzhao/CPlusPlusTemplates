#include "../stdafx.h"

#ifndef RESOURCE_ACQUISITION_IS_INITIALIZATION
#define RESOURCE_ACQUISITION_IS_INITIALIZATION
#include "Holder.h"

//void do_something(){
//   //获取资源
//	RES1* res1 = acquire_resource_1();
//	RES2* res2 = acquire_resource_2();
//
//	//释放资源
//	release_resource_2(res2);
//	release_resource_1(res1);
//}

//void do_something(){
//    //获取资源
//	Holder<RES1, ...> res1(acquire_resource_1());
//	Holder<RES2, ...> res2(acquire_resource_2());
//
//	//代码实现了异常安全性。
//}

////Holder的局限
////Holder不能解决所有的问题
//Something* load_something(){
//	Something* result = new Something;
//	read_something(result);//普通指针作为实参
//	return result;//返回的也是一个普通指针。
//}
////使用Holder实现异常安全性
//Something* load_something(){
//	Holder<Something> result(new Something());
//	read_something(result.get_pointer());	
//	return result.release();
//}

#endif//RESOURCE_ACQUISITION_IS_INITIALIZATION