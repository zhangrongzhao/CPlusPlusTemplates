#include "../stdafx.h"

#ifndef ARRAY_SCALAR_OP_H
#define ARRAY_SCALAR_OP_H

//��ֵ����ķŴ�����չΪScalar��ֵ���飬��Ϊһ�ֲ�����
template<typename T>
class A_Scalar{
private:
	T const& s;//scalar��ֵ
public:
	A_Scalar(T const& value) :s(value){ }

	//ת��Ϊ�±����㣬ÿ��Ԫ�ض�����Scalar�Ŵ��ֵ
	T operator[](size_t idx){
		return s;
	}

	//scalar�Ĵ�С
	size_t size() const{
		return 0;
	}
};

#endif//ARRAY_SCALAR_OP_H