#include "../stdafx.h"

#ifndef BINDER_PARAMS_H
#define BINDER_PARAMS_H

#include "..\Traits\IfThenElse.h"
#include "FunctorParam.h"

template<typename F,int P>
class BinderParams{
public:
	//参数个数减少1,因为一个参数已经绑定了
	enum{ NumParams = F::NumParams - 1 };
#define ComposeParamT(N)                                                                                 \
	typedef typename IfThenElse<(N<P),FunctorParam<F,N>,FunctorParam<F,N+1>>::ResultT::Type Param##N##T; \

	ComposeParamT(1);
	ComposeParamT(2);
	ComposeParamT(3);
	ComposeParamT(4);
	ComposeParamT(5);
	ComposeParamT(6);
	ComposeParamT(7);
	ComposeParamT(8);
	ComposeParamT(9);
	ComposeParamT(10);
	ComposeParamT(11);
	ComposeParamT(12);
	ComposeParamT(13);
	ComposeParamT(14);
	ComposeParamT(15);
	ComposeParamT(16);
	ComposeParamT(17);
	ComposeParamT(18);
	ComposeParamT(19);
	ComposeParamT(20);
#undef ComposeParamT
};

#endif//BINDER_PARAMS_H