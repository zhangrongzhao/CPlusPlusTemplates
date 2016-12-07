#include "../stdafx.h"

#ifndef CSTRING_AS_ARGUMENT_H
#define CSTRING_AS_ARGUMENT_H
#include <string>
//template<int N>
//inline char* max(char const (&a)[N],char const (&b)[N]){
//	return a < b ? b : a;
//}

//template<typename T,int N>
//inline T* max(T const (&a)[N],T const (&b)[N]){
//	return a < b ? b : a;
//}

template<typename T,int N,int M>
inline T* max(T const (&a)[N],T const (&b)[M]){
    
}


inline std::string max(std::string const& a,std::string const& b){
   
}

//inline char const* max(char const* a,char const* b){
//	return std::strcmp(a, b) < 0 ? b : a;
//}


//template<typename T>
//inline T const& max(T const& a,T const& b){
//	return a < b ? b : a;
//}

//template<typename T>
//inline T max(T a,T b){
//	return a < b ? b : a;
//}


void test_max(){
	::max("apple","peach");
	::max("apple","tomato");

}

#endif//CSTRING_AS_AEGUMENT_H