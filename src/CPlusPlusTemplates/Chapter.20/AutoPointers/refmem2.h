#include "../stdafx.h"

#ifndef REFERENCE_MEMBER_2_H
#define REFERENCE_MEMBER_2_H
#include "Holder1.h"
#include <stdexcept>
class MemType{};

class RefMembers{
private:
	Holder<MemType> ptr1;//Holder所引用的成员
	Holder<MemType> ptr2;//
public:
	//默认构造函数
	//Holder所引用的成员，会随着Holder对象的释放而释放。这样有助于避免在初始化期间抛出异常而导致的资源泄露。
	RefMembers():ptr1(new MemType()),ptr2(new MemType()){ }

	//拷贝构造函数
	//Holder所引用的成员，会随着Holder对象的释放而释放。这样有助于避免在初始化期间抛出异常而导致的资源泄露。
	RefMembers(RefMembers const& x):ptr1(new MemType(*x.ptr1)),ptr2(new MemType(*x.ptr2)){ }

	//赋值运算符
	const RefMembers& operator=(RefMembers const& x){
		*ptr1 = *(x.ptr1);
		*ptr2 = *(x.ptr2);
		return *this;
	}

	//不需要析构函数
	//缺省的析构函数将会让ptr1和ptr2删除他们所引用的对象。
};


#endif//REFERENCE_MEMBER_2_H