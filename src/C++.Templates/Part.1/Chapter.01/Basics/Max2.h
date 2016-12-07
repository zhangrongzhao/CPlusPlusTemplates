#include "../stdafx.h"

#ifndef MAX_2_H
#define MAX_2_H
//����ģ������
/********************���������������*****************************/
template<typename T>
inline T const& max(T const& a,T const& b){
	return a < b ? b : a;
}

/********************��Գ�ָ���������������*********************/
//������C�ַ����е������
//inline char const* const& max(char const* const& a,char const* const& b){
//	return std::strcmp(a, b) < 0 ? b : a;
//}

//inline char const* max(char const* a,char const* b){
//	return std::strcmp(a, b) < 0 ? b : a;
//}

inline char const* const& max(char const* const& a, char const* const& b){
	return std::strcmp(a, b) < 0 ? b : a;
}

//template<typename T>
//inline T* const& max(T* const& a,T* const& b){
//	return *a < *b ? b : a;
//}
/**************************************************************/
template<typename T>
inline T const& max(T const& a,T const& b,T const& c){
	return max(max(a,b),c);
}

void test_max(){
	/*int a = 7;
	int b = 42;
	int* p1 = &a;
	int* p2 = &b;
	::max(p1,p2);*/

	char const* s1 = "David";
	char const* s2 = "Nico";
	char const* s3 = "lucas";
	::max(s1,s2,s3);
}



#endif//MAX_2_H