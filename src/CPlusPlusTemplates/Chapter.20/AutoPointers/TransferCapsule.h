#include "../stdafx.h"

#ifndef TRANSFER_CAPSULE_H
#define TRANSFER_CAPSULE_H

//transfer capsule(������):��Ҫ��������Holder����

template<typename T>
class Holder;

template<typename T>
class TransferCapsule{
private:
	T* ptr;//�����������õĶ���(������ڵĻ�)
public:
	//���캯����ȷ��TransferCapsuleֻ����Ϊ�������ͣ����ڽ�Holder�ӱ����ú������ݸ����ú���
	TransferCapsule(Holder<T>& h){
		ptr = h.release();
	}

	//�������캯��
	TransferCapsule(TransferCapsule<T> const& t){
		ptr = t.ptr;
		const_cast<TransferCapsule<T>&>(t).ptr = 0;//const_cast������const����ǿ��ת��Ϊnon-const���ͣ���ptrָ����Ϊ0���Ƴ�ԭTransferCapsule������Ȩ��
	}

	//��������
	~TransferCapsule(){
		delete ptr;
	}
private:
	TransferCapsule(TransferCapsule<T>&);//��ֹ����
	TransferCapsule<T>& operator=(TransferCapsule<T>&);//��ֹ������ֵ
	friend class Holder<T>;
};
#endif//TRANSFER_CAPSULE_H