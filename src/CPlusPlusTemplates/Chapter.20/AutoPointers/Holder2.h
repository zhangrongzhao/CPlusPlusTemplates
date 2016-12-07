#include "../stdafx.h"

#ifndef HOLDER_H
#define HOLDER_H
#include "TransferCapsule.h"

//Holder：独占ptr所引用对象的所有权
//两种情况下释放所指向的指针：1.本身被释放；2.把另一个指针赋值给它
template<typename T>
class Holder{
private:
	T* ptr;//引用它所持有的对象，前提是该对象存在
public:
	//缺省构造函数，让该Holder引用一个空对象
	Holder() :ptr(0){ }

	//针对指针的构造函数，让该Holder引用该指针所指向的对象
	explicit Holder(T* p) :ptr(p){ }

	Holder(TransferCapsule<T> const& t){
		ptr = t.ptr;
		const_cast<TransferCapsule<T>&>(t).ptr = 0;//移除TransferCapsule原有的对象所有权
	}

	Holder<T>& operator=(TransferCapsule<T> const& t){
		delete ptr;//释放Holder原有对象所有权。
		ptr = t.ptr;
		const_cast<TransferCapsule<T>&>(t).ptr = 0;//移除TransferCapsule原有对象所有权。
		return *this;
	}

	//析构函数：释放所引用的对象（前提该对象存在）
	~Holder(){
		delete ptr;
	}

	//针对新指针的赋值运算符
	Holder<T>& operator=(T* p){
		delete ptr;//被赋值新的对象之前，释放持有的原有对象
		ptr = p;
		return *this;
	}

	//指针运算符
	T& operator*() const{
		return *ptr;
	}

	T* operator->() const{
		return ptr;
	}

	//获取所引用的对象（前提是该对象存在）
	T* get() const{
		return ptr;
	}

	//释放对所引用对象的所有权
	T* release(){
		T* temp = ptr;
		ptr = 0;
		return temp;
	}

	//与另一个Holder交换所有权
	void exchange_with(Holder<T>& h){
		swap(ptr,h);
	}

	//与其他的指针交换所有权
	void exchange_with(T*& p){
		swap(ptr,p);
	}
private:
	//不向外提供拷贝构造函数和拷贝赋值运算符
	Holder(Holder<T> const&);
	Holder<T>& operator=(Holder<T> const&);
};
#endif//HOLDER_H