#include "../stdafx.h"

#ifndef TYPE_OP_H
#define TYPE_OP_H

//����ģ��:�����������
template<typename T>
class TypeOp{
public:
	typedef T ArgT;
	typedef T BareT;
	typedef T const ConstT;
	typedef T& RefT;
	typedef T& RefBareT;
	typedef T const& RefConstT;
};

//���const���͵ľֲ��ػ�
template<typename T>
class TypeOp<T const>{
public:
	typedef T const ArgT;
	typedef T BareT;          
	typedef T const ConstT;
	typedef T const& RefT;
	typedef T& RefBareT;
	typedef T const& RefConstT;
};

//������õľֲ��ػ�
template<typename T>
class TypeOp<T&> {
public:
	typedef T& ArgT;
	typedef typename TypeOp<T>::BareT BareT;
	typedef T const ConstT;
	typedef T& RefT;
	typedef typename TypeOp<T>::RefBareT RefBareT;
	typedef T const& RefConstT;
};

//���void���ػ���ָ��void�������ǲ�����ġ�Ҫ��ָ��void�����ý���ȫ���ػ���
template<>
class TypeOp<void>{
public:
	typedef void ArgT;
	typedef void BareT;
	typedef void const ConstT;
	typedef void RefT;
	typedef void RefBareT;
	typedef void RefConstT;
};

#endif//TYPE_OP_H
