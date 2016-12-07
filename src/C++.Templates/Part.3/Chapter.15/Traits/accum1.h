#include "../stdafx.h"

#ifndef ACCUMULATION_H
#define ACCUMULATION_H
#include "AccumulationTraits.h"
//����ģ��
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

//����1��T=char�ǣ��ۼӼ��������
//����2��AccumulationTraits<T>::ResultT�ں���ģ���й̶�������fixed traits.�û����ܶ��㷨�����޸ġ�
//
#endif//ACCUMULATION_H