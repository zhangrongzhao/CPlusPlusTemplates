#include "../stdafx.h"

#ifndef HOLDER_H
#define HOLDER_H
//Holder��ҪĿ�ģ���ȷ�ͷ���Դ��������Դй¶��
//holder����ռ�����ö�������Ȩ�����ṩ���ƹ��캯�������ṩ��ֵ���������ֹ��������Ȩ�Ķ�ռ�Ա����⴫��
//(�������������Ȩ��������һ��holder�ͷŵ�����֮������holder��Ȼ��Ϊ��ռ����Ȩ��������Holder�����Ѿ��ͷ��˵Ķ�������׳��쳣������ϵͳ����)
#include "../TransferCapsule/TransferCapsule.h"
template<typename T>
class Holder{
private:
	T* pointer;
private:
	//���ṩ���ƹ��죬���ṩ��ֵ�����
	Holder(Holder<T> const&);
	Holder<T>& operator=(Holder<T> const&);
public:
	Holder() :pointer(0){ }
    explicit Holder(T* ptr) :pointer(ptr){ }//explicit��֪��������ʽ����ת������ֹ��ʽ����ת����
	Holder(TransferCapsule<T> const& transferCapsule){
		pointer = transferCapsule.pointer;
		const_cast<TransferCapsule<T>&>(transferCapsule).pointer = 0;
	}
	~Holder(){ delete pointer; }

	//�����ָ��ĸ�ֵ�����
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

	//��������ռ��ָ��
	//���ؽ����������,������ʵ����
	T& operator*() const{
		return *pointer;
	}

	//����ָ����ʳ�Ա�����
	T* operator->() const{
		return pointer;
	}

	T* get()const{
		return pointer;
	}

	//�ͷŶ������ö��������Ȩ,���������ö������ָͨ��
	T* release(){
		T* temp = pointer;
		pointer = 0;
		return temp;
	}

	//����һ��Holder��������Ȩ��
	void exchange_with(Holder<T>& h){
		//swap(pointer,h.pointer);
	}

	//����һ��ָ�뽻������Ȩ
	void exchange_with(T* ptr){
		//swap(pointer,ptr);
	}
};

#endif//HOLDER_H