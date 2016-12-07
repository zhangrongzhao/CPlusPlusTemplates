#include "../stdafx.h"

#ifndef COUNTING_POINTER_H
#define COUNTING_POINTER_H
#include <cassert>
#include "CounterPolicy.h"
#include "ObjectPolicy.h"
//���ü���
//ǰ������һ��ָ��������ָͨ�룬�޷���������δ�������ֵ�����ٵġ�
//��������������ָͨ�룬ʹ�����������ָ��������
template<typename T,
         typename CounterPolicy=CounterPolicy<T>,//��ʲô�ط������������ڲ������Ƕ����ⲿ������ʱ�����߳�����£�Ҫʹ������ȷ������
		 typename ObjectPolicy = StandardObjectPolicy> //�����������ͷŲ��ԡ�
class CountingPointer:private CounterPolicy,private ObjectPolicy{
private:
	T* object_pointed_to;//�����õĶ������û�������κζ�����ΪNULL��
private:
	void init(T* ptr){
		if (p!=NULL){
			CounterPolicy::init(P);//ʹ�ü��������Խ��г�ʼ����
		}
		this->object_pointed_to = p;
	}
	//����ָ�룬���Ӽ�������ǰ����ָ����ڡ�
	void attach(CountingPointer<T,CounterPolicy,ObjectPolicy> const& countingPointer){
		this->object_pointed_to = countingPointer.object_pointed_to;
		if (countingPointer.object_pointed_to!=NULL){
			CounterPolicy::increment(countingPointer.object_pointed_to);
		}
	}
	//���ټ����������������Ϊ0,���ͷż�������
	void detach(){
		if (this->object_pointed_to!=NULL){
			CounterPolicy::decrement(this->object_pointed_to);
			if (CounterPolicy::is_zero(this->object_pointed_to)){
			    //�ͷż�������
				CounterPolicy::dispose(this->object_pointed_to);
				//�ͷŶ���ObjectPolicy::dispose()�ͷŶ���
				ObjectPolicy::dispose(this->object_pointed_to);
			}
		}
	}
public:
	//Ĭ�Ϲ��캯����û����ʾ��ʼ����û����explicit�ؼ��֡�
	CountingPointer(){
		this->object_pointed_to = NULL;
	}

	//���캯����Ϊ��ָ��Ķ���ʼһ���µļ�����
	explicit CountingPointer(T* ptr){
		this->init(ptr);
	}

	//�������캯���������Ӽ���
	CountingPointer(CountingPointer<T,CounterPolicy,ObjectPolicy> const& counterPointer)
	:CounterPolicy((CounterPolicy const&)counterPointer),
	 ObjectPolicy((CounterPolicy const&)counterPointer ){
		this->attach(counterPointer);
	};

	//��ֵ������������Ӽ�����
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

	//���������������ټ���
	~CountingPointer(){
		this->detach();
	};

	//���ָ��������������ʹ֮��Ϊ����ָ�롣
	T& operator*() const{
		return *(this->object_pointed_to);
	};

	T* operator->() const{
		return this->object_pointed_to;
	};
};


#endif//COUNTING_POINTER_H