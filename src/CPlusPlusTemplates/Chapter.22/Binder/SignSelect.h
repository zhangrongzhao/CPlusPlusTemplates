#include "../stdafx.h"

#ifndef SIGN_SELECT_H
#define SIGN_SELECT_H

#include "../Traits/IfThenElse.h"
template<int S,typename NegT,typename ZeroT,typename PosT>
struct SignSelectT{
	typedef typename IfThenElse<(S<0),
		                        NegT,
								typename IfThenElse<(S>0),PosT,ZeroT>::ResultT
	                 >::ResultT ResultT;
};

#endif//SING_SELECT_H