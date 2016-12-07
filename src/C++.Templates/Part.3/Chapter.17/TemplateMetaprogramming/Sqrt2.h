#include "../stdafx.h"

#ifndef SQRT_2_H
#define SQRT_2_H
#include "../Traits/IfThenElse.h"
template<int V>
class Value{
public:
	enum{result=V};
};

template<int N,int I>
class Sqrt{
public:
	//enum{ result=(N<I*I)?Sqrt<N,I+1>::result:I};
	typedef IfThenElse<(N<I*I),Sqrt<N,I+1>,Value<I>>::ResultT SubT;
	enum{result=SubT::result};
};

template<N>
class Sqrt<N,N>{
public:
	enum{result=N};
};
#endif//SQRT_2_H