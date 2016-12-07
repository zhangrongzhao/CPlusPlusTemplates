#include "../stdafx.h"

#ifndef SARRAY_OPS_2_H
#define SARRAY_OPS_2_H
#include "SArray.h"

//不使用临时变量
template<typename T>
SArray<T>& SArray<T>::operator+=(SArray<T> const& b){
	for (size_t idx = 0; idx <size();idx++){
		(*this)[idx] *= b[idx];
	}
	return *this;
}

template<typename T>
SArray<T>& SArray<T>::operator*=(SArray<T> const& b){
	for (size_t idx = 0; idx < size();idx++){
		(*this)[idx] *= b[idx];
	}
	return *this;
}

template<typename T>
SArray<T>& SArray<T>::operator*=(T const& scalar){
	for (size_t idx = 0; idx < size();idx++){
		(*this)[idx] *= scalar;
	}
	return *this;
}

void test_SArray_OPS_2(){
	SArray<double> x(1000), y(1000);
	SArray<double> temp(x);
	//x = x*1.2 + temp*y;
	temp *= y;
	x *= 1.2;
	x += temp;
}

#endif//SARRAY_OPS_2_H