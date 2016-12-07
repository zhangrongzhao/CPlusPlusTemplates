#include "../stdafx.h"

#ifndef ARRAY_SCALAR_OP_H
#define ARRAY_SCALAR_OP_H

//数值数组的放大倍数扩展为Scalar数值数组，作为一种操作数
template<typename T>
class A_Scalar{
private:
	T const& s;//scalar的值
public:
	A_Scalar(T const& value) :s(value){ }

	//转换为下标运算，每个元素都等于Scalar放大的值
	T operator[](size_t idx){
		return s;
	}

	//scalar的大小
	size_t size() const{
		return 0;
	}
};

#endif//ARRAY_SCALAR_OP_H