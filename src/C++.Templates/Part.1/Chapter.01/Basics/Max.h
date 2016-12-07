#include "../stdafx.h"

#ifndef MAX_1_H
#define MAX_1_H

//����ģ�壺
/**************************���ֵ���ͽ�������************************************/
template<typename T>
inline T max(T a, T b){
	return a < b ? b : a;
}
/**************************���ָ�����ͽ�������************************************/
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
/**************************����������ͽ�������************************************/
template<typename T>
inline T& max(T& a,T& b ){
	return a < b ? b : a;
}

template<typename T>
inline T const& max(T const& ,T const& b){
	return a < b ? b : a;
}
#endif//MAX_1_H