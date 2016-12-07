#include "../stdafx.h"

#ifndef MAX_1_H
#define MAX_1_H

//函数模板：
/**************************针对值类型进行重载************************************/
template<typename T>
inline T max(T a, T b){
	return a < b ? b : a;
}
/**************************针对指针类型进行重载************************************/
template<typename T>
inline T* max(T* a,T* b){
	return *a < *b ? b : a;
}

template<typename T>
inline T const* max(T const* a,T const* b){
	return *a < *b ? b : a;
}

template<typename T>
inline T* const max(T* const a,T* const b){
	return *a < *b ? b : a;
}

//template<typename T>
//inline T const* const max(T const* const a,T const* const b){
//	return *a < *b ? b : a;
//}
/**************************针对引用类型进行重载************************************/
template<typename T>
inline T& max(T& a,T& b ){
	return a < b ? b : a;
}

template<typename T>
inline T const& max(T const& ,T const& b){
	return a < b ? b : a;
}
#endif//MAX_1_H