#include "../stdafx.h"

#ifndef HOLDER_H
#define HOLDER_H
//Holder主要目的：正确释放资源，避免资源泄露。
//holder：独占所引用对象所有权。不提供复制构造函数，不提供赋值运算符，防止对象所有权的独占性被无意传递
//(如果允许传递所有权，当其中一个holder释放掉对象之后，其他holder仍然认为独占所有权。当其他Holder访问已经释放了的对象，则会抛出异常，甚至系统崩溃)
#include "../TransferCapsule/TransferCapsule.h"
template<typename T>
class Holder{
private:
	T* pointer;
private:
	//不提供复制构造，不提供赋值运算符
	Holder(Holder<T> const&);
	Holder<T>& operator=(Holder<T> const&);
public:
	Holder() :pointer(0){ }
    explicit Holder(T* ptr) :pointer(ptr){ }//explicit告知编译器显式类型转换，禁止隐式类型转换。
	Holder(TransferCapsule<T> const& transferCapsule){
		pointer = transferCapsule.pointer;
		const_cast<TransferCapsule<T>&>(transferCapsule).pointer = 0;
	}
	~Holder(){ delete pointer; }

	//针对新指针的赋值运算符
	Holder<T>& operator=(T* p){
		delete pointer;
		pointer = p;
		return *this;
	}
	Holder<T>& operator=(TransferCapsule<T> const& transferCapsule){
		delete pointer;
		pointer = transferCapsule.pointer;
		const_cast<TransferCapsule<T>>(transferCapsule).pointer = 0;
		return *this;
	}

	//访问所独占的指针
	//重载解引用运算符,返回真实对象
	T& operator*() const{
		return *pointer;
	}

	//重载指针访问成员运算符
	T* operator->() const{
		return pointer;
	}

	T* get()const{
		return pointer;
	}

	//释放对所引用对象的所有权,返回所引用对象的普通指针
	T* release(){
		T* temp = pointer;
		pointer = 0;
		return temp;
	}

	//与另一个Holder交换所有权。
	void exchange_with(Holder<T>& h){
		//swap(pointer,h.pointer);
	}

	//与另一个指针交换所有权
	void exchange_with(T* ptr){
		//swap(pointer,ptr);
	}
};

#endif//HOLDER_H