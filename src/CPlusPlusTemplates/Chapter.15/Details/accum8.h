#include "../stdafx.h"

#ifndef ACCUM_H
#define ACCUM_H
#include "accumtraits4.h"
#include "sumpolicy2.h"
template<typename T,
	     template<typename,typename> class Policy=SumPolicy,
	     typename Traits=AccumulationTraits<T>
>
class Accum{
public:
	typedef typename Traits::AccT AccT;
	static AccT accum(T const* begin,T const* end){
		AccT total = Traits::zero();
		while(begin!=end){
			Policy<AccT, T>::accum(total,*begin);
			begin++;
		}
		return total;
	}
};

#endif//ACCUM_H

