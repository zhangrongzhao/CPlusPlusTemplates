#include "../stdafx.h"
#include <iostream>

//�Ƚ������������͵������
template<typename T>
inline T const& max(T const& a, T const& b){
	return a < b ? b : a;
}


//�Ƚ�����ָ�����͵������
template<typename T>
inline T* const& max(T* const& a,T* const& b){
	return *a < *b ? b : a;
}


//�Ƚ�C�ַ����е������
inline char* const& max(char* const& a,char* const& b){
	return std::strcmp(a, b) < 0 ? b : a;
}
