#include "../stdafx.h"

#ifndef RESOURCE_ACQUISITION_IS_INITIALIZATION
#define RESOURCE_ACQUISITION_IS_INITIALIZATION
#include "Holder.h"

//void do_something(){
//   //��ȡ��Դ
//	RES1* res1 = acquire_resource_1();
//	RES2* res2 = acquire_resource_2();
//
//	//�ͷ���Դ
//	release_resource_2(res2);
//	release_resource_1(res1);
//}

//void do_something(){
//    //��ȡ��Դ
//	Holder<RES1, ...> res1(acquire_resource_1());
//	Holder<RES2, ...> res2(acquire_resource_2());
//
//	//����ʵ�����쳣��ȫ�ԡ�
//}

////Holder�ľ���
////Holder���ܽ�����е�����
//Something* load_something(){
//	Something* result = new Something;
//	read_something(result);//��ָͨ����Ϊʵ��
//	return result;//���ص�Ҳ��һ����ָͨ�롣
//}
////ʹ��Holderʵ���쳣��ȫ��
//Something* load_something(){
//	Holder<Something> result(new Something());
//	read_something(result.get_pointer());	
//	return result.release();
//}

#endif//RESOURCE_ACQUISITION_IS_INITIALIZATION