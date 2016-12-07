#include "../stdafx.h"

#ifndef COMPOSE_FUNCTOR_H
#define COMPOSE_FUNCTOR_H
#include "Compose4.h"

template<typename FO1,typename FO2>
class Composer :private BaseMem<FO1, 1>, 
	            private BaseMem<FO2,2>{//FO1,FO2��״̬�Ļ������Բ�Ϊ��Ա�º�������ռ䣬����ʹ�ÿջ����Ż���
//private:
//	FO1 fo1;//Ҫ���õĵ�һ��/�ڲ��ĺ�������
//	FO2 fo2;//Ҫ���õĵڶ���/�ⲿ�ĺ�������
public:
	//���ڳ�ʼ��������������Ĺ��캯��
	Composer(FO1 f1,FO2 f2):BaseMem<FO1,1>(f1),BaseMem<FO2,2>(f2){ }

	//"��������"�����������Ƕ�׵���
	/*double operator()(double v){
		return fo2(fo1(v));
	}*/

	double operator()(double v){
		return BaseMem<FO2,2>::operator()(BaseMem<FO1,1>::operator()(v));
	}
};

template<typename FO1,typename FO2>
inline Composer<FO1, FO2> compose(FO1 fo1,FO2 fo2){
	return Composer<FO1,FO2>(fo1,fo2);
}
#endif//COMPOSE_FUNCTOR_H