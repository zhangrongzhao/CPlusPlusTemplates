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

	//拷贝构造函数，使用Holder来正确释放资源。即使构造对象时ptr1成功，ptr2失败，ptr1仍然可以正常释放资源。
	ReferenceMember(ReferenceMember const& rm) :ptr1(new MemberType(*rm.ptr1)), ptr2(new MemberType(*rm.ptr2)){ }
	//~ReferenceMember(){ //只有在构造函数成功执行的情况下，析构函数才能执行，释放资源。如果构造函数执行失败，该析构函数不能执行，那么已经构造好的对象，无法进行资源释放。
	//	delete ptr1;
	//	delete ptr2;
	//}

	//赋值运算符：
	ReferenceMember const& operator=(ReferenceMember const& x){
		//delete ptr1;
		//delete ptr2;
		*ptr1 = *x.ptr1;
		*ptr2 = *x.ptr2;
		return *this;
	}
};

#endif//REFERENCE_MEMBER_2_H