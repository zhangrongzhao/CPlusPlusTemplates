#include "../stdafx.h"
#ifndef LOOP_1_H
#define LOOP_1_H
template<typename T>
int dot_product(int dim,T* a,T* b){
	T result = T();
	for (int i = 0; i < dim;i++){
		result += a[i]*b[i];
	}
	return result;
}

#endif//LOOP_1_H