#include "../stdafx.h"

#ifndef BASE_MEMBER_PAIR_H
#define BASE_MEMBER_PAIR_H
//如果已知一个模板参数必然是类，该模板的另外一个成员不是空类。可以借助ECBO，把可能为空的类型参数和该成员合起来。

template<typename CustomClass>
class Optimizable{
private:
	//CustomClass info;
	//void* storage;
	BaseMemberPair<CustomClass, void*> info_and_storage;
};


template<typename Base,typename Member>
class BaseMemberPair:public Base,public Member{//Base为空时，可以得到优化。
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