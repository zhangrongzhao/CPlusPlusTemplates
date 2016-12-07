#include "../stdafx.h"

#ifndef ACQUIRE_RESOURCE_H
#define ACQUIRE_RESOURCE_H
#include "Holder.h"

class Resource1{ };
class Resource2{ };

Resource1* acquire_resource_1(){ }
Resource2* acquire_resource_2(){ }

void release_resource_1(Resource1*){ }
void release_resource_2(Resource2*){ }

void do_something_1(){

	Resource1* resource1 = acquire_resource_1();
	Resource2* resource2 = acquire_resource_2();
	//...如果出现异常，资源无法正确释放
	release_resource_2(resource2);
	release_resource_1(resource1);
}

//使用Holder实现异常安全性。
void do_something_2(){
	Holder<Resource1> resource1(acquire_resource_1());
	Holder<Resource2> resource2(acquire_resource_2());
}

#endif//ACQUIRE_RESOURCE_H