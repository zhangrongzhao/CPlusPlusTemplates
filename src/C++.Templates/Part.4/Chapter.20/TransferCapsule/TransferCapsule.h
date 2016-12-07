#include "../stdafx.h"

#ifndef TRANSFER_CAPSULE_H
#define TRANSFER_CAPSULE_H
//专门用于传递Holder的辅助类模板：保证只能有一个TransferCapsule具有对象的所有权。
template<typename T>
class Holder;

template<typename T>
class TransferCapsule{
private:
	T* pointer;//所引用的对象，从Holder接过来的所引用的对象。
private:
	//禁止复制。
	TransferCapsule(TransferCapsule&);
	//禁止隐式赋值。
	TransferCapsule& operator=(TransferCapsule const&);
	//友元类。
	friend class Holder<T>;
public:
	//构造函数，确保TransferCapsule只能作为返回对象，用于将Holder对象从被调用函数传递给调用函数
	TransferCapsule(Holder<T>& holder){
		pointer = holder.release();
	}

	//拷贝构造
	TransferCapsule(TransferCapsule<T> const& transferCapsule){
		pointer = transferCapsule.pointer;
		const_cast<TransferCapsule<T>>(transferCapsule).pointer = 0;
	}

	//析构函数，释放资源。
	~TransferCapsule(){
		delete pointer;
	}
};



#endif//TRANSFER_CAPSULE_H