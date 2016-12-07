#include "../stdafx.h"

#ifndef REFERENCE_MEMBER_1_H
#define REFERENCE_MEMBER_1_H

class MemType{};

class RefMembers{
private:
	MemType* ptr1;
	MemType* ptr2;
public:
	//ȱʡ���캯��
	//-����ڶ���new�����׳��쳣�Ļ������ᵼ����Դй¶
	RefMembers() :ptr1(new MemType()),ptr2(new MemType()){}

	//�������캯��
	//-����ڶ���new�����׳��쳣�Ļ������ᵼ����Դй¶
	RefMembers(RefMembers const& x) :ptr1(new MemType(*x.ptr1)), ptr2(new MemType(*x.ptr2)){}

	//��ֵ�����
	const RefMembers& operator=(RefMembers const& x){
		*ptr1 = *x.ptr1;
		*ptr2 = *x.ptr2;
		return *this;
	}

	//��������
	~RefMembers(){
		delete ptr1;
		delete ptr2;
	}
};

#endif//REFERENCE_MEMBER_1_H