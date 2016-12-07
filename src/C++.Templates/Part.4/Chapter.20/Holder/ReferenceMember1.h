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
	~ReferenceMember(){ //只有在构造函数成功执行的情况下，析构函数才能执行，释放资源。如果构造函数执行失败，该析构函数不能执行，那么已经构造好的对象，无法进行资源释放。
		delete ptr1;
		delete ptr2;
	}

    //赋值运算符：
	ReferenceMember const& operator=(ReferenceMember const& x){
		delete ptr1;
		delete ptr2;
		*ptr1 = *x.ptr1;
		*ptr2 = *x.ptr2;
		return *this;
	}
};

#endif//REFERENCE_MEMBER_1_H