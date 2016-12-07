#include "../stdafx.h"
#ifndef DUO_H
#define DUO_H

template<typename T1,typename T2>
class Duo{
private:
	typedef T1 Type1;//第一个域的类型
	typedef T2 Type2;//第二个域的类型
private:
	T1 v1;//第一个域的值
	T2 v2;//第二个域的值。
public:
	enum{ N = 2 };//域的个数。
public:
	Duo() :v1(), v2(){ }
	Duo(T1 const& v1,T2 const& v2) :v1(v1), v2(v2){ } 

	//构造期间，进行类型转换。
	template<typename U1,typename U2>
	Duo(Duo<U1,U2> const& d) : v1(d.value1()), v2(d.value2()){}

	template<typename U1,typename U2>
	Duo<T1, T2>& operator=(Duo<U1,U2> const& d){
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

template<typename T1, typename T2, typename U1, typename U2>
inline bool operator==(Duo<T1,T2> const& duo1,Duo<U1,U2> const& duo2){
	return duo1.value1() == duo2.value1() && duo1.value2() == duo2.value2();
}

template<typename T1, typename T2, typename U1, typename U2>
inline bool operator!=(Duo<T1,T2> const& duo1,Duo<U1,U2> const& duo2){
	return !(duo1 == duo2);
}

template<typename T1,typename T2>
Duo<T1, T2> make_Duo(T1 const& v1,T2 const& v2){
	return Duo<T1, T2>(v1,v2);
}

Duo<float, int> foo(){
	return make_Duo(42,42);
}

void test_foo(){
	if (foo() == make_Duo(42, 42.0)){ }
}

#endif//DUO_H