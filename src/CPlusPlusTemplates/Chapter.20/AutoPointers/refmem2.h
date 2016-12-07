#include "../stdafx.h"

#ifndef REFERENCE_MEMBER_2_H
#define REFERENCE_MEMBER_2_H
#include "Holder1.h"
#include <stdexcept>
class MemType{};

class RefMembers{
private:
	Holder<MemType> ptr1;//Holder�����õĳ�Ա
	Holder<MemType> ptr2;//
public:
	//Ĭ�Ϲ��캯��
	//Holder�����õĳ�Ա��������Holder������ͷŶ��ͷš����������ڱ����ڳ�ʼ���ڼ��׳��쳣�����µ���Դй¶��
	RefMembers():ptr1(new MemType()),ptr2(new MemType()){ }

	//�������캯��
	//Holder�����õĳ�Ա��������Holder������ͷŶ��ͷš����������ڱ����ڳ�ʼ���ڼ��׳��쳣�����µ���Դй¶��
	RefMembers(RefMembers const& x):ptr1(new MemType(*x.ptr1)),ptr2(new MemType(*x.ptr2)){ }

	//��ֵ�����
	const RefMembers& operator=(RefMembers const& x){
		*ptr1 = *(x.ptr1);
		*ptr2 = *(x.ptr2);
		return *this;
	}

	//����Ҫ��������
	//ȱʡ����������������ptr1��ptr2ɾ�����������õĶ���
};


#endif//REFERENCE_MEMBER_2_H