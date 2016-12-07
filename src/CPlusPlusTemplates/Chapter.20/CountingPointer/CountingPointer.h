#include "../stdafx.h"

#ifndef COUNTING_POINTER_H
#define COUNTING_POINTER_H
#include "SimpleReferenceCount.h"
#include "StandardObjectPolicy.h"

//���ü���.����ָ��
//����ָ��ģ��
template<typename T,
         typename CounterPolicy=SimpleReferenceCount,
		 typename ObjectPolicy=StandardObjectPolicy>
class CountingPtr:private CounterPolicy,private ObjectPolicy{//CounterPolicy,ObjectPolicyΪ��ʱ�����ÿջ����Ż��������EBCO
private:
	T* object_pointed_to;//�����õĶ���,���û�������κζ�����ΪNULL
public:
	//ȱʡ���캯������û����ʾ��ʼ������û�м���explicit�ؼ��֣�
	CountingPtr(){
		this->object_pointed_to = NULL;
	}

	//���캯����ΪT��ָ��Ķ���ʼһ���µļ���
	//һ�����ת�͵Ĺ��캯����ת����һ���ڽ���ָ�룩
	explicit CountingPtr(T* p){
		this->init(p);
	}

	//�������캯���������Ӽ���ֵ
	CountingPtr(CountingPtr<T, CounterPolicy, ObjectPolicy> const& oCountingPointer)
		:CounterPolicy((CounterPolicy const&)oCountingPointer),//����policy
		 ObjectPolicy((ObjectPolicy const&)oCountingPointer){
		this->attach(oCountingPointer);//����ָ�룬�������Ӽ���ֵ
	}

	//�������������ټ���ֵ
	~CountingPtr(){
		this->detach();//���ټ���ֵ���������ֵΪ0�����ͷŸ�ָ��
	}

	//����ڽ�ָ��ĸ�ֵ�����
	CountingPtr<T, CounterPolicy, ObjectPolicy>& operator=(T* p){
		//����ָ�벻��ָ��*p:
		assert(P!=this->object_pointed_to);
		this->detach();//���ټ���ֵ���������ֵΪ0�����ͷŸü�����
		this->init(p);//��һ����ָͨ���ʼ��
		return *this;
	}

	//��ֵ������������ٲ�������ļ���ֵ��ͬʱ���ӱ���ֵ����ļ���ֵ������Ҫ�����Լ���ֵ���Լ���������ڡ�
	CountingPtr<T,CounterPolicy,ObjectPolicy>& operator=(CountingPtr<T,CounterPolicy,ObjectPolicy> const& oCountingPointer){
		if (this->object_pointed_to != oCountingPointer.object_pointed_to){
			this->detach();//���ټ���ֵ���������ֵΪ0�����ͷŸü�����
			CounterPolicy::operator=((CounterPolicy const&)oCountingPointer);//��policy���и�ֵ
			ObjectPolicy::operator=((ObjectPolicy const&)oCountingPointer);
			this->attach(oCountingPointer);
		}
		return *this;
	}

	//������һЩ���ָ��������������ʹ�����Ϊһ������ָ��
	inline T& operator*() const{
		return *(this->object_pointed_to);
	}
	inline T* operator->() const{
		return this->object_pointed_to;
	}

	//�Ժ������ｫ���ܻ����������ӿ�
	//...
	//����һ��ת�͹��캯��������ȷ�������Է��ʣ�����ʵ�������˽�����
	//template<typename T2, typename CP2, typename OP2>
	//class CountingPtr;

	//friend 
    //template<typename S>//S������void����T�Ļ���
	//CountingPtr(CountingPtr<S, OP, CP> const& cp) :OP((OP const&)cp),CP((CP const&)cp),object_pointed_to(cp.object_pointed_to){
	//	if (cp.object_pointed_to != NULL){
	//		CP::increment(cp.object_pointed_to);
	//	}
	//}

	//��bool���͵�ת�͡�
	//operator bool() const{
	//	return this->object_pointed_to != (T*)0;
	//}

	//����һ������Աָ�����͵�ת��
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
	//��������
	//����ָͨ����г�ʼ����ǰ���Ǹ�ָ����ڣ�
	void init(T* p){
		if (p != NULL){
			CounterPolicy::init(p);
		}
		this->object_pointed_to = p;
	}

	//����ָ�벢�����Ӽ���ֵ��ǰ����ָ����ڣ�
	void attach(CountingPtr<T,CounterPolicy,ObjectPolicy> const& oCounterPointer){
		this->object_pointed_to = oCounterPointer.object_pointed_to;
		if (oCounterPointer.object_pointed_to != NULL){
			CounterPolicy::increment(oCounterPointer.object_pointed_to);
		}
	}

	//���ټ���ֵ���������ֵΪ0�����ͷż�������
	void detach(){
		if (this->object_pointed_to != NULL){
			CounterPolicy::decrement(this->object_pointed_to);
			//����б�Ҫ���ͷż�����
			CounterPolicy::dispose(this->object_pointed_to);
			//ʹ��object policy���ͷ���ָ��Ķ���
			ObjectPolicy::dispose(this->object_pointed_to);
		}
	}
};


template<typename T1,typename T2,typename CP,typename OP>
inline bool operator==(CountingPtr<T1,CP,OP> const& cp1,CountingPtr<T2,CP,OP> const& cp2){
	return cp1.operator->() == cp2.operator->();
}

#endif//COUNTING_POINTER_H