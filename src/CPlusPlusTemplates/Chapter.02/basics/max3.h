#include "../stdafx.h"
#include <iostream>

//比较两个任意类型的最大者
template<typename T>
inline T const& max(T const& a, T const& b){
	return a < b ? b : a;
}


//比较两个指针类型的最大者
template<typename T>
inline T* const& max(T* const& a,T* const& b){
	return *a < *b ? b : a;
}


//比较C字符串中的最大者
inline char* const& max(char* const& a,char* const& b){
	return std::strcmp(a, b) < 0 ? b : a;
}
