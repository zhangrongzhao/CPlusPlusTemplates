#include "../stdafx.h"

#ifndef SARRAY_OPS
#define SARRAY_OPS

#include "sarray1.h"

//������SArray���
template<typename T>
SArray<T> operator+(SArray<T> const& a,SArray<T> const& b){
	SArray<T> result(a.size());
	for (size_t k = 0; k < a.size();++k){
		result[k] = a[k] + b[k];
	}
	return result;
}

//������SArray���
template<typename T>
SArray<T> operator*(SArray<T> const& a,SArray<T> const& b){
	SArray<T> result(a.size());
	for (size_t k = 0; k < a.size();++k){
		result[k] = a[k] * b[k];
	}
	return result;
}

//��һ��SArray����һ���Ŵ���
template<typename T>
SArray<T> operator*(T const& s,SArray<T> const& a){
	SArray<T> result(a.size());
	for (size_t k = 0; k < a.size();k++){
		result[k] = a[k] * s;
	}
	return result;
}
#endif//SARRAY_OPS

