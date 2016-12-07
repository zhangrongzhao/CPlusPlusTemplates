#include "../stdafx.h"

#ifndef REFERENCE_MEMBER_1_H
#define REFERENCE_MEMBER_1_H

class MemType{};

class RefMembers{
private:
	MemType* ptr1;
	MemType* ptr2;
public:
	//缺省构造函数
	//-如果第二个new操作抛出异常的话，将会导致资源泄露
	RefMembers() :ptr1(new MemType()),ptr2(new MemType()){}

	//拷贝构造函数
	//-如果第二个new操作抛出异常的话，将会导致资源泄露
	RefMembers(RefMembers const& x) :ptr1(new MemType(*x.ptr1)), ptr2(new MemType(*x.ptr2)){}

	//赋值运算符
	const RefMembers& operator=(RefMembers const& x){
		*ptr1 = *x.ptr1;
		*ptr2 = *x.ptr2;
		return *this;
	}

	//析构函数
	~RefMembers(){
		delete ptr1;
		delete ptr2;
	}
};

#endif//REFERENCE_MEMBER_1_H