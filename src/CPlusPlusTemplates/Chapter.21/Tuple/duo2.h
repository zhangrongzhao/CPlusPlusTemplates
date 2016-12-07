#include "../stdafx.h"

#ifndef DUO_2_H
#define DUO_2_H
#include "duo1.h"

//可递归Duo
template<typename A, typename B,typename C>
class Duo<A,Duo<B,C>>{
public:
	typedef A T1;//第一个域的类型
	typedef Duo<B, C> T2; //第二个域的类型
	enum { N = Duo<B, C>::N + 1; };//域的个数
private:
	T1 value1;//第一个域的值
	T2 value2;//第二个域的值
public:
	//构造函数
	Duo() :value1(), value2(){ }
	Duo(T1 const& a, T2 const& b) :value1(a), value2(b){ }

	//用于在构造期间，进行隐式的类型转换
	template<typename U1, typename U2>
	Duo(Duo<U1, U2> const& d) : value1(d.v1()), value2(d.v2()){ }

	//用于在赋值期间，进行隐式的类型转换
	template<typename U1, typename U2>
	Duo<T1, T2>& operator=(Duo<U1, U2> const& d){
		value1 = d.value1;
		value2 = d.value2;
		return *this;
	}

	//用于访问域的函数（域访问函数）
	T1& v1(){ return value1; }
	T1 const& v1() const{ return value1; }
	T2& v2(){ return value2; }
	T2 const& v2() const{ return value2; }
};

//递归Duo的出口：针对只含有一个域的Duo<>的局部特化
template<typename A>
class Duo<A,void>{
public:
	typedef A T1;
	typedef void T2;
	enum{N=1};
private:
	T1 value1;
public:
	//构造函数
	Duo() :value1(){}
	Duo(T1 const& a) :value1(a){}

	//域访问函数
	T1 const& v1() const{ return value1; }
	T1& v1(){ return value1; }

	void v2(){}
	void v2() const{}
};

#endif//DUO_2_H