#include "../stdafx.h"

#ifndef TYPE_LIST_H
#define TPYE_LIST_H

#include "CompoundType.h"
#include "FundamentalType.h"
#include "IsClassType.h"
#include "IsEnumType.h"
#include "IsFunctionType.h"

template<typename T>
class TypeT{
public:
	enum{
		IsFundaT = IsFundaT<T>::Yes,
		IsPtrT = CompoundT<T>::IsPtrT,
		IsRefT = CompoundT<T>::IsRefT,
		IsArrayT = CompoundT<T>::IsArrayT,
		IsFuncT = CompoundT<T>::IsFuncT,
		IsPtrMemT = CompoundT<T>::IsPtrMemT,
		IsEnumT = IsEnumT<T>::Yes,
		IsClassT = IsClassT<T>::Yes
	};
};

#endif//TYPE_LIST_H