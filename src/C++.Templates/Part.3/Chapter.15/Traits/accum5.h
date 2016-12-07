#include "../stdafx.h"
#ifndef ACCUM_5_H
#define ACCUM_5_H
//²ÎÊý»¯Trait
#include "AccumulationTraits.h"
#include "..\Policy\SumPolicy.h"
#include "..\Policy\MultPolicy.h"

template<typename T,
	     template<typename> class Policy = SumPolicy,
	     typename Traits = AccumulationTraits<T> >
class Accumulation{
public:
	typedef typename Traits::ResultT ResultT;
	static ResultT Accumulate(T const* begin,T const* end){
		ResultT total = Traits::zero();
		while (begin!=end){
			Policy<Traits>::accumulate(*begin, total);
			begin++;
		}
		return total;
	}
};

template<typename T>
inline typename AccumulationTraits<T>::ResultT accumulate(T const* begin, T const* end){
	return Accumulation<T>::Accumulate(begin,end);
}

//template<template<typename ResultT,typename T> class Policy, 
//	     typename Traits, 
//		 typename T>
//inline typename Traits::ResultT accumulate(T const* begin,T const* end){
//	return Accumulation<T, Policy,Traits>::Accumulate(begin, end);
//}


#endif//ACCUM_5_H