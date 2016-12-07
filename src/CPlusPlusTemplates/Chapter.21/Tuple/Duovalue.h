#include "../stdafx.h"

#ifndef DUO_VALUE_H
#define DUO_VALUE_H
#include "TypeOp.h"
#include "duo1.h"
#include "duo2.h"
//����ģ�壬�����T�ĵ�N��ֵ
template<int N,typename T>
class DuoValue{
public:
	static void get(T&){}//һ������£���������ֵ
	static void get(T const&){}
};

//�����ͨDuo�ĵ�һ������ػ�
template<typename A,typename B>
class DuoValue<1,Duo<A,B>> {
public :
	static A& get(Duo<A,B>& d){
		return d.v1();
	}

	static A const& get(Duo<A,B> const& d){
		return d.v1();
	}
};

//�����ͨDuo�ĵڶ�������ػ�
template<typename A,typename B>
class DuoValue<2,Duo<A,B>>{
public:
	static B& get(Duo<A,B>& d){
		return d.v2();
	}

	static B const& get(Duo<A,B> const& d){
		return d.v2();
	}
};

//��Կɵݹ�duo�ĵ�N��ֵ���ػ�
template<int N,typename A,typename B,typename C>
class DuoValue<N,Duo<A,Duo<B,C>>>{
public:
	static typename TypeOp<typename Duo<N-1, Duo<B,C>>::Result>::RefT get(Duo<A,Duo<B,C>>& d){
		return DuoValue<N-1, Duo<B,C>>::get(d.v2());
	}

	static typename TypeOp<typename Duo<N-1, Duo<B,C>>::ResultT>::RefConstT get(Duo<A,Duo<B,C>> const& d){
		return DuoValue<N-1, Duo<B,C>>::get(d.v2());
	}
};

//��Կɵݹ�Duo�ĵ�һ������ػ�
template<typename A,typename B,typename C>
class DuoValue<1,Duo<A,Duo<B,C>>>{
public:
	static A& get(Duo<A,Duo<B,C>>& d){
		return d.v1();
	}

	static A const& get(Duo<A,Duo<B,C>> const& d){
		return d.v1();
	}
};

//��Կɵݹ�Duo�ĵڶ�������ػ�
template<typename A,typename B,typename C>
class DuoValue<2, Duo<A,Duo<B,C>> > {
public:
	static B& get(Duo<A,Duo<B,C>>& d){
		return d.v2().v1();
	}

	static B const& get(Duo<A,Duo<B,C>> const& d){
		return d.v2().v1();
	}
};

#endif//DUO_VALUE_H