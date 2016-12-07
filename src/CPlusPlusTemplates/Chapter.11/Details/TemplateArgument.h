#include "../stdafx.h"

/*函数模板的实参推倒
template<typename T>
inline T const& max(T const& a,T const& b){
	return a < b ? b : a;
}

//int g = max(1,1.0);//
*/

/*
template<typename T>
typename T::ElementT at(T const& a,int i){
	return a[i];
}

void f(int* p){
	int x = at<int*>(p,7);//explicit template argument to probid the argument to 
	}*/

/*
template<typename T>
inline void f(T);

template<typename T>
inline void g(T&){};

double x[20];
int const seven = 7;

//f(x);//数组到指针类型的转换：T=double *
//g(x);//&引用整个数组空间：double(&)[20]
//f(seven);//非引用参数：T=int.纯粹的值传递。
//g(seven);//引用参数：T=int const
//f(7);//非引用参数，T=int;
//g(7);//不能把7传递给int&.
*/

/*演绎的上下文
template<typename T>
void f1(T*);

template<typename E,int N>
void f2(E(&)[N]);

template<typename T1,typename T2,typename T3>
void f3(T1 (T2::*)(T3*));

class S{
public :
	void f(double*);
};

void g(int*** ppp){
	bool b[42];
	f1(ppp);//T=int**
	f2(b);//bool (&)[42]
	f3(&S::f);//void (*)(double*)
}*/



