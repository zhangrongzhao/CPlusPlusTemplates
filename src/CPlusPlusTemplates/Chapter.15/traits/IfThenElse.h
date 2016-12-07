#include "../stdafx.h"

#ifndef IFTHENELSE_H
#define IFTHENELSE_H

//primary template:根据第一个实参来决定：是选择第2个实参，还是第三个实参
template<bool C,typename Ta,typename Tb>
class IfThenElse;

//partail specialization: true选择第二个实参
template<typename Ta,typename Tb>
class IfThenElse<true,Ta,Tb>{
public:
	typedef Ta ResultT;
};

//partial specialization:false选择第三个实参
template<typename Ta,typename Tb>
class IfThenElse<false,Ta,Tb>{
public:
	typedef Tb ResultT;
};

#endif//IFTHENELSE_H