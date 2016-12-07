#include "../stdafx.h"

#ifndef HOLDER_H
#define HOLDER_H
#include "TransferCapsule.h"

//Holder����ռptr�����ö��������Ȩ
//����������ͷ���ָ���ָ�룺1.�����ͷţ�2.����һ��ָ�븳ֵ����
template<typename T>
class Holder{
private:
	T* ptr;//�����������еĶ���ǰ���Ǹö������
public:
	//ȱʡ���캯�����ø�Holder����һ���ն���
	Holder() :ptr(0){ }

	//���ָ��Ĺ��캯�����ø�Holder���ø�ָ����ָ��Ķ���
	explicit Holder(T* p) :ptr(p){ }

	Holder(TransferCapsule<T> const& t){
		ptr = t.ptr;
		const_cast<TransferCapsule<T>&>(t).ptr = 0;//�Ƴ�TransferCapsuleԭ�еĶ�������Ȩ
	}

	Holder<T>& operator=(TransferCapsule<T> const& t){
		delete ptr;//�ͷ�Holderԭ�ж�������Ȩ��
		ptr = t.ptr;
		const_cast<TransferCapsule<T>&>(t).ptr = 0;//�Ƴ�TransferCapsuleԭ�ж�������Ȩ��
		return *this;
	}

	//�����������ͷ������õĶ���ǰ��ö�����ڣ�
	~Holder(){
		delete ptr;
	}

	//�����ָ��ĸ�ֵ�����
	Holder<T>& operator=(T* p){
		delete ptr;//����ֵ�µĶ���֮ǰ���ͷų��е�ԭ�ж���
		ptr = p;
		return *this;
	}

	//ָ�������
	T& operator*() const{
		return *ptr;
	}

	T* operator->() const{
		return ptr;
	}

	//��ȡ�����õĶ���ǰ���Ǹö�����ڣ�
	T* get() const{
		return ptr;
	}

	//�ͷŶ������ö��������Ȩ
	T* release(){
		T* temp = ptr;
		ptr = 0;
		return temp;
	}

	//����һ��Holder��������Ȩ
	void exchange_with(Holder<T>& h){
		swap(ptr,h);
	}

	//��������ָ�뽻������Ȩ
	void exchange_with(T*& p){
		swap(ptr,p);
	}
private:
	//�������ṩ�������캯���Ϳ�����ֵ�����
	Holder(Holder<T> const&);
	Holder<T>& operator=(Holder<T> const&);
};
#endif//HOLDER_H