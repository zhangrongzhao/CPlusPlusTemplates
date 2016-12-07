#include "../stdafx.h"
#ifndef DUO_2_H
#define DUO_2_H
template<typename T1,typename T2>
class Duo;

//�ݹ飺������Ϊ�����
template<typename A, typename B,typename C>
class Duo<A,Duo<B,C>>{
private:
	typedef A T1;//��һ���������
	typedef Duo<B,C> T2;//�ڶ����������
private:
	T1 v1;//��һ�����ֵ
	T2 v2;//�ڶ������ֵ��
public:
	enum{ N = Duo<B,C>::N+1};//��ĸ�����
public:
	Duo() :v1(), v2(){ }
	Duo(T1 const& v1, T2 const& v2) :v1(v1), v2(v2){ }

	//�����ڼ䣬��������ת����
	template<typename U1, typename U2>
	Duo(Duo<U1, U2> const& d) : v1(d.value1()), v2(d.value2()){}

	template<typename U1, typename U2>
	Duo<T1, T2>& operator=(Duo<U1, U2> const& d){
		v1 = d.value1();
		v2 = d.value2();
		return *this;
	}

	T1& value1(){
		return this->v1;
	}
	T1 const& value1() const{
		return this->v1;
	}

	T2& value2() {
		return this->v2;
	}
	T2 const& value2() const{
		return this->v2;
	}

};

//�ݹ����
template<typename A>
class Duo<A,void> {
private:
	typedef A T1;
	typedef void T2;
public:
	enum{N=1};
private:
	T1 v1;
public:
	Duo() :v1(){}
	Duo(T1 const& a) :v1(a){}

	T1& value1(){ return v1;}
	T1 const& value1() const{ return v1; }

	void value2(){}
	void value2() const{ }
};


#endif//DUO_2_H