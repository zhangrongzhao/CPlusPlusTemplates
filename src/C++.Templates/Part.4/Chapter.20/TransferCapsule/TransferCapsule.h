#include "../stdafx.h"

#ifndef TRANSFER_CAPSULE_H
#define TRANSFER_CAPSULE_H
//ר�����ڴ���Holder�ĸ�����ģ�壺��ֻ֤����һ��TransferCapsule���ж��������Ȩ��
template<typename T>
class Holder;

template<typename T>
class TransferCapsule{
private:
	T* pointer;//�����õĶ��󣬴�Holder�ӹ����������õĶ���
private:
	//��ֹ���ơ�
	TransferCapsule(TransferCapsule&);
	//��ֹ��ʽ��ֵ��
	TransferCapsule& operator=(TransferCapsule const&);
	//��Ԫ�ࡣ
	friend class Holder<T>;
public:
	//���캯����ȷ��TransferCapsuleֻ����Ϊ���ض������ڽ�Holder����ӱ����ú������ݸ����ú���
	TransferCapsule(Holder<T>& holder){
		pointer = holder.release();
	}

	//��������
	TransferCapsule(TransferCapsule<T> const& transferCapsule){
		pointer = transferCapsule.pointer;
		const_cast<TransferCapsule<T>>(transferCapsule).pointer = 0;
	}

	//�����������ͷ���Դ��
	~TransferCapsule(){
		delete pointer;
	}
};



#endif//TRANSFER_CAPSULE_H