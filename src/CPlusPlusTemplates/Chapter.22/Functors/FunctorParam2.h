#include "../stdafx.h"

#ifndef FUNCTOR_PARAM_2_H
#define FUNCTOR_PARAM_2_H

#include "FunctorParam1.h"

#define FunctorParamSpec(N)                   \
	template<typename F>                      \
    class UsedFunctorParam<F,N>{              \
	   public:                                \
         typedef typename F::Param##N##T Type;\
	};                                        \

FunctorParamSpec(2);
FunctorParamSpec(3);
FunctorParamSpec(4);
FunctorParamSpec(5);
FunctorParamSpec(6);
FunctorParamSpec(7);
FunctorParamSpec(8);
FunctorParamSpec(9);
FunctorParamSpec(10);
FunctorParamSpec(11);
FunctorParamSpec(12);
FunctorParamSpec(13);
FunctorParamSpec(14);
FunctorParamSpec(15);
FunctorParamSpec(16);
FunctorParamSpec(17);
FunctorParamSpec(18);
FunctorParamSpec(19);
FunctorParamSpec(20);
#undef FunctorParamSpec

#endif//FUNCTOR_PARAM_2_H