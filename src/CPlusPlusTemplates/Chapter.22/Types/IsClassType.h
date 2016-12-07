#include "../stdafx.h"

#ifndef IS_CLASS_TYPE
#define IS_CLASS_TYPE

#include "FundamentalType.h"
#include "IsEnumType.h"
#include "CompoundType.h"

template<typename T>
class IsClassT{
public:
	enum{Yes = IsFundaT<T>::No &&
		       IsEnumT<T>::No &&
			   !CompoundT<T>::IsPtrT &&
			   !CompoundT<T>::IsRefT &&
			   !CompoundT<T>::IsArrayT &&
			   !CompoundT<T>::IsPtrMemT &&
			   !CompoundT<T>::IsFuncT};
	enum{No=!Yes};
};

#endif//IS_CLASS_TYPE