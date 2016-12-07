#include "../stdafx.h"

#ifndef SQRT_1_H
#define SQRT_1_H
#include "../Traits/IfThenElse.h"
template<int N,int LOWER=0,int HIGH=N>
class Sqrt{
public:
	enum{Middle=(LOWER+HIGH+1)/2};
	//enum{ result = (N<Middle*Middle) ? (Sqrt<N, LOWER, Middle - 1>::result) : (Sqrt<N,Middle,HIGH>::result) };
	typedef IfThenElse < (N < Middle*Middle),Sqrt<N, LOWER, Middle - 1>,	Sqrt<N, Middle, HIGH>> ::ResultT  SubT;
	enum{result=SubT::result};
};

template<int N,int M>
class Sqrt <N,M,M> {
public:
	enum{result=M};
};

#endif//SQRT_1_H