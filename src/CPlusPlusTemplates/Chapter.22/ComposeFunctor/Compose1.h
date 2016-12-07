#include "../stdafx.h"

#ifndef COMPOSE_FUNCTOR_H
#define COMPOSE_FUNCTOR_H
#include "Compose4.h"

template<typename FO1,typename FO2>
class Composer :private BaseMem<FO1, 1>, 
	            private BaseMem<FO2,2>{//FO1,FO2无状态的话，可以不为成员仿函数分配空间，可以使用空基类优化。
//private:
//	FO1 fo1;//要调用的第一个/内部的函数对象
//	FO2 fo2;//要调用的第二个/外部的函数对象
public:
	//用于初始化两个函数对象的构造函数
	Composer(FO1 f1,FO2 f2):BaseMem<FO1,1>(f1),BaseMem<FO2,2>(f2){ }

	//"函数调用"：函数对象的嵌套调用
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