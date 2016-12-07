#include "../stdafx.h"

#ifndef SUM_POLICY_H
#define SUM_POLICY_H

//¿€º∆«Û∫Õ
//template<typename ResultT, typename T>
//class SumPolicy{
//public:
//	static void accumulate(ResultT& total,T const& value){
//		 total += value;
//	}
//};

template<typename Traits>
class SumPolicy{
public:
	typedef typename Traits::ElementT ElementT;
	typedef typename Traits::ResultT ResultT;
	static void accumulate(ElementT const& value, ResultT& total=Traits::zero()){
		total += value;
	}
};

//template<bool use_compound_op=true>
//class SumPolicy{
//public:
//	template<typename T1,typename T2>
//	static void accumulate(T1& total,T2 const& value){
//		total += value;
//	}
//};
//
//template<>
//class SumPolicy<false>{
//	template<typename T1, typename T2>
//	static void accumulate(T1& total,T2 const& value){
//		total = total + value;
//	}
//};

#endif//SUM_POLICY_H