#include "../stdafx.h"
#ifndef ACCUM_H
#define ACCUM_H
#include "accumtraits2.h"

template<typename T>
inline typename AccumulationTraits<T>::AccT accum(T const* begin,T const* end){
	typedef typename AccumulationTraits<T>::AccT AccT;
	AccT total = AccT();//����ֵ��������һ��Ԫ�����͵�trait
	while (begin!=end){
		total += *begin;
		begin++;
	}
	return total;
}

#endif //ACCUM_H