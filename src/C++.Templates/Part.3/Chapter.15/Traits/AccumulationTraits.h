#include "../stdafx.h"
#ifndef ACCUMULATION_TRAITS_H
#define ACCUMULATION_TRATTS_H

//问题1：T=char是，累加计算溢出。
//修改建议:结果类型由模板参数T相关。可以根据模板参数T的类型，进行特化，获取相关计算结果的类型。
template<typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<char>{
public:
	typedef char ElementT;
	typedef int ResultT;
	static ResultT zero(){
		return 0;
	};
};

template<>
class AccumulationTraits<short>{
public:
	typedef short ElementT;
	typedef int ResultT;
	static ResultT zero(){
		return 0;
	};
};

template<>
class AccumulationTraits<int>{
public:
	typedef int ElementT;
	typedef long ResultT;
	static ResultT zero(){
		return 1;
	};
};

template<>
class AccumulationTraits<unsigned int>{
public:
	typedef unsigned int ElementT;
	typedef unsigned long ResultT;
	static ResultT zero(){
		return 0;
	};
};

template<>
class AccumulationTraits<float>{
public:
	typedef float ElementT;
	typedef double ResultT;
	static ResultT zero(){
		return 0;
	};
};

//.....其他类型。
#endif//ACCUMULATION_TRAITS_H

