#include "../stdafx.h"

//#include "typeop.h"
#include "duo1.h"
#include "duo2.h"
#include "DuoT.h"
//返回变量Duo的第N个值
template<int N,typename A,typename B>
inline typename TypeOp<typename DuoT<N, Duo<A, B>>::ResultT>::RefT val(Duo<A,B>& d){
	return DuoValue<N, Duo<A, B>>::get(d);
}

//返回常量duo的第N个值
template<int N,typename A,typename B>
inline typename TypeOp<typename DuoT<N, Duo<A, B>>::Result>::RefConstT val(Duo<A,B> const& d){
	return DuoValue<N, Duo<A, B>>::get(d);
}

