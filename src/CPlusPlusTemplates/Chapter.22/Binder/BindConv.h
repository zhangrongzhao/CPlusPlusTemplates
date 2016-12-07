#include "../stdafx.h"

#ifndef BIND_CONV_H
#define BIND_CONV_H

#include "..\Traits\ForwardParam.h"
#include "FunctorParam.h"
#include "Binder.h"

template<int P,         //绑定参数的位置，首个模板参数
	     typename FO>   //绑定参数所在的仿函数
inline Binder<FO, P, BoundVal<typename FunctorParam<FO, P>::Type>> bind(FO const& fo,typename ForwardParamT<typename FunctorParam<FO,P>::Type>::Type val){
	return Binder<FO,P,BoundVal<typename FunctorParam<FO,P>::Type>>(fo,BoundVal<typename FunctorParam<FO,P>::Type>(val));
}

#endif//BIND_CONV_H