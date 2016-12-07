#include "stdafx.h"
#include <string>

namespace Test1{
	inline int const& Max(int const& a,int const& b){
		return a < b ? b : a;
	}

	inline double const& Max(double const& a, double const& b){
		return a < b ? b : a;
	}

	inline std::string const& Max(std::string const& a, std::string const& b){
		return a < b ? b : a;
	}

	/*
	* ×î´óÖµ
	*/
	template<typename T>
	inline T const& Max(T const& a, T const& b){
		return a < b ? b : a;
	}

	template<typename T>
	inline T const& Max(T const& a,T const& b,T const& c){
		return Test::Max(Test::Max(a,b),c);
	}

	template<typename T1,typename T2>
	inline T1 Max(T1 const& a, T2 const& b){
		return a < b ? b : a;
	}

	template<typename RT,typename T1,typename T2>
	inline RT const& Max(T1 const& a,T2 const& b){
		return a < b ? a : b;
	}
}