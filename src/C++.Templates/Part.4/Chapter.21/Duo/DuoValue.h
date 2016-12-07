#include "../stdafx.h"

#ifndef DUO_VALUE_H
#define DUO_VALUE_H
#include "../Traits/typeop.h"
#include "DuoT.h"
//��ȡ��N�����ֵ��
//˼·���ͳ�ȡ���͵�˼·һ�¡�
/*1.��Duo���͵ĵ�N�����ֵ==>�޷���ֵ��
  2.Duo���ͣ�
   2.1�ǵݹ�Duo����==>��һ����ֵ���ڶ�����ֵ��
   2.2�ݹ�Duo����==>��N�����ֵ��
*/

//����ģ�壺�����Duo����,����������;�Ϊvoid�����޷���ֵ��
template<int N,typename T>
class DuoValue{
public:
	static void get(T&){ }
	static void get(T const&){ }
};

//�ػ�1������Duo���ͣ��ǵݹ����͡�
template<typename A,typename B>
class DuoValue<1,Duo<A,B>>{
public:
	static A& get(Duo<A,B>& duo){
		return duo.value1();
	}

	static A const& get(Duo<A,B> const& duo){
		return duo.value1();
	}
};

template<typename A, typename B>
class DuoValue<2, Duo<A, B>>{
public:
	static B& get(Duo<A, B>& duo){
		return duo.value2();
	}

	static B const& get(Duo<A, B> const& duo){
		return duo.value2();
	}
};

//�ػ�2������Duo���ͣ��ݹ����͡�
template<int N,typename A,typename B,typename C>
class DuoValue<N,Duo<A,Duo<B,C>>>{
public:
	typedef typename TypeOp<typename DuoT<N - 1, Duo<B, C>>::ResultT>::RefT RefT;
	typedef typename TypeOp<typename DuoT<N - 1, Duo<B, C>>::ResultT>::RefConstT RefConstT;

	static RefT get(Duo<A, Duo<B, C>>& duo){
		return DuoValue<N - 1, Duo<B, C>>::get(duo.value2());
	}
	static RefConstT get(Duo<A, Duo<B, C>> const& duo){
		return DuoValue<N - 1, Duo<B, C>>::get(duo.value2());
	}
};

template<typename A,typename B,typename C>
class DuoValue<1, Duo<A, Duo<B, C>>> {
public:
	static A& get(Duo<A,Duo<B,C>>& duo){
		return duo.value1();
	}
	static A const& get(Duo<A,Duo<B,C>> const& duo){
		return duo.value1();
	}
};

template<typename A,typename B,typename C>
class DuoValue<2, Duo<A, Duo<B, C> > > {
public:
	static B& get(Duo<A,Duo<B,C>>& duo){
		return duo.value2().value1();
	}
	static B const& get(Duo<A,Duo<B,C>> const& duo){
		return duo.value2().value1();
	}
};

//��װ
template<int N,typename A,typename B>
inline typename TypeOp<typename DuoT<N,Duo<A,B>>::ResultT>::RefT val(Duo<A,B>& duo){
	return DuoValue<N, Duo<A, B>>::get(duo);
}

template<int N,typename A,typename B>
inline typename TypeOp<typename DuoT<N, Duo<A, B>>::ResultT>::RefConstT val(Duo<A,B> const& duo){
	return DuoValue<N, Duo<A, B>>::get(duo);
}

void test_Duo(){
	Duo<bool, int> d;
	bool bResult = d.value1();
	bResult = val<1>(d);

	Duo<bool, Duo<int, float>> t;
	val<1>(t) = true;
	val<2>(t) = 42;
	val<3>(t) = 0.2;

	bResult = val<1>(t);
	int nResult = val<2>(t);
	float  fReuslt = val<3>(t);
}



#endif//DUO_VALUE_H