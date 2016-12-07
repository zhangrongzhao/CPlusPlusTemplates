#include "../stdafx.h"

#ifndef ARGUMENT_CAST_H
#define ARGUMENT_CAST_H
namespace Argument_Cast{
	//template<typename T>
	//class B{ };

	//template<typename T>
	//class D :public B<T> { };

	//template<typename T>
	//void f(B<T>*);

	//void g(D<long> dl){
	//	f(&dl);//被替换的模板形参P可以是模板实参A类型的基类。如果模板实参A是指针类型，模板形参可以是一个指针类型，他所指向的类型是A所指向的类型的基类。
	//}
	
	//template<typename T>
	//class S{
	//private:
	//	T a;
	//public:
	//	S(T b) :a(b){}
	//};
	//
	//S<int> x(12);//类模板不能通过构造函数进行模板实参演绎。类模板必须显示指定模板实参。

	//template<typename T>
	//void init(T* loc,T const& val=T()){
	//	*loc = val;
	//}

	//class S{
	//public:
	//	S(int, int){ };
	//};
	//
	//S s(1, 1);
	//
	//void test(){
	//	init(&s,S(7,42));//T==>S,第二个参数显示提供了构造函数，默认构造函数就不在起作用啦
	//}

	template<typename T>
	void f(T x=42){ }

	void test(){
		f<int>();
		//f();//不能用默认调用实参来演绎模板参数。
	}
}




#endif//ARGUMENT_CAST_H