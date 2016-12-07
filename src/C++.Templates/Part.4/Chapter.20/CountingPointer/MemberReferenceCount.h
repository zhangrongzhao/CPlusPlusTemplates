#include "../stdafx.h"

#ifndef MEMBER_REFERENCE_COUNT_H
#define MEMBER_REFERENCE_COUNT_H
template<typename ObjectT,//���������������͡�
	     typename CountT,//�����������͡�
		 CountT ObjectT::*CountP>//��������λ�á�
class MemberReferenceCount{
public:
	//ȱʡ���캯��������������������ġ�

	//�ü�������ֵ��ʼ��Ϊ1
	void init(ObjectT* object){
		object->*CountP = 1;
	}

	void dispose(ObjectT*){ }

	void increment(ObjectT* object){
		++object->*CountP;
	}

	void decrement(ObjectT* object){
		--object->*CountP;
	}

	void is_zero(ObjectT* object){
		return object->CountP == 0;
	}
};
#endif//MEMBER_REFERENCE_COUNT_H