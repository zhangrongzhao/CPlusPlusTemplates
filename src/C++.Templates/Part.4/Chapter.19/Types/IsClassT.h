#include "../stdafx.h"

#ifndef IS_CLASS_TYPE_H
#define IS_CLASS_TYPE_H
#include "IsFundaT.h"
#include "CompoundT.h"
#include "IsEnumT.h"

//是否为类类型：排除基本类型，枚举类型，组合类型，剩下的类型为类类型。

template<typename T>
class IsClassT{
public:
	enum{
		Yes = IsFundaT<T>::No
				&&IsEnumT<T>::No
				&&!CompoundT<T>::IsPointerT
				&&!CompoundT<T>::IsReferenceT
				&&!CompoundT<T>::IsPointerToMemberT
				&&!CompoundT<T>::IsArrayT
				&&!CompoundT<T>::IsFunctionT
	};

	enum{ No = !Yes };
};

#endif//IS_CLASS_TYEE_H