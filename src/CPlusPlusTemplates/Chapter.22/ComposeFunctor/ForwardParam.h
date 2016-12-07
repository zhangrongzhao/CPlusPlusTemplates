#include "../stdafx.h"

#ifndef FORWARD_PARAM_H
#define FORWARD_PARAM_H

#include "IfThenElse.h"
#include "..\Types\TypeT.h"
#include "..\Traits\TypeOp.h"

//���Class���ͣ�ForwardParamT<T>::Type��һ��������
//����������������ͣ�ForwardParamT<T>::Type����ͨ����
//����void���ͣ�ForwardParamT<T>::Type��һ�������ͣ�Unused��

template<typename T>
class ForwardParamT{
public:
	typedef typename IfThenElse<TypeT<T>::IsClassT,
	                            typename TypeOp<T>::RefConstT,
								typename TypeOp<T>::ArgT
	                           >::ResultT Type;
};

//���void��ȫ���ػ�
template<>
class ForwardParamT<void>{
private:
	class Unused{};
public:
	typedef Unused Type;
};
#endif//FORWARD_PARAM_H