#include "../stdafx.h"
#include "promotionTrait.h"

#define MK_PROMOTION(T1,T2,Tr)\
template<>                    \
class Promotion<T1, T2>{      \
public:                       \
	typedef Tr ResultT;       \
};                            \
	                          \
template<>                    \
class Promotion<T2,T1>{       \
public:                       \
	typedef Tr ResultT;       \
};                            \