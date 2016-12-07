#include "../stdafx.h"

#ifndef COMPOSE_5_H
#define COMPOSE_5_H

#include "ForwardParam.h"
template<typename C,int N>
class BaseMem :public C{
public:
	BaseMem(C& c):C(c){ }
	BaseMem(C const& c):C(c){ }
};

template<typename FO1,typename FO2>
class Composer :private BaseMem<FO1,1>, private BaseMem<FO2,2>{
public:
	//ʹ֮�ʺϿ��
	enum{NumParams=FO1::NumParams};
	typedef typename FO2::ReturnT ReturnT;
	typedef typename FO1::Param1T Param1T;

	//���캯������ʼ����������
	Composer(FO1 fo1,FO2 fo2) :BaseMem<FO1, 1>(f1), BaseMem<FO2, 2>(f2){ }

	//�������ã����������Ƕ�׵���
	ReturnT operator()(typename ForwardParamT<Param1T>::Type v){
		return BaseMem<FO2, 2>::operator()(BaseMem<FO1,1>::operator()(v));
	}
};

template<typename FO1,typename FO2>
Composer<FO1, FO2> compose(FO1 fo1,FO2 fo2){
	return Composer<FO1, FO2>(fo1,fo2);
}

#endif//COMPOSE_5_H