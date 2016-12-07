#include "../stdafx.h"
#ifndef MULTPOLICY_H
#define MULTPOLICY_H
class MultPolicy{
public:
	template<typename T1,typename T2>
	static void accumulate(T1& total,T2& value){
		total *= value;
	}
};
#endif//MULTPOLICY_H