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
//	//ʹ֮�ʺϿ��
//	//enum{NumParams=FO1::NumParams};
//	//����������ֱ�۵ġ�
//	typedef typename FO2::ReturnT ReturnT;
//
//	//����Param1T,Param2T�ȣ�ʹ�ú����򻯲������͹���ĸ���
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
//	//���캯��:����Ը���const��non-const�º������в�ͬ�����
//	Composer(FO1 const& f1,FO2 const& f2):BaseMem<FO1,1>(f1),BaseMem<FO2,2>(f2){}
//	Composer(FO1 const& f2,FO2 & f2):BaseMem<FO1,1>(f1),BaseMem<FO2,2>(f2){}
//	Composer(FO1 & f1,FO2 const& f2):BaseMem<FO1,1>(f1),BaseMem<FO2,2>(f2){}
//	Composer(FO1 & f1,FO2 & f2):BaseMem<FO1,1>(f1),BaseMem<FO2,2>(f2){}
//
//	//���0�������Ķ������
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