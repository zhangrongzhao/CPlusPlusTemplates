#include "../stdafx.h"

#ifndef EXPRESSION_ARRAY
#define EXPRESSION_ARRAY
#include <stddef.h>
#include <cassert>
#include "sarray1.h"

template<typename T,typename Rep=SArray<T>>
class Array{
private:
	Rep expr_rep;//(访问)数组的数据
public:
	//创建具有初始大小的数组
	explicit Array(size_t s):expr_rep(s){
	   
	}

	//根据其他可能的表示来创建数组
	Array(Rep const& rb):expr_rep(rb){
	   
	}

	//针对相同类型的赋值运算符
	Array& operator=(Array const& b){
		assert(size()==b.size());
		for (size_t idx = 0; idx < b.size();++idx){
			expr_rep[idx] = b[idx];
		}
		return *this;
	}

	//针对不同类型的赋值运算符
	template<typename T2,typename Rep2>
	Array& operator=(Array<T2,Rep2> const& b){
		assert(size()==b.size());
		for (size_t idx = 0; idx < size();idx++){
			expr_rep[idx] = b[idx];
		}
		return *this;
	}

	//size是所表示数据的大小
	size_t size() const{
		return expr_rep.size();
	}

	//分别针对常量和变量的索引（下标）运算符
	T operator[](size_t idx) const{
		assert(idx < size());
		return expr_rep[idx];
	}

	T& operator[](size_t idx){
		assert(idx<size());
		return expr_rep[idx];
	}

	//返回数组现在所表示的对象
	Rep const& rep() const{
		return expr_rep;
	}

	Rep& rep(){
		return expr_rep;
	}
};

#endif//EXPRESSION_ARRAY

