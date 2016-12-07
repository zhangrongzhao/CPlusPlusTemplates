#include "../stdafx.h"

#ifndef ARRAY_OP_H
#define ARRAY_OP_H
#include "SArray.h"

//数值数组操作数
template<typename T,typename Rep=SArray<T>>
class Array{
private:
	Rep expr_rep;//访问数组的数据。
public:
	//显式创建具有初始大小的数组
	explicit Array(size_t size) :expr_reg(size){ }

	//根据其他类型创建数组
	Array(Rep const& rb):expr_rep(rb){ }

	//同类型的赋值运算符
	Array<T>& operator=(Array<T> const& b){
		assert(size()==b.size());
		for (size_t idx = 0; idx < size();idx++){
			expr_rep[idx] = b[idx];
		}
		return *this;
	}

	//不同类型的赋值运算符
	template<typename T2,typename Rep2>
	Array<T>& operator=(Array<T2,Rep2> const& b){
		assert(size()==b.size());
		for (size_t idx = 0; idx < size();idx++){
			expr_rep[idx] = b[idx];
		}
		return *this;
	}


	T operator[](size_t idx){
		assert(idx<b.size());
		return expr_rep[idx];
	}

	T& operator[](size_t idx){
		assert(idx<size());
		return expr_rep[idx];
	}

	size_t size() const{
		return expr_rep.size();
	}

	Rep const& rep() const{
		return expr_rep;
	}

	Rep& rep(){
		return expr_rep;
	}
};


#endif//ARRAY_OP_H