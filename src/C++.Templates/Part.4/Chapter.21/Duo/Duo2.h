#include "../stdafx.h"
#ifndef DUO_2_H
#define DUO_2_H
template<typename T1,typename T2>
class Duo;

//递归：可容纳为多个域
template<typename A, typename B,typename C>
class Duo<A,Duo<B,C>>{
private:
	typedef A T1;//第一个域的类型
	typedef Duo<B,C> T2;//第二个域的类型
private:
	T1 v1;//第一个域的值
	T2 v2;//第二个域的值。
public:
	enum{ N = Duo<B,C>::N+1};//域的个数。
public:
	Duo() :v1(), v2(){ }
	Duo(T1 const& v1, T2 const& v2) :v1(v1), v2(v2){ }

	//构造期间，进行类型转换。
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

//递归出口
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