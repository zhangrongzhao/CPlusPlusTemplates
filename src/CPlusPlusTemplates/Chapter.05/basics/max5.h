#include "../stdafx.h"
#include <string>

inline char* max(char* a,char* b){
	return std::strcmp(a,b) < 0 ? b : a;
}

//c�ַ����Ƚϴ�С��ָ����ָ�����ݲ��ɱ䣬ָ�뱾�����洢��ַ�ɱ䣩
inline char const* max(char const* a,char const* b){
	return std::strcmp(a, b) < 0 ? b : a;
}

//inline char const*const max(char const* const a,char const* const b){
//	return std::strcmp(a, b) < 0 ? b : a;
//}

inline std::string max(std::string const& a,std::string const& b){
	return a < b ? b : a;
}

//ע�����ò�����
template<typename T>
inline T const& max(T const& a,T const& b){
    return a < b ? b : a;
}

template<typename T>
T max(T a ,T b){
	return a < b ? b : a;
}

template<typename T>
inline T const* max(T const* a,T const* b){
	return *a < *b ? b : a;
}

//template<typename T>
//inline T const *const max( T const*const a, T const*const b){
//	return std::strcmp(a, b) < 0 ? b : a;
//}



