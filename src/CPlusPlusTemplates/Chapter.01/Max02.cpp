#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>

namespace Test02{
    template<typename T>
	inline T const& Max(T const& a,T const& b){
		return a < b ? b : a;
	}

	/*
	* Ϊʲô��ֵ����:ȡ*������ĳ�ʼ���塣ȡֵ
	*
	*/
	inline char const* Max(char const* a,char const* b){
		return std::strcmp(a,b)<0?b:a;
	}

	//template<typename T>
	//inline T* const& Max(T* const& a,T* const& b){
	//	return *a < *b ? b : a;
	//}

    template<typename T>
	inline T const& Max(T const a,T const b,T const c){
		//a = "111";
		return Test02::Max(Test02::Max(a,b),c);
	}

	//inline char const* const& Max(char const* const& a,
	//	                          char const* const& b)
	//{
	//	return std::strcmp(a, b) < 0 ? b : a;
	//}
}