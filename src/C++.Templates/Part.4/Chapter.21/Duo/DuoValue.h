#include "../stdafx.h"

#ifndef DUO_VALUE_H
#define DUO_VALUE_H
#include "../Traits/typeop.h"
#include "DuoT.h"
//抽取第N个域的值。
//思路：和抽取类型的思路一致。
/*1.非Duo类型的第N个域的值==>无返回值。
  2.Duo类型：
   2.1非递归Duo类型==>第一个域值，第二个域值。
   2.2递归Duo类型==>第N个域的值。
*/

//基本模板：处理非Duo类型,各个域的类型均为void，即无返回值。
template<int N,typename T>
class DuoValue{
public:
	static void get(T&){ }
	static void get(T const&){ }
};

//特化1：处理Duo类型，非递归类型。
template<typename A,typename B>
class DuoValue<1,Duo<A,B>>{
public:
	static A& get(Duo<A,B>& duo){
		return duo.value1();
	}

	static A const& get(Duo<A,B> const& duo){
		return duo.value1();
	}
};

template<typename A, typename B>
class DuoValue<2, Duo<A, B>>{
public:
	static B& get(Duo<A, B>& duo){
		return duo.value2();
	}

	static B const& get(Duo<A, B> const& duo){
		return duo.value2();
	}
};

//特化2：处理Duo类型，递归类型。
template<int N,typename A,typename B,typename C>
class DuoValue<N,Duo<A,Duo<B,C>>>{
public:
	typedef typename TypeOp<typename DuoT<N - 1, Duo<B, C>>::ResultT>::RefT RefT;
	typedef typename TypeOp<typename DuoT<N - 1, Duo<B, C>>::ResultT>::RefConstT RefConstT;

	static RefT get(Duo<A, Duo<B, C>>& duo){
		return DuoValue<N - 1, Duo<B, C>>::get(duo.value2());
	}
	static RefConstT get(Duo<A, Duo<B, C>> const& duo){
		return DuoValue<N - 1, Duo<B, C>>::get(duo.value2());
	}
};

template<typename A,typename B,typename C>
class DuoValue<1, Duo<A, Duo<B, C>>> {
public:
	static A& get(Duo<A,Duo<B,C>>& duo){
		return duo.value1();
	}
	static A const& get(Duo<A,Duo<B,C>> const& duo){
		return duo.value1();
	}
};

template<typename A,typename B,typename C>
class DuoValue<2, Duo<A, Duo<B, C> > > {
public:
	static B& get(Duo<A,Duo<B,C>>& duo){
		return duo.value2().value1();
	}
	static B const& get(Duo<A,Duo<B,C>> const& duo){
		return duo.value2().value1();
	}
};

//封装
template<int N,typename A,typename B>
inline typename TypeOp<typename DuoT<N,Duo<A,B>>::ResultT>::RefT val(Duo<A,B>& duo){
	return DuoValue<N, Duo<A, B>>::get(duo);
}

template<int N,typename A,typename B>
inline typename TypeOp<typename DuoT<N, Duo<A, B>>::ResultT>::RefConstT val(Duo<A,B> const& duo){
	return DuoValue<N, Duo<A, B>>::get(duo);
}

void test_Duo(){
	Duo<bool, int> d;
	bool bResult = d.value1();
	bResult = val<1>(d);

	Duo<bool, Duo<int, float>> t;
	val<1>(t) = true;
	val<2>(t) = 42;
	val<3>(t) = 0.2;

	bResult = val<1>(t);
	int nResult = val<2>(t);
	float  fReuslt = val<3>(t);
}



#endif//DUO_VALUE_H