#include "../stdafx.h"

#ifndef TUPLE_H
#define TUPLE_H
#include "duo1.h"
#include "duo2.h"
#include "duo5.h"
#include "DuoT.h"
#include "Duovalue.h"
#include "TypeOp.h"

//���ڴ������ò���������
class NullT{};

//һ������£�Tuple<>��������"���ٰ���һ��NullT����һ��Tuple<>"
template<typename P1,
         typename P2=NullT,
		 typename P3=NullT,
		 typename P4=NullT,
		 typename P5=NullT>
class Tuple :public Duo<P1,typename Tuple<P2,P3,P4,P5,NullT>::BaseT >{
public:
	typedef Duo<P1, typename Tuple<P2, P3, P4, P5, NullT>::BaseT> BaseT;
	
	//���캯��
	Tuple(){}
	Tuple(TypeOp<P1>::RefConstT a1,
	      TypeOp<P2>::RefConstT a2,
		  TypeOp<P3>::RefConstT a3 = NullT(),
		  TypeOp<P4>::RefConstT a4 = NullT(),
		  TypeOp<p5>::RefConstT a5 = NullT()):Base(a1,Tuple<P2,P3,P4,P5,NullT>(a2,a3,a4,a5)){

	}
};

//������ֹ�ݹ���ػ�
template<typename P1,typename P2>
class Tuple<P1,P2,NullT,NullT,NullT>:public Duo<P1,P2>{
public:
	typedef Duo<P1, P2> BaseT;
	Tuple(){}
	Tuple(TypeOp<P1>::RefConstT a1,
		  TypeOp<P2>::RefConstT a2,
		  TypeOp<P3>::RefConstT a3 = NullT(),
		  TypeOp<P4>::RefConstT a4 = NullT(),
		  TypeOp<P5>::RefConstT a5 = NullT()):Base<a1,a2>{
	}
};

//���Singletons���ػ�
template<typename P1>
class Tuple<P1,NullT,NullT,NullT,NullT>:public Duo<P1,void>{
public:
	typedef Duo<P1, void> BaseT;
	Tuple(){}
	Tuple(TypeOp<P1>::RefConstT a1,
		  TypeOp<P2>::RefConstT){}
};

#endif//TUPLE_H