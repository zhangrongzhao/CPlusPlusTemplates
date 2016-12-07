#include "../stdafx.h"
#include <iostream>
#include <cstring>
#include <string>

//����C�ַ����е������
inline char* const& max(char* const& a, char* const& b){
	return std::strcmp(a, b) < 0 ? b : a;
}

inline const char* const& max(const char* const& a, const char* const& b){
	return std::strcmp(a, b) < 0 ? b : a;
}

//�������������е������
template<typename T>
inline T const& max(T const& a,T const& b){
	return a < b ? b : a;
}

//��3����������ֵ������ߣ�ͨ�������ý��е��ã�
template<typename T>
inline T const& max(T const& a,T const& b,T const& c){
	return ::max(::max(a,b),c);
}


