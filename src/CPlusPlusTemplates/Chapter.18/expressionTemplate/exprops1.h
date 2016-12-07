#include "../stdafx.h"

#ifndef EXPR_OPS_1
#define EXPR_OPS_1

#include <stddef.h>
#include <cassert>
#include "exprops1a.h"

//包含了一个辅助class trait template.从而根据不同情况，判断究竟是以“传值”的方式，还是以“传引用”的方式来引用的对应的“表达式模板节点”

//表示两个操作数之和的对象的所属类
template<typename T,typename OP1,typename OP2>
class A_Add{
private:
	typename A_Traits<OP1>::ExprRef op1;//第一个操作数
	typename A_Traits<OP2>::ExprRef op2;//第二个操作数
public:
	//构造函数，用于初始化指向操作数的引用
	A_Add(OP1 const& a,OP2 const& b):op1(a),op2(b){
	    
	}

	//在求值的时候计算和
	T operator[](size_t idx) const{
		return op1[idx] + op2[idx];
	}

	//size代表最大的容量
	size_t size() const{
		assert(op1.size()==0||op2.size()==0||op1.size()==op2.size());
		return op1.size() != 0 ? op1.size() : op2.size();
	}
};

//代表两个对象之积的对象的所属类
template<typename T,typename OP1,typename OP2>
class A_Mult{
private:
	typename A_Traits<OP1>::ExprRef op1;//第一个操作数
	typename A_Traits<OP2>::ExprRef op2;//第二个操作数
public:
	//构造函数，用于初始化对象指向操作数的引用
	A_Mult(OP1 const& a, OP2 const& b) :op1(a), op2(b){
	
	}

	//在求值的时候计算积
	T operator[](size_t idx) const{
		return op1[idx] * op2[idx];
	}

	//size表示最大的容量
	size_t size() const{
		assert(op1.size()==0||op2.size()==0||op1.size()==op2.size());
		return op1.size() != 0 ? op1.size() : op2.size();
	}
};


#endif//EXPR_OPS_1