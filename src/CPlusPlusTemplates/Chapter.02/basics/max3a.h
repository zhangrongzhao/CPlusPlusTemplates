#include "../stdafx.h"
#include <iostream>
#include <cstring>
#include <string>

//两个C字符串中的最大者
inline char* const& max(char* const& a, char* const& b){
	return std::strcmp(a, b) < 0 ? b : a;
}

inline const char* const& max(const char* const& a, const char* const& b){
	return std::strcmp(a, b) < 0 ? b : a;
}

//两个任意类型中的最大者
template<typename T>
inline T const& max(T const& a,T const& b){
	return a < b ? b : a;
}

//求3个任意类型值的最大者（通过传引用进行调用）
template<typename T>
inline T const& max(T const& a,T const& b,T const& c){
	return ::max(::max(a,b),c);
}


