#include "../stdafx.h"

#ifndef FUNCTION_POINTER_H
#define FUNCTION_POINTER_H

#include "ForwardParam.h"
#include "FunctionPtrType.h"

template<typename RT,typename P1=void,
                     typename P2=void,
                     typename P3=void>
class FunctionPtr{
private:
	typedef typename FunctionPtrT<RT, P1, P2, P3>::Type FuncPtr;
	//封装的指针
	FuncPtr fPtr;
public:
	//使之适合我们的额框架
	enum{ NumParams = FunctionPtrT<RT, P1, P2, P3>::NumParams };
	typedef RT ReturnT;
	typedef P1 Param1T;
	typedef P2 Param2T;
	typedef P3 Param3T;

	//构造函数
	FunctionPtr(FuncPtr ptr):fPtr(ptr){ }

	//"函数调用"
	RT operator()(){
		return fPtr();
	}

	RT operator()(typename ForwardParamT<P1>::Type a1){
		return fPtr(a1);
	}

	RT operator()(typename ForwardParamT<P1>::Type a1,
		          typename ForwardParamT<P2>::Type a2){
		return fPtr(a1,a2);
	}

	RT operator()(typename ForwardParamT<P1>::Type a1,
		          typename ForwardParamT<P2>::Type a2,
				  typename ForwardParamT<P3>::Type a3){
		return fPtr(a1,a2,a3);
	}
}; 


#endif//FUNCTION_POINTER_H