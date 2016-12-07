#include "../stdafx.h"

#ifndef EXPRESSIONS_OPS_H
#define EXPRESSIONS_OPS_H
#include <cassert>
#include "A_Traits.h"
//使用临时变量，6000：read；4000：wirte，造成性能低下。
//改进建议：避免使用临时变量。见到赋值运算符时，计算表达式的值。之前，转换为表达式模板。

//x=1.2*x+x*y转换为表达式模板
//期望的目标表达式模板=>A_Add<A_Multi<A_Scalar<double>,Array<double> >,
//                          A_Multi<Array<double>,Array<double>>
//                         >;


//两个数值数组相加
template<typename T,typename OP1,typename OP2>
class A_Add{
private:
	 typename A_Traits<OP1>::ExprRef op1;//第一个操作数
	 typename A_Traits<OP2>::ExprRef op2;//第二个操作数
public:
	A_Add(OP1 const& a,OP1 const& b):op1(a),op2(b){ }

	//在求值的时候计算和
	T operator[](size_t idx) const{
		return op1[idx] + op2[idx];
	}

	//size计算最大容量。
	size_t size() const(){
		assert(op1.size()==0||op2.size()==0||op1.size()==op2.size());
		return op1.size() != 0 ? op1.size() : op2.size();
	}
};

//两个数值数组相乘
template<typename T,typename OP1,typename OP2>
class A_Multi{
private:
	typename A_Traits<OP1>::ExprRef op1;
	typename A_Traits<OP2>::ExprRef op2;
public:
	//构造函数，指向操作数的引用。
	A_Multi(OP1 const& a,OP2 const& b) :op1(a), op2(b){	}

	//在求值的时候计算乘积
	T operator[](size_t idx){
		return op1[idx] * op2[idx];
	}

	//计算最大容量
	size_t size() const{
		assert(op1.size()==0||op2.size()==0||op1.size()==op2.size());
		return op1.size() != 0 ? op1.size() : op2.size();
	}
};

template<typename T,typename A1,typename A2>
class A_Subscript{
private:
	A1 const& a1;
	A2 const& a2;
public:
	A_Subscript(A1 const& a,A2 const& b) :a1(a), a2(b){ }

	T operator[](size_t idx) const{
		return a1[a2[idx]];
	}

	T& operator[](size_t idx){
		return a1[a2[idx]];
	}

	size_t size() const{
		return a2.size();
	}
};

#endif//EXPRESSIONS_OPS_H