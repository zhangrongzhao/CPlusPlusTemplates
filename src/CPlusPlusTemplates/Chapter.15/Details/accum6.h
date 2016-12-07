#include "../stdafx.h"
#include "accumtraits4.h"
#include "sumpolicy1.h"

template<typename T,
	     typename Policy=SumPolicy,
		 typename Traits=AccumulationTraits<T>
> 
class Accum{
public:
	typedef typename Traits::AccT AccT;
	static AccT accum(T const* begin,T const* end){
		AccT total = Traits::zero();
		while (begin!=end){
			Policy::accumulate(total,*begin);
			begin++;
		}
		return total;
	}
};
