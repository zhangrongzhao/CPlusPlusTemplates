#include "../stdafx.h"

#ifndef TRANSFER_CAPSULE_H
#define TRANSFER_CAPSULE_H

//transfer capsule(运送器):主要用来传递Holder对象

template<typename T>
class Holder;

template<typename T>
class TransferCapsule{
private:
	T* ptr;//运送器所引用的对象(如果存在的话)
public:
	//构造函数，确保TransferCapsule只能作为返回类型，用于将Holder从被调用函数传递给调用函数
	TransferCapsule(Holder<T>& h){
		ptr = h.release();
	}

	//拷贝构造函数
	TransferCapsule(TransferCapsule<T> const& t){
		ptr = t.ptr;
		const_cast<TransferCapsule<T>&>(t).ptr = 0;//const_cast函数将const类型强制转换为non-const类型，将ptr指针置为0，移除原TransferCapsule的所有权。
	}

	//析构函数
	~TransferCapsule(){
		delete ptr;
	}
private:
	TransferCapsule(TransferCapsule<T>&);//禁止拷贝
	TransferCapsule<T>& operator=(TransferCapsule<T>&);//禁止拷贝赋值
	friend class Holder<T>;
};
#endif//TRANSFER_CAPSULE_H