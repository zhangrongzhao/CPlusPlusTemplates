#include "../stdafx.h"
#include <iostream>
/*受限名称查找
int x;

class B{
public:
	int i;
};

class D :public B{

};

//受限名称查找：如果作用域是一个类，那么查找范围可以到达他的基类
void f(D* pd){
	pd->i = 3;//找到基类中的i,如果作用域是一个类，那么查找范围可以到达他的基类。但是不会考虑的外围作用域。
	//D::x;//class D has no member 'X'
}*/

/*非受限名称查找，采用普通查找：先查找当前作用域{}，然后查找作用域的外围
* 在类内部定义的成员函数，先查找所在类及其基类的作用域，然后查找外围类的作用域。

extern int count;
int lookup_example(int count){
	if (count < 0){
		int count = 1;
		lookup_example(count);//非受限名称查找：。
	}

	return count + ::count;
}
*/

/*ADL:argument-dependent lookup,依赖参数的查找
template<typename T>
inline T const& max(T const& a,T const& b){
	return a < b ? b : a;
}

//在另外一个命名空间中使用这个模板函数
namespace BigMath{
	class BigNumber{};
	bool operator<(BigNumber const&,BigNumber const&);
}

using BigMath::BigNumber;
void g(BigNumber const& a,BigNumber const& b){
	BigNumber x = max(a,b);
	//使用普通方式查找max函数本身，当前作用域查找完毕，去查找当前作用域的外围，外围max函数并不知道BigMath命名空间，所以无法应用BigMath命名空间下的operator运算符。
	//要想应用BigMath命名空间下的Operator<，使用ADL：argument-dependent lookup,参数依赖查找，来解决这种限制。
}
*/

/*命名空间N中using指令符被忽略
namespace X{
   template<typename T>
   void f(T){
	   std::cout << "X::f(X::T) called\n";
   }
}

namespace N{
	//using namespace X;//该using指令符被忽略。
	enum E{ e1 };
	void f(E){
		std::cout << "N::f(N::E) called\n";
		X::f(0);
	}
}

void f(int){
	std::cout << "::f(int) called\n";
	X::f(1);
}*/

/*友元名称的插入
template<typename T>
class C{
	friend void f();//友元声明在外围类中是不可见的。
	friend void f(C<T> const&);//友元声明在外围类中是不可见的。
};

void g(C<int>* p){
	//f();
	//f(p);
	}*/

/*插入类名称
int C;

class C{
private:
	int i[2];
public :
	static int f(){
		return sizeof(C);//在类内部插入类的名称。看做是该类作用域中的非受限名称。
	}
};

int f(){
	return sizeof(C);
}*/

/*类模板也可以有插入式类名称
template<template<typename>
         class TT
>
class X{};

template<typename T>
class C{
	//C* a;//C<T>* a
	//C<void> b;
	//X<C> c;
	//X<::C> d;
	X< ::C> e;
};*/

/*依赖型类型名称
//template<typename T>
//class Trap{
//	public enum{x};//这里x不是一个类型。
//};
//
//template<typename T>
//class Victim{
//	int y;
//	void poof(){
//		Trap<T>::x*y;//声明or乘积？
//	}
//};
//
//template<>
//class Trap < void > {
//public:
//	typedef int x;
//};
//
//void boom(Victim<void>& bomb){
//	//bomb.poof();
//}
*/

/*
//template<typename T>
//class Shell{
//public:
//	template<int N>
//	class In{
//	public:
//		template<int M>
//		class Deep{
//		public:
//			virtual void f();
//		};
//	};
//};
//
//template<typename T,int N>
//class Weird{
//public:
//	void case1(typename Shell<T>::template In<N>::template Deep<N>* p){
//		p->template Deep<N>::f();//禁止虚函数调用。
//	}
//
//	void case2(typename Shell<T>::template In<N>::template Deep<N>& p){
//		p.template Deep<N>::f();//禁止虚函数调用。
//	}
//};

*/

/*using-declaration中的依赖型名称
class BX{
public:
	void f(int);
	void f(char const*);
	void g();
};

class DX :private BX{
public:
	using BX::f;//1.名称机制，不关注该名称是否是一个单一声明。
	            //2.不能访问的成员，现在变成可访问的。
};*/

/*
template<typename T>
class BXT{
public:
	typedef T Mystery;
	template<typename U>
	struct Magic;
};

template<typename T>
class DXTT :private BXT<T> {
public:
	using typename BXT<T>::Mystery;//显示指定类型。
	Mystery* p;//如果上面不使用typename，将会是一个语法错误。
};

//template<typename T>
//class DXTM :private BXT <T> {
//public:
//	using BXT<T>::template Magic;//不能指定依赖型名称是一个模板
//	Magic<T> sMagic;
//};*/

/*ADL和显示模板实参
namespace N{
	class X{};

	template<int I>
	void select(X*);
}

void g(N::X* xp){
	N::select<3>(xp);
}

*/

/*派生和类模板
//非依赖型基类
template<typename X>
class Base{
public:
	int baseField;
	typedef int T;
};

class D1 :public Base<Base<void> > {//实际上不是模板
public:
	void f(){ baseField = 3; }
};

template<typename T>
class D2 :public Base<double> {//非依赖型基类
public:
	void f(){
		baseField = 7;//正常访问继承成员
	}
	T strange;//T是Base<double>::T,不是模板参数。这里的T不带域解析运算符，是一个非受限名称，先查找非依赖型积累，然后才查找模板参数列表
};

void g(D2<int*>& d2,int* p){
	d2.strange = p;
}*/

/*依赖型基类
*C++标准规定：1.对于模板中的非依赖型名称，将会在看到的第一时间进行查找。
*C++标准声明：2.非依赖型名称不会在依赖型基类中进行查找。
*C++声明：two-phase lookup:首次看到模板定义的时候，进行第一次查找；当实例化模板的时候，进行第二次查找。

template<typename T>
class Base{
public :
	int baseField;
	typedef int T;
};

template<typename T>
class DD :public Base<T> {//依赖型基类
public :
	void f(){ Base<T>::baseField = 0; };//(1) 将非依赖型名称改为依赖型名称。依赖性名称到实例化的时候才进行查找。
};

template<>
class Base<bool> {
public :
	enum{baseField=42};//tricky;
};

void g(DD<bool>& d){
	d.f();//oops.
}*/

/**/
template<typename T>
class Base{
public:
	int baseField;
	//typedef int T;
};

template<typename T>
class B{
public:
	enum E{e1=6,e2=28,e3=496};
	virtual void zero(E e=e1);
	virtual void one(E&);
};

template<typename T>
class D :public B <T> {
public :
	void f(){
		typename D<T>::E e;//this->E会是一个无效的语法
		this->zero();//B<T>::zero()会禁止虚函数的调用，B<T>已经限定是调用基类的zero方法。
		one(e);//实参时依赖型的。
	}
};

template<typename T>
class DD3 :public Base <T> {
public:
	using Base<T>::baseField;//依赖性名称现在位于该作用域
	void f(){ baseField = 0; }//正确
};







