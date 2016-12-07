#include "../stdafx.h"

#ifndef COUNTING_POINTER_H
#define COUNTING_POINTER_H
#include <cassert>
#include "CounterPolicy.h"
#include "ObjectPolicy.h"
//引用计数
//前提需求：一个指向对象的普通指针，无法跟踪是如何创建，赋值，销毁的。
//解决方案：针对普通指针，使用特殊的智能指针来管理。
template<typename T,
         typename CounterPolicy=CounterPolicy<T>,//在什么地方计数：对象内部，还是对象外部。计数时，多线程情况下，要使用锁正确计数。
		 typename ObjectPolicy = StandardObjectPolicy> //对象析构和释放策略。
class CountingPointer:private CounterPolicy,private ObjectPolicy{
private:
	T* object_pointed_to;//所引用的对象。如果没有引用任何对象，则为NULL。
private:
	void init(T* ptr){
		if (p!=NULL){
			CounterPolicy::init(P);//使用计数器策略进行初始化。
		}
		this->object_pointed_to = p;
	}
	//拷贝指针，增加计数器。前提是指针存在。
	void attach(CountingPointer<T,CounterPolicy,ObjectPolicy> const& countingPointer){
		this->object_pointed_to = countingPointer.object_pointed_to;
		if (countingPointer.object_pointed_to!=NULL){
			CounterPolicy::increment(countingPointer.object_pointed_to);
		}
	}
	//减少计数器（如果计数器为0,则释放计数器）
	void detach(){
		if (this->object_pointed_to!=NULL){
			CounterPolicy::decrement(this->object_pointed_to);
			if (CounterPolicy::is_zero(this->object_pointed_to)){
			    //释放计数器：
				CounterPolicy::dispose(this->object_pointed_to);
				//释放对象：ObjectPolicy::dispose()释放对象。
				ObjectPolicy::dispose(this->object_pointed_to);
			}
		}
	}
public:
	//默认构造函数。没有显示初始化。没有用explicit关键字。
	CountingPointer(){
		this->object_pointed_to = NULL;
	}

	//构造函数，为所指向的对象开始一个新的计数。
	explicit CountingPointer(T* ptr){
		this->init(ptr);
	}

	//拷贝构造函数，将增加计数
	CountingPointer(CountingPointer<T,CounterPolicy,ObjectPolicy> const& counterPointer)
	:CounterPolicy((CounterPolicy const&)counterPointer),
	 ObjectPolicy((CounterPolicy const&)counterPointer ){
		this->attach(counterPointer);
	};

	//赋值运算符，将增加计数。
	CountingPointer<T>& operator=(CountingPointer<T,CounterPolicy,ObjectPolicy> const& countingPointer){
		if (this->object_pointed_to != countingPointer.object_pointed_to){
			this->detach();
			CounterPolicy::operator=((CounterPolicy&)countingPointer);
			ObjectPolicy::operator=((ObjectPolicy&)countingPointer);
			this->attach(countingPointer);
		}
		return *this;
	};

	CountingPointer<T>& operator=(T* p){
		assert(p != this->object_pointed_to);
		this->detach();
		this->init(p);
		return *this;
	}

	//析构函数，将减少计数
	~CountingPointer(){
		this->detach();
	};

	//针对指针操作的运算符，使之成为智能指针。
	T& operator*() const{
		return *(this->object_pointed_to);
	};

	T* operator->() const{
		return this->object_pointed_to;
	};
};


#endif//COUNTING_POINTER_H