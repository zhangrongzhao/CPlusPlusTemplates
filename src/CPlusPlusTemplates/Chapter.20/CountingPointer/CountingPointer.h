#include "../stdafx.h"

#ifndef COUNTING_POINTER_H
#define COUNTING_POINTER_H
#include "SimpleReferenceCount.h"
#include "StandardObjectPolicy.h"

//引用计数.智能指针
//计数指针模板
template<typename T,
         typename CounterPolicy=SimpleReferenceCount,
		 typename ObjectPolicy=StandardObjectPolicy>
class CountingPtr:private CounterPolicy,private ObjectPolicy{//CounterPolicy,ObjectPolicy为空时，采用空基类优化提高性能EBCO
private:
	T* object_pointed_to;//所引用的对象,如果没有引用任何对象，则为NULL
public:
	//缺省构造函数，（没有显示初始化，既没有加上explicit关键字）
	CountingPtr(){
		this->object_pointed_to = NULL;
	}

	//构造函数，为T所指向的对象开始一个新的计数
	//一个针对转型的构造函数（转型自一个内建的指针）
	explicit CountingPtr(T* p){
		this->init(p);
	}

	//拷贝构造函数，将增加计数值
	CountingPtr(CountingPtr<T, CounterPolicy, ObjectPolicy> const& oCountingPointer)
		:CounterPolicy((CounterPolicy const&)oCountingPointer),//拷贝policy
		 ObjectPolicy((ObjectPolicy const&)oCountingPointer){
		this->attach(oCountingPointer);//拷贝指针，并且增加计数值
	}

	//析构函数，减少计数值
	~CountingPtr(){
		this->detach();//减少计数值，如果计数值为0，则释放该指针
	}

	//针对内建指针的赋值运算符
	CountingPtr<T, CounterPolicy, ObjectPolicy>& operator=(T* p){
		//计数指针不能指向*p:
		assert(P!=this->object_pointed_to);
		this->detach();//减少计数值，如果计数值为0，则释放该计数器
		this->init(p);//用一个普通指针初始化
		return *this;
	}

	//赋值运算符，将减少参数对象的计数值，同时增加被赋值对象的计数值，但是要考虑自己赋值给自己的情况存在。
	CountingPtr<T,CounterPolicy,ObjectPolicy>& operator=(CountingPtr<T,CounterPolicy,ObjectPolicy> const& oCountingPointer){
		if (this->object_pointed_to != oCountingPointer.object_pointed_to){
			this->detach();//减少计数值，如果计数值为0，则释放该计数器
			CounterPolicy::operator=((CounterPolicy const&)oCountingPointer);//对policy进行赋值
			ObjectPolicy::operator=((ObjectPolicy const&)oCountingPointer);
			this->attach(oCountingPointer);
		}
		return *this;
	}

	//下面是一些针对指针操作的运算符，使该类成为一个智能指针
	inline T& operator*() const{
		return *(this->object_pointed_to);
	}
	inline T* operator->() const{
		return this->object_pointed_to;
	}

	//以后在这里将可能会增加其他接口
	//...
	//增加一个转型构造函数，而且确认它可以访问，其他实例化体的私有组件
	//template<typename T2, typename CP2, typename OP2>
	//class CountingPtr;

	//friend 
    //template<typename S>//S可能是void或者T的基类
	//CountingPtr(CountingPtr<S, OP, CP> const& cp) :OP((OP const&)cp),CP((CP const&)cp),object_pointed_to(cp.object_pointed_to){
	//	if (cp.object_pointed_to != NULL){
	//		CP::increment(cp.object_pointed_to);
	//	}
	//}

	//到bool类型的转型。
	//operator bool() const{
	//	return this->object_pointed_to != (T*)0;
	//}

	//定义一个到成员指针类型的转型
	//private:
	//	class BoolConversionSupport{
	//		int dummy;
	//	};
	//public:
	//	operator BoolConversionSupport::*() const{
	//		return (this->object_pointed_to) ? (&BoolConversionSupport::dummy) : 0;
	//	}


public:
	friend bool operator==(CountingPtr<T,CP,OP> const& cp,T const* p){
		return cp == p;
	}

	friend bool operator==(T const* p,CountingPtr<T,CP,OP> const& cp){
		return p = cp;
	}

private:
	//辅助函数
	//用普通指针进行初始化（前提是该指针存在）
	void init(T* p){
		if (p != NULL){
			CounterPolicy::init(p);
		}
		this->object_pointed_to = p;
	}

	//拷贝指针并且增加计数值（前提是指针存在）
	void attach(CountingPtr<T,CounterPolicy,ObjectPolicy> const& oCounterPointer){
		this->object_pointed_to = oCounterPointer.object_pointed_to;
		if (oCounterPointer.object_pointed_to != NULL){
			CounterPolicy::increment(oCounterPointer.object_pointed_to);
		}
	}

	//减少计数值（如果计数值为0，则释放计数器）
	void detach(){
		if (this->object_pointed_to != NULL){
			CounterPolicy::decrement(this->object_pointed_to);
			//如果有必要，释放计数器
			CounterPolicy::dispose(this->object_pointed_to);
			//使用object policy来释放所指向的对象
			ObjectPolicy::dispose(this->object_pointed_to);
		}
	}
};


template<typename T1,typename T2,typename CP,typename OP>
inline bool operator==(CountingPtr<T1,CP,OP> const& cp1,CountingPtr<T2,CP,OP> const& cp2){
	return cp1.operator->() == cp2.operator->();
}

#endif//COUNTING_POINTER_H