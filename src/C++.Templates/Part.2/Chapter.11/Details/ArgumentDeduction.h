#include "../stdafx.h"

//template<typename T>
//T const& max(T const& a,T const& b){
//	return a < b ? b : a;
//}
//
//void test(){
//	//int g = max(1, 2.0);
//}

//template<typename T>
//typename T::ElementT at(T const& a,int i){
//	return a[i];
//}
//
//void f(int* p){
//	//int x = at(p,7);
//	//int y = at<int*>(p,7);
//}

//template<typename T> void f(T); //parameter形参类型就是T
//template<typename T> void g(T&);//parameter形参类型就是A声明的类型
//
//double x[20];
//int const seven = 7;

//f(x);//x是数组类型，传递给f函数，decay蜕化为指针。T类型为 double* 
//g(x);//double (*)[20]
//f(seven);// T=int
//g(seven);//T=int const
//f(7);//T=int
//g(7);//T=int const

//template<typename T>
//void f1(T*);
//
//template<typename E,int N>
//void f2(E(&)[N]);
//
//template<typename T1,typename T2,typename T3>
//void f3(T1 (T2::*)(T3*));
//
//class S{
//public:
//	void f(double*);
//};
//
//void g(int*** ppp){
//	bool b[42];
//	f1(ppp);//T=>int**
//	f2(b);//E(&)[N]=>bool(&)[42]
//	f3(&S::f);//T2=>S,T3=>double,T1=>void
//}

