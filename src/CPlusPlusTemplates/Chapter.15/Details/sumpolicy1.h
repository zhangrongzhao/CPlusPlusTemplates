#include "../stdafx.h"

#ifndef SUMPOLICY_H
#define SUMPOLICY_H
class SumPolicy{
public:
	template<typename T1,typename T2>
	static void accumulate(T1& total,T2& value){
		total += value;
	}
};
#endif//SUMPOLICY_H
