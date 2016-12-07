#include "../stdafx.h"

#ifndef BIND_CONV_H
#define BIND_CONV_H

#include "..\Traits\ForwardParam.h"
#include "FunctorParam.h"
#include "Binder.h"

template<int P,         //�󶨲�����λ�ã��׸�ģ�����
	     typename FO>   //�󶨲������ڵķº���
inline Binder<FO, P, BoundVal<typename FunctorParam<FO, P>::Type>> bind(FO const& fo,typename ForwardParamT<typename FunctorParam<FO,P>::Type>::Type val){
	return Binder<FO,P,BoundVal<typename FunctorParam<FO,P>::Type>>(fo,BoundVal<typename FunctorParam<FO,P>::Type>(val));
}

#endif//BIND_CONV_H