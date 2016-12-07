#include "../stdafx.h"
#include "IfThenElse.h"

#ifndef SQRT_H
#define SQRT_H

//以模板参数作为result的基本模板
template<int N>
class Value{
public:
	enum{Result=N};
};

//primary template
template<int N,int I=0>
class Sqrt{
public:

	//以实例化下一步Sqrt<N,I+1>或者结果类型Value<I>作为两个分支
	typedef IfThenElse<(I*I<N),Sqrt<N,I+1>,Value<I>>::Result SubT;

	//使用分支类型的结果
	enum{result=SubT::Result};
};
#endif//SQRT_H