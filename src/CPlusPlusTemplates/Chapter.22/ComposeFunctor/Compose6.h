#include "../stdafx.h"

#ifndef COMPOSER_6_H
#define COMPOSER_6_H

//template<typename C,int N>
//class BaseMem:private C{
//public:
//	BaseMem(C& c):C(c){ }
//	BaseMem(C const& c) :C(c){ }
//};
//
//template<typename FO1,typename FO2>
//class Composer :private BaseMem<FO1, 1>, 
//	            private BaseMem<FO2,2>{
//public:
//	//使之适合框架
//	//enum{NumParams=FO1::NumParams};
//	//返回类型是直观的。
//	typedef typename FO2::ReturnT ReturnT;
//
//	//定义Param1T,Param2T等，使用宏来简化参数类型构造的复制
//#define ComposeParamT(N)                                   \
//	typedef typename FunctorParam<FO1,N>::Type Param##N##T 
//	ComposeParamT(1);
//	ComposeParamT(2);
//	ComposeParamT(3);
//	ComposeParamT(4);
//	ComposeParamT(5);
//	ComposeParamT(6);
//	ComposeParamT(7);
//	ComposeParamT(8);
//	ComposeParamT(9);
//	ComposeParamT(10);
//	ComposeParamT(11);
//	ComposeParamT(12);
//	ComposeParamT(13);
//	ComposeParamT(14);
//	ComposeParamT(15);
//	ComposeParamT(16);
//	ComposeParamT(17);
//	ComposeParamT(18);
//	ComposeParamT(19);
//#undef ComposeParamT
//	
//	//构造函数:允许对各种const和non-const仿函数进行不同的组合
//	Composer(FO1 const& f1,FO2 const& f2):BaseMem<FO1,1>(f1),BaseMem<FO2,2>(f2){}
//	Composer(FO1 const& f2,FO2 & f2):BaseMem<FO1,1>(f1),BaseMem<FO2,2>(f2){}
//	Composer(FO1 & f1,FO2 const& f2):BaseMem<FO1,1>(f1),BaseMem<FO2,2>(f2){}
//	Composer(FO1 & f1,FO2 & f2):BaseMem<FO1,1>(f1),BaseMem<FO2,2>(f2){}
//
//	//针对0个参数的额函数调用
//	ReturnT operator()(){
//		return BaseMem<FO2, 2>::operator()(BaseMem<FO1,1>()());
//	}
//
//	ReturnT operator()(typename ForwardParamT<Param1T>::Type v1){
//		return BaseMem<FO2, 2>::operator()(BaseMem<FO1,1>()(v1));
//	}
//
//	ReturnT operator()(typename ForwardParamT<Param1T>::Type v1,
//		               typename ForwardParamT<Param2T>::Type v2){
//		return BaseMem<FO2, 2>::operator()(BaseMem<FO1,1>::operator()(v1,v2));
//	}
//};
//
//template<typename FO1,typename FO2>
//Composer<FO1, FO2> compose(FO1 fo1,FO2 fo2){
//	return Composer<FO1,FO2>(fo1,fo2);
//}

#endif//COMPOSER_6_H