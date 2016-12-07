#include "../stdafx.h"
#ifndef RPARAM_H
#define RPARAM_H

#include "IfThenElse.h"
#include "isClassType.h"

//primary template
template<typename T>
class RParam{
public:
	typedef typename IfThenElse<IsClassType<T>::No, T, T const&>::ResultT ResultT;
};

#endif//RPARAM_H


/*
//����������ͽ��оֲ��ػ�
template<typename T>
class RParam<array<T> >{
public:
	typedef array<T> const& Type;
};
*/
