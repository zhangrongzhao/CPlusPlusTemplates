#include "../stdafx.h"

#ifndef FORWARD_PARAM_H
#define FORWARD_PARAM_H

#include "IfThenElse.h"
#include "TypeOp.h"
#include "..\Types\TypeT.h"

//针对class类型，ForwardParamT<T>::Type是一个常引用
//针对其他的所用类型，ForwardParamT<T>::Type是普通类型
//针对void类型，ForwardParamT<T>::Type是一个哑类型(Unused)

template<typename T>
class ForwardParamT{
public:
	typedef typename IfThenElse<TypeT<T>::IsClassT,
	                            typename TypeOp<T>::RefConstT,
								typename TypeOp<T>::ArgT
	                           >::ResultT Type;
};

template<>
class ForwardParamT<void>{
private:
	class Unused{};
public:
	typedef Unused Type;
};

#endif//FORWARD_PARAM_H