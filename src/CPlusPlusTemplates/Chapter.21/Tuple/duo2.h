#include "../stdafx.h"

#ifndef DUO_2_H
#define DUO_2_H
#include "duo1.h"

//�ɵݹ�Duo
template<typename A, typename B,typename C>
class Duo<A,Duo<B,C>>{
public:
	typedef A T1;//��һ���������
	typedef Duo<B, C> T2; //�ڶ����������
	enum { N = Duo<B, C>::N + 1; };//��ĸ���
private:
	T1 value1;//��һ�����ֵ
	T2 value2;//�ڶ������ֵ
public:
	//���캯��
	Duo() :value1(), value2(){ }
	Duo(T1 const& a, T2 const& b) :value1(a), value2(b){ }

	//�����ڹ����ڼ䣬������ʽ������ת��
	template<typename U1, typename U2>
	Duo(Duo<U1, U2> const& d) : value1(d.v1()), value2(d.v2()){ }

	//�����ڸ�ֵ�ڼ䣬������ʽ������ת��
	template<typename U1, typename U2>
	Duo<T1, T2>& operator=(Duo<U1, U2> const& d){
		value1 = d.value1;
		value2 = d.value2;
		return *this;
	}

	//���ڷ�����ĺ���������ʺ�����
	T1& v1(){ return value1; }
	T1 const& v1() const{ return value1; }
	T2& v2(){ return value2; }
	T2 const& v2() const{ return value2; }
};

//�ݹ�Duo�ĳ��ڣ����ֻ����һ�����Duo<>�ľֲ��ػ�
template<typename A>
class Duo<A,void>{
public:
	typedef A T1;
	typedef void T2;
	enum{N=1};
private:
	T1 value1;
public:
	//���캯��
	Duo() :value1(){}
	Duo(T1 const& a) :value1(a){}

	//����ʺ���
	T1 const& v1() const{ return value1; }
	T1& v1(){ return value1; }

	void v2(){}
	void v2() const{}
};

#endif//DUO_2_H