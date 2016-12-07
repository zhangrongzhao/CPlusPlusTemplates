#include "../stdafx.h"

#ifndef MULT_POLICY_H
#define MULT_POLICY_H
//ÀÛ¼ÆÇó»ý
template<typename ResultT, typename T>
class MultPolicy{
public:
	static void accumulate(ResultT& total,T const& value){
		total *= value;
	}
};

#endif//MULT_POLICY_H