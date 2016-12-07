#include "../stdafx.h"

#ifndef TYPE_OP_H
#define TYPE_OP_H
//����ģ��
template<typename T>
class TypeOp{
public:
	typedef T ArgT;
	typedef T BareT;
	typedef T const ConstT;
	typedef T& RefT;
	typedef T& RefBareT;
	typedef T const & RefConstT;
};

//��Գ������;ֲ��ػ�
template<typename T>
class TypeOp<T const>{//���const���͵ľֲ��ػ�
public:
	typedef T const ArgT;
	typedef T BareT;
	typedef T const ConstT;
	typedef T const& RefT;
	typedef T & RefBareT;
	typedef T const& RefConstT;
};

//����������;ֲ��ػ�
template<typename T>
class TypeOp<T&>{//������õľֲ��ػ�
public:
	typedef T& ArgT;
	typedef T& RefT;
	typedef T const ConstT;
	typedef typename TypeOp<T>::BareT BareT;
	typedef typename TypeOp<T>::BareT & RefBareT;
	typedef T const & RefConstT;
};

//���void���ͽ���ȫ���ػ�
template<>
class TypeOp<void>{//���void��ȫ���ػ�
public:
	typedef void ArgT;
	typedef void BareT;
	typedef void const ConstT;
	typedef void RefT;
	typedef void RefBareT;
	typedef void RefConstT;
};


#endif//TYPE_OP_H