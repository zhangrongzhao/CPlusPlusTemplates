#include "../stdafx.h"

#ifndef FUNCTOR_PARAM_H
#define FUNCTOR_PARAM_H

#include "..\Traits\IfThenElse.h"
template<typename F,int N>
class UsedFunctorParam;

template<typename F>
class UsedFunctorParam<F,1>{
public:
	typedef typename F::Param1T Type;
};

//ʹ�ú궨�壬�򻯾ֲ��ػ�
#define FunctorParamSpec(N)                     \
   template<typename F>                         \
   class UsedFunctorParam<F,N>{                 \
   public:                                      \
	   typedef typename F::Param##N##T Type;    \
   };                                           \

   FunctorParamSpec(2);
   FunctorParamSpec(3);
   FunctorParamSpec(4);
   FunctorParamSpec(5);
   FunctorParamSpec(6);
   FunctorParamSpec(7);
   FunctorParamSpec(8);
   FunctorParamSpec(9);
   FunctorParamSpec(10);
   FunctorParamSpec(11);
   FunctorParamSpec(12);
   FunctorParamSpec(13);
   FunctorParamSpec(14);
   FunctorParamSpec(15);
   FunctorParamSpec(16);
   FunctorParamSpec(17);
   FunctorParamSpec(18);
   FunctorParamSpec(19);
   FunctorParamSpec(20);
#undef FunctorParamSpec


//N��λ�ô��ڷº���F�Ĳ�������ʱ��ʹ��˽�е�Unused���͡�
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
	typedef typename IfThenElse<(F::NumParams>=N,UsedFunctorParam<F,N>,Unused)>::ResultT::Type Type;
};


#endif//FUNCTOR_PARAM_H