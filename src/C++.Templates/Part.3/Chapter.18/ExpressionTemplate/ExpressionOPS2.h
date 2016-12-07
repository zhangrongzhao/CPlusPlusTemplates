#include "../stdafx.h"

#ifndef EXPRESSION_OPS_2_H
#define EXPRESSION_OPS_2_H
#include "ExpressionOPS.h"
#include "Array.h"
#include "A_Scalar.h"

//两个数组相加
template<typename T,typename R1,typename R2>
Array<T,A_Add<T,R1,R2>> operator+(Array<T,R1> const& a,Array<T,R2> const& b){
	return Array<T, A_Add<T, R1, R2>>(A_Add<T,R1,R2>(a.rep(),b.rep));
}

//两个数组相乘
template<typename T,typename R1,typename R2>
Array<T,A_Multi<T,R1,R2>> operator*(Array<T,R1> const& a,Array<T,R2> const& b){
	return Array<T, A_Multi<T, R1, R2>>(A_Multi<T,R1,R2>(a.rep(),b.rep()));
}

//数组放大倍数
template<typename T,typename R2>
Array<T,A_Multi<T,A_Scalar<T>,R2>> operator*(T const& a,Array<T,R2> const& b){
	return Array<T, A_Multi<T, A_Scalar<T>, R2>>(A_Multi<T,A_Scalar<T>,R2>(A_Scalar<T>(a),b.rep()));
}


#endif//EXPRESSION_OPS_2_H