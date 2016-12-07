#include "../stdafx.h"

#ifndef GLOBAL_SPECIALIZATION_H
#define GLOBAL_SPECIALIZATION_H
#include <iostream>

//template<typename T>
//class S{
//public:
//	void info(){
//		std::cout << "generic(S<T>::info())\n";
//	}
//};
//
////全局特化的实现可以与基本模板没有关系。
//template<>
//class S<void>{
//public:
//	void msg(){
//		std::cout << "fully specialized (S<void>::msg())\n";
//	}
//};
//
//template<typename T>
//class Types{
//public:
//	typedef int I;
//};
//
//template<typename T,typename U=typename Types<T>::I>
//class S;
//
//template<>
//class S<void>{
//public:
//	void f();
//};
//
//template<>
//class S < char, char > {};
//
////template<> class S <char,0> ;//error
//void test(){
//	S<int>* p1;//
//	//S<int> e1; //隐式调用构造函数。需要类型的定义。
//	S<void>* pv;
//	S<void, int> sv;
//	//S<void, char> e2; //隐式调用构造函数。需要类型的定义。
//	S<char, char> e3;
//}
//template<>
//class S<char, char>{ };

//template<typename T>
//class S;
//
//template<>
//class S<char**>{
//public:
//	void print() const;
//};
//
//void S<char**>::print() const{ };//对具体类模板的实例中的成员进行定义。

//template<typename T>
//class Outside{
//public:
//	template<typename T>
//	class Inside{ };
//};
//
//template<>
//class Outside<void> {
//public:
//	template<typename T>
//	class Inside{
//	private:
//		static int count;
//	};
//};
//
//template<typename U>
//int Outside<void>::Inside<U>::count = 1;

//template<typename T>
//class Invalid{ };
//
//Invalid<double> x1;
//
//template<>
//class Invalid<double>;

//template<typename T>
//int f(T){ return 1; }
//
//template<typename T>
//int f(T*){ return 2; }
//
//template<>
//int f(int){ return 3; }
//
//template<>
//int f(int*){ return 4; }
//
//template<typename T>
//int f(T, T x = 42){ return x; }
//
//template<>
//int f(int, int){ return 0; }
//
//template<typename T>
//int g(T, T x = 42){ return x; }
//
//template<>
//int g(int, int y){ return y / 2; }
//

#endif//GLOBAL_SPECIALIZATION_H
