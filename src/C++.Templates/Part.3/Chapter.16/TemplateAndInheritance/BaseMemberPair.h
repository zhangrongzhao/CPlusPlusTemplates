#include "../stdafx.h"

#ifndef BASE_MEMBER_PAIR_H
#define BASE_MEMBER_PAIR_H
//�����֪һ��ģ�������Ȼ���࣬��ģ�������һ����Ա���ǿ��ࡣ���Խ���ECBO���ѿ���Ϊ�յ����Ͳ����͸ó�Ա��������

template<typename CustomClass>
class Optimizable{
private:
	//CustomClass info;
	//void* storage;
	BaseMemberPair<CustomClass, void*> info_and_storage;
};


template<typename Base,typename Member>
class BaseMemberPair:public Base,public Member{//BaseΪ��ʱ�����Եõ��Ż���
private:
	Member member;
public:
	BaseMemberPair(Base const& b,Member const& m) :Base(b), member(m){ }
	
	Base& first() const{ return *this; }
	Base const& first() const{ return *this; }

	Member& second() const(){ return this->member; }
	Member const& second() const(){ return this->member; }
};


#endif//BASE_MEMBER_PAIR_H