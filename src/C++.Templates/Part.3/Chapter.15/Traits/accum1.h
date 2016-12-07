#include "../stdafx.h"

#ifndef ACCUMULATION_H
#define ACCUMULATION_H
#include "AccumulationTraits.h"
//基本模板
template<typename T>
inline typename AccumulationTraits<T>::ResultT accumulate(T const* begin,T const* end){
	typedef typename AccumulationTraits<T>::ResultT ResultT;
	ResultT total = AccumulationTraits<T>::zero();
	while (begin!=end){
		total += *begin;
		begin++;
	}
	return total;
}

//问题1：T=char是，累加计算溢出。
//问题2：AccumulationTraits<T>::ResultT在函数模板中固定，属于fixed traits.用户不能对算法进行修改。
//
#endif//ACCUMULATION_H