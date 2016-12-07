#include "../stdafx.h"

#ifndef REFERENCE_MEMBER_2_H
#define REFERENCE_MEMBER_2_H
#include "Holder.h"
class MemberType{
public:
	MemberType(){ }
	MemberType(MemberType const&){}
};
class ReferenceMember{
private:
	Holder<MemberType> ptr1;
	Holder<MemberType> ptr2;
public:
	ReferenceMember() :ptr1(new MemberType), ptr2(new MemberType){ }

	//�������캯����ʹ��Holder����ȷ�ͷ���Դ����ʹ�������ʱptr1�ɹ���ptr2ʧ�ܣ�ptr1��Ȼ���������ͷ���Դ��
	ReferenceMember(ReferenceMember const& rm) :ptr1(new MemberType(*rm.ptr1)), ptr2(new MemberType(*rm.ptr2)){ }
	//~ReferenceMember(){ //ֻ���ڹ��캯���ɹ�ִ�е�����£�������������ִ�У��ͷ���Դ��������캯��ִ��ʧ�ܣ���������������ִ�У���ô�Ѿ�����õĶ����޷�������Դ�ͷš�
	//	delete ptr1;
	//	delete ptr2;
	//}

	//��ֵ�������
	ReferenceMember const& operator=(ReferenceMember const& x){
		//delete ptr1;
		//delete ptr2;
		*ptr1 = *x.ptr1;
		*ptr2 = *x.ptr2;
		return *this;
	}
};

#endif//REFERENCE_MEMBER_2_H