#include "../stdafx.h"

#ifndef REFERENCE_MEMBER_1_H
#define REFERENCE_MEMBER_1_H

class MemberType{ };
class ReferenceMember{
private:
	MemberType* ptr1;
	MemberType* ptr2;
public:
	ReferenceMember() :ptr1(new MemberType), ptr2(new MemberType){ }
	ReferenceMember(ReferenceMember const& rm) :ptr1(rm.ptr1), ptr2(rm.ptr2){ }
	~ReferenceMember(){ //ֻ���ڹ��캯���ɹ�ִ�е�����£�������������ִ�У��ͷ���Դ��������캯��ִ��ʧ�ܣ���������������ִ�У���ô�Ѿ�����õĶ����޷�������Դ�ͷš�
		delete ptr1;
		delete ptr2;
	}

    //��ֵ�������
	ReferenceMember const& operator=(ReferenceMember const& x){
		delete ptr1;
		delete ptr2;
		*ptr1 = *x.ptr1;
		*ptr2 = *x.ptr2;
		return *this;
	}
};

#endif//REFERENCE_MEMBER_1_H