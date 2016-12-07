#include "../stdafx.h"

#ifndef BASE_MEMBER_PAIR_H
#define BASE_MEMBER_PAIE_H
/*
  前提条件：Base必然是类,Member类型不是空类
  后置结果：Base为空类时，编译器启用Empty Base Class Optamization.空基类优化
*/
template<typename Base,typename Member>
class BaseMemberPair :private Base{
private:
	Member member;
public:
	//构造函数
	BaseMemberPair(Base const& b,Member const& m):Base(b),Member(m){
	   
	}

	//通过first()来访问基类数据
	Base const& first() const{
		return (Base const&)*this;
	}

	Base& first(){
		return (Base&)*this;
	}

	//通过second()来访问基类的成员变量
	Member const& second() const{
		return this->member;
	}

	Member& second(){
		return this->member;
	}
};


#endif//BASE_MEMBER_PAIR_H