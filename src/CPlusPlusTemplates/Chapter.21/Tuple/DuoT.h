#include "../stdafx.h"

#ifndef DUO_TYPE_H
#define DUO_TYPE_H
#include "duo1.h"
#include "duo2.h"
//用于获取duo的第N个域的类型的基本模板
template<int N,typename T>
class DuoT{
public:
	typedef void ResultT;//一般情况下，结构类型是void
};

//针对普通duo的第一个域的特化
template<typename A,typename B>
class DuoT<1,Duo<A,B>>{
public:
	typedef A ResultT;
};

//针对普通duo第2个域的特化
template<typename A,typename B>
class DuoT<2,Duo<A,B>>{
public:
	typedef B ResultT;
};

//针对可递归Duo第N个域的类型的特化
template<int N,typename A,typename B,typename C>
class DuoT<N,Duo<A,Duo<B,C>>>{
public:
	typedef typename DuoT<N - 1, Duo<B, C>>::ResultT ResultT;
};

//针对可递归duo第一个域的特化
template<typename A,typename B,typename C>
class DuoT<1, Duo<A, Duo<B, C>> > {
public:
	typedef A ResultT;
};

//针对可递归duo的第二个域的局部特化
template<typename A,typename B,typename C>
class DuoT<2,Duo<A,Duo<B,C>>>{
public:
	typedef B ResultT;
};

#endif//DUO_TYPE_H