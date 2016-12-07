#include "../stdafx.h"

#ifndef TUPLE_H
#define TUPLE_H
#include "../Traits/typeop.h"
#include "../Duo/Duo.h"
#include "../Duo/Duo2.h"
#include "../Duo/DuoValue.h"
class NullT{};

template<typename P1,
         typename P2=NullT,
		 typename P3=NullT,
		 typename P4=NullT,
		 typename P5=NullT>
class Tuple:public Duo<P1,typename Tuple<P2,P3,P4,P5,NullT>::BaseT >{
public:
	typedef Duo<P1,typename Tuple<P2,P3,P4,P5,NullT>::BaseT> BaseT;
	Tuple(){}
	Tuple(typename TypeOp<P1>::RefConstT a1,
		typename TypeOp<P2>::RefConstT a2,
		typename TypeOp<P3>::RefConstT a3 = NullT(),
		typename TypeOp<P4>::RefConstT a4 = NullT(),
		typename TypeOp<P5>::RefConstT a5 = NullT()
		) :BaseT(a1, Tuple<P2, P3, P4, P5, NullT>(a2, a3, a4, a5)){
	}
};

//�ݹ���ڣ�

template<typename P1,typename P2>
class Tuple<P1,P2,NullT,NullT,NullT>:public Duo<P1,P2>{
public:
	typedef Duo<P1, P2> BaseT;
	Tuple(){}
	Tuple(typename TypeOp<P1>::RefConstT a1,
		typename TypeOp<P2>::RefConstT a2,
		typename TypeOp<NullT>::RefConstT a3 = NullT(),
		typename TypeOp<NullT>::RefConstT a4 = NullT(),
		typename TypeOp<NullT>::RefConstT a5 = NullT())
		:BaseT(a1,a2){
	}
};
template<typename P1>
class Tuple<P1, NullT, NullT, NullT, NullT> :public Duo<P1, void>{
public:
	typedef Duo<P1, void> BaseT;
	Tuple(){}
	Tuple(typename TypeOp<P1>::RefConstT a1,
		typename TypeOp<NullT>::RefConstT a2 = NullT(),
		typename TypeOp<NullT>::RefConstT a3 = NullT(),
		typename TypeOp<NullT>::RefConstT a4 = NullT(),
		typename TypeOp<NullT>::RefConstT a5 = NullT())
		:BaseT(a1){
	}
};


template<typename T1>
inline Tuple<T1> make_tuple(T1 const& a1){
	return Tuple<T1>(a1);
}

template<typename T1,typename T2>
inline Tuple<T1, T2> make_tuple(T1 const& a1,T2 const& a2){
	return Tuple<T1, T2>(a1,a2);
}

template<typename T1, typename T2,typename T3>
inline Tuple<T1, T2,T3> make_tuple(T1 const& a1, T2 const& a2,T3 const& a3){
	return Tuple<T1, T2,T3>(a1, a2,a3);
}

template<typename T1, typename T2, typename T3,typename T4>
inline Tuple<T1, T2, T3,T4> make_tuple(T1 const& a1, T2 const& a2, T3 const& a3,T4 const& a4){
	return Tuple<T1, T2, T3,T4>(a1, a2, a3,a4);
}

template<typename T1, typename T2, typename T3, typename T4,typename T5>
inline Tuple<T1, T2, T3, T4,T5> make_tuple(T1 const& a1, T2 const& a2, T3 const& a3, T4 const& a4,T5 const& a5){
	return Tuple<T1, T2, T3, T4,T5>(a1, a2, a3, a4,a5);
}


void test_tuple(){
	//Tuple<int> t1;
	//val<1>(t1) += 42;
	//int nResult = t1.value1();

	//Tuple<bool, int> t2;
	//bool bResult = val<1>(t2);
	//bResult = t2.value1();

	Tuple<bool, int, double> t3;
	//val<1>(t3) = true;
	//val<2>(t3) = 42;
	//val<3>(t3) = 0.2;


	//t3 = make_tuple(false,23,13.13);

	//bool b1 = val<1>(t3);
	//int n1 = val<2>(t3);
	//double d1 = val<3>(t3);

	Tuple<bool, int, float, double> t4;
	val<4>(t4);
	t4.value2().value2().value2();
}

#endif//TUPLE_H