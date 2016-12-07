#include "../stdafx.h"

#ifndef IFTHENELSE_H
#define IFTHENELSE_H

//primary template:
template<bool C,typename Ta,typename Tb>
class IfThenElse;

//partial specialization
//C=true,chose the Ta as the result type;
template<typename Ta,typename Tb>
class IfThenElse <true,Ta,Tb>{
public:
	typedef Ta ResultT;
};

//partial specialization
//C=false,chose the Tb as the result type.
template<typename Ta,typename Tb>
class IfThenElse<false,Ta,Tb>{
public:
	typedef Tb ResultT;
};

#endif//IFTHENELSE_H