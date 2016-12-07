#include "../stdafx.h"

#ifndef HOLDER_FAULT_H
#define HOLDER_FAULT_H
#include "Holder.h"
//Holder�ľ���
class Something{ };
void read_something(Something*){}

////ʹ����ָͨ����д��봫����
//Something* load_something(){
//	Something* result = new Something;
//	read_something(result);//λ��1������ָͨ�봫�ݸ�read_something.
//	return result;//λ��2������ָͨ�뷵�ظ��ⲿ��
//}

//����Holder���и���
Something* load_something(){
	//Something* result = new Something;
	Holder<Something> result(new Something);
	read_something(&(*result));//λ��1������ָͨ�봫�ݸ�read_something.

	//Something* ret = result.operator->();//��ʾ���ã���һ��Σ�յĲ�����
	//result.release();//������ָͨ��֮ǰ��Holder�ͷŶ�������Ȩ����ֹHolder������������ʱ�������������

	return result.release();//λ��2������ָͨ�뷵�ظ��ⲿ��
}

//ת������Ȩ
void test_Transfer_owner(){
	Holder<Something> h1(new Something);
	Holder<Something> h2(h1.release());
}

#endif//HOLDER_FAULT_H