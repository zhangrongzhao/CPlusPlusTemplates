#include "../stdafx.h"

#ifndef ARRAY_OPS_2
#define ARRAY_OPS_2

#include "exprArray.h"
#include "exprops1.h"

//两个数组相加
template<typename T,typename R1,typename R2>
Array<T, A_Add<T,R1,R2>> operator+(Array<T,R1> const& a,Array<T,R2> const& b){
	return Array<T,A_Add<T,R1,R2>>(A_Add<T,R1,R2>(a.rep(),b.rep()));
}

//两个数组相乘
template<typename T,typename R1,typename R2>
Array<T, A_Mult<T, R1, R2>> operator*(Array<T, R1> const& a, Array<T, R2> const& b){
	return Array<T, A_Mult<T, R1, R2>>(A_Mult<T, R1, R2>(a.rep(), b.rep()));
}

//scalar和数组相乘
template<typename T,typename R2>
Array<T, A_Mult<T,A_Scalar<T>, R2>> operator*(T const& s, Array<T, R2> const& b){
	return Array<T, A_Mult<T, A_Scalar<T>, R2>>(A_Mult<T, A_Scalar<T>, R2>(A_Scalar<T>(s), b.rep()));
}

#endif//ARRAY_OPS_2