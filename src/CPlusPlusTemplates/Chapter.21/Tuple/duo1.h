#include "../stdafx.h"

#ifndef DUO_1_H
#define DUO_1_H

template<typename T1,typename T2>
class Duo{
private:
	T1 value1;//第一个域的值
	T2 value2;//第二个域的值
public:
	typedef T1 Type1;//第一个域的类型
	typedef T2 Type2; //第二个域的类型
	enum { N = 2 };//域的个数
public:
	//构造函数
	Duo():value1(),value2(){ }
	Duo(T1 const& a,T2 const& b):value1(a),value2(b){ }
	
	//用于在构造期间，进行隐式的类型转换
	template<typename U1,typename U2>
	Duo(Duo<U1,U2> const& d):value1(d.v1()),value2(d.v2()){ }

	//用于在赋值期间，进行隐式的类型转换
	template<typename U1,typename U2>
	Duo<T1, T2>& operator=(Duo<U1,U2> const& d){
		value1 = d.value1;
		value2 = d.value2;
		return *this;
	}

	//用于访问域的函数（域访问函数）
	T1& v1(){ return value1;}
	T1 const& v1() const{return value1;}
	T2& v2(){return value2;}
	T2 const& v2() const{return value2;	}
};

//比较运算符（允许混合类型）
template<typename T1, typename T2, typename U1, typename U2>
inline bool operator==(Duo<T1, T2> const& d1, Duo<U1, U2> const& d2){
	return d1.v1() == d2.v1() && d1.v2() == d2.v2();
}

template<typename T1,typename T2,typename U1,typename U2>
inline bool operator!=(Duo<T1,T2> const& d1,Duo<U1,U2> const& d2){
	return !(d1==d2);
}

//针对创建和初始化的辅助函数
template<typename T1,typename T2>
inline Duo<T1,T2> make_duo(T1 const& a,T2 const& b){
	return Duo<T1, T2>(a,b);
}

//template<typename T1,typename T2>
//inline Duo<T1, T2> make_duo(T1& a,T2& b){
//	return Duo<T1, T2>(a,b);
//}


#endif//DUO_1_H