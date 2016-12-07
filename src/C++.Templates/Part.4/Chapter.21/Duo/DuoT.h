#include "../stdafx.h"

#ifndef DUO_TYPE_H
#define DUO_TYPE_H
#include "Duo.h"
//获取第N个域的类型。
//获取类型的思路：
/*1.非Duo类型的第N个域的类型==>void
  2.Duo类型：
    2.1非递归Duo类型==>第一个域类型，第二个域类型。
	2.2递归Duo类型==>第N个域的类型。
*/


//基本模板:处理非Duo类型，则每个域为void类型。
template<int N,typename T>
class DuoT{
public:
	typedef void ResultT;
};

//特化1：处理Duo非递归类型。只有两个域。
//获取第一个域类型
template<typename A,typename B>
class DuoT<1, Duo<A, B>> {
public:
	typedef A ResultT;
};
//获取第二个域类型。
template<typename A,typename B>
class DuoT <2, Duo<A, B>> {
public:
	typedef B ResultT;
};


//特化2：处理Duo递归类型。
template<int N,typename A,typename B,typename C>
class DuoT<N,Duo<A,Duo<B,C>>>{
public:
	typedef typename DuoT<N - 1, Duo<B, C>>::ResultT ResultT;
};

//为特化2，寻找递归出口。
template<typename A,typename B,typename C>
class DuoT<1,Duo<A,Duo<B,C>>>{
public:
	typedef A ResultT;
};

template<typename A,typename B,typename C>
class DuoT<2,Duo<A,Duo<B,C>> > {
public:
	typedef B ResultT;
};

#endif//DUO_TYPE_H