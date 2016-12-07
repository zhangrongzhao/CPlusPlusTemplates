#include "../stdafx.h"

#ifndef IS_CLASS_TYPE_H
#define IS_CLASS_TYPE_H
#include "IsFundaT.h"
#include "CompoundT.h"
#include "IsEnumT.h"

//�Ƿ�Ϊ�����ͣ��ų��������ͣ�ö�����ͣ�������ͣ�ʣ�µ�����Ϊ�����͡�

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