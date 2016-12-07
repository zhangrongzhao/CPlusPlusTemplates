#include "../stdafx.h"

#ifndef BASE_MEMBER_PAIR_H
#define BASE_MEMBER_PAIE_H
/*
  ǰ��������Base��Ȼ����,Member���Ͳ��ǿ���
  ���ý����BaseΪ����ʱ������������Empty Base Class Optamization.�ջ����Ż�
*/
template<typename Base,typename Member>
class BaseMemberPair :private Base{
private:
	Member member;
public:
	//���캯��
	BaseMemberPair(Base const& b,Member const& m):Base(b),Member(m){
	   
	}

	//ͨ��first()�����ʻ�������
	Base const& first() const{
		return (Base const&)*this;
	}

	Base& first(){
		return (Base&)*this;
	}

	//ͨ��second()�����ʻ���ĳ�Ա����
	Member const& second() const{
		return this->member;
	}

	Member& second(){
		return this->member;
	}
};


#endif//BASE_MEMBER_PAIR_H