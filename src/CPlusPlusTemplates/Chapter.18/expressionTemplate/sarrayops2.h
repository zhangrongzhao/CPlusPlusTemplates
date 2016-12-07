#include "../stdafx.h"
#ifndef SARRAY_OPS_2
#define SARRAY_OPS_2
#include "sarray1.h"

//SArray的自加运算符
template<typename T>
SArray<T> SArray<T>::operator+=(SArray<T> const& b){
	for (size_t k = 0; k < size(); k++){
		(*this)[k] += b[k];
	}
	return *this;
}

//SArray的自乘运算符
template<typename T>
SArray<T> SArray<T>::operator*=(SArray<T> const& b){
	for (size_t k = 0; k < size();k++){
		(*this)[k] *= b[k];
	}
	return *this;
}

//针对放大倍数的自乘运算符
template<typename T>
SArray<T> SArray<T>::operator*=(T const& s){
	for (size_t k = 0; k < size();k++){
		(*this)[k] *= s;
	}
	return *this;
}

#endif//SARRAY_OPS_2