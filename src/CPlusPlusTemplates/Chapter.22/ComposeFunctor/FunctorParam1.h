#include "../stdafx.h"

#ifndef FUNCTOR_PARAM_1_H
#define FUNCTOR_PARAM_1_H

#include "IfThenElse.h"

template<typename F,int N>
class UsedFunctorParam;

template<typename F>
class UsedFunctorParam<F,1>{
public:
	typedef typename F::Param1T Type;
};


//���ʸ���functor�ĵ�N������������
template<typename F,int N>
class FunctorParam{
private:
	class Unused{
	private:
		class Private{};
	public:
		typedef Private Type;
	};
public:
	typedef typename IfThenElse<F::NumParam>=N,UsedFunctorParam<F,N>,Unused>::ResultT::Type Type;
};



#endif//FUNCTOR_PARAM_1_H