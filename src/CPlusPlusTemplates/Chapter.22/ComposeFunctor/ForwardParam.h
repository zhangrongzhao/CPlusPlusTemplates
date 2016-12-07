#include "../stdafx.h"

#ifndef FORWARD_PARAM_H
#define FORWARD_PARAM_H

#include "IfThenElse.h"
#include "..\Types\TypeT.h"
#include "..\Traits\TypeOp.h"

//针对Class类型，ForwardParamT<T>::Type是一个常引用
//针对其他的所用类型，ForwardParamT<T>::Type是普通类型
//对于void类型，ForwardParamT<T>::Type是一个哑类型（Unused）

template<typename T>
class ForwardParamT{
public:
	typedef typename IfThenElse<TypeT<T>::IsClassT,
	                            typename TypeOp<T>::RefConstT,
								typename TypeOp<T>::ArgT
	                           >::ResultT Type;
};

//针对void的全局特化
template<>
class ForwardParamT<void>{
private:
	class Unused{};
public:
	typedef Unused Type;
};
#endif//FORWARD_PARAM_H