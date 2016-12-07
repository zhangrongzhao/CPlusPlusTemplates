#include "../stdafx.h"
#ifndef ACCUM_H
#define ACCUM_H
#include "accumtraits4.h"

template<typename T,
	     typename AT=AccumulationTraits<T> 
>
class Accum{
public:
	static typename AT::AccT accum(T const* begin,T const* end){
		typename AT::AccT total = AT::zero();
		while(begin!=end){
			total += *begin;
			begin++;
		}
		return total;
	}
};

template<typename T>
inline typename AccumulationTraits<T>::AccT accum(T const* begin,T const* end){
	return Accum<T>::accum(begin,end);
}

template<typename Traits,typename T>
inline typename Traits::AccT accum(T const* begin,T const* end){
	return Accum<T, Traits>::accum(begin,end);
}
#endif//ACCUM_H