#include "../stdafx.h"

/*
template<int N>
class X{
public:
	typedef int I;
	void f(int){}
};

template<int N>
void fppm(void (X<N>::*p)(typename X<N>::I)){};
*/

/*
template<typename T>
void f(X<Y<T>,Y<T> >);
*/

/*指向函数的指针，指向函数模板
template<typename T>
void f(T,T);

void(*pf)(char, char) = &f;
*/

/*
class S{
public:
	template<typename T,int N> operator T[N](&)();
};
*/

/*模板实参演绎只能应用于函数模板和成员函数模板。
template<typename T>
class B{};

template<typename T>
class D :public B<T> {};

template<typename T>
void f(B<T>*){};

template<typename T>
void f(D<T>*){};//

void g(D<long> d1){
	f(&d1);//精确匹配优先，如果精确匹配不存在的情况下，会使用宽松匹配。
}
*/

/*类模板参数
template<typename T>
class S{
private:
	T a;
public:
	S(T b) :a(b){
	}
};

//S x(12); //错误：不能从构造函数的调用实参12来演绎模板参数T
*/

/*缺省调用实参
template<typename T>
void init(T* loc,T const& val=T()){
	*loc = val;
}

class S{
public:
	S(int, int){};
};
*/

/*
template<typename T>
void f(T x = 42){

}

void g(){
	f<int>();//显示制定模板实参T=int.
	//f();//错误：不能通过缺省调用实参来演绎T
}
*/



