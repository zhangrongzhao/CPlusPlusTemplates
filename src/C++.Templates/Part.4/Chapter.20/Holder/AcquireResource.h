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
	//...��������쳣����Դ�޷���ȷ�ͷ�
	release_resource_2(resource2);
	release_resource_1(resource1);
}

//ʹ��Holderʵ���쳣��ȫ�ԡ�
void do_something_2(){
	Holder<Resource1> resource1(acquire_resource_1());
	Holder<Resource2> resource2(acquire_resource_2());
}

#endif//ACQUIRE_RESOURCE_H