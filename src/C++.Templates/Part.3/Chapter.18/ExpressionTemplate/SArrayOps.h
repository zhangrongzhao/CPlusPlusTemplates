#include "../stdafx.h"

#ifndef S_ARRAY_OPS_H
#define S_ARRAY_OPS_H
#include "SArray.h"

//使用了临时变量
template<typename T>
SArray<T> operator+(SArray<T> const& a,SArray<T> const& b){
	SArray<T> result(a.size());
	for (size_t idx = 0; idx < a.size();idx++){
		result[idx] = a[idx] + b[idx];
	}
	return result;
}

template<typename T>
SArray<T> operator*(SArray<T> const& a,SArray<T> const& b){
	SArray<T> result(a.size());
	for (size_t idx = 0; idx < a.size();idx++){
		result[idx] = a[idx] * b[idx];
	}
	return result;
}

template<typename T>
SArray<T> operator*(T const& scalar,SArray<T> const& a){
	SArray<T> result(a.size());
	for (size_t idx = 0; idx < a.size();idx++){
		result[idx] = a[idx] * scalar;
	}
	return result;
}

void test_SArray_OPS_1(){
	SArray<double> x(1000), y(1000);
	x = 1.2*x + x*y;//6000:read;4000:wirte,性能低下。
}


#endif//S_ARRAY_OPS_H