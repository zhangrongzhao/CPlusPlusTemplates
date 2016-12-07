#include "../stdafx.h"

#ifndef PARAMETER_DECLARATION_H
#define PARAMETER_DECLARATION_H
//#include <stack>
//template<typename T>
//class List{
//public:
//   template<typename T2>
//   List(List<T2> const&);
//};
//
//template<typename T>
//template<typename T2>
//List<T>:List(List<T2> const& list2){ 
//    
//}
//
//template<typename T>
//int length(List<T> const& );
//
//class collection{
//	template<typename T>
//	class Node{ };
//
//	template<typename T>
//	class Handle;
//
//	template<typename T>
//	T* alloc();
//};
//
//template<typename T>
//class collection::Handle{ };
//
//
//template<typename T>
//void report_top(std::Stack<T> const&, int number = 10);
//
//template<typename T>
//void fill(Array<T>* ,T const&=T());
//
//template<int I>
//class CupBoard{
//	void open();
//	class shelf;
//	static double total_weight;
//};
//
//template<int I>
//void CupBoard<I>::open(){};
//
//template<int I>
//class CupBoard<I>::shelf{ };
//
//template<int I>
//double CupBoard<I>::total_weight = 0.0;

//template<typename T>
//class Dynamic{
//public:
//    //普通成员可以是虚函数
//	virtual ~Dynamic();
//
//	////成员函数模板不能声明为虚函数
//	//template<typename T2>
//	//virtual void copy(T2 const&);
//};
//
//int C;
//class C;//类名称和非类名称位于不同的名字空间。

//int X;
//template<typename T>
//class X;

//struct S;
//template<typename T>
//class S;

//template<typename T,T* Root,template<T*> class buf>
//class Structure; 

//template<typename Allocator>
//class List{
//	class Allocator* allocator;
//	friend class Allocator;
//};

//template<typename T,
//         typename T::Allocator* Allocator//typename
//>
//class List;

////函数和数组类型可以指定为非模板参数
//template<int buf[]>//隐式int* 
//class Lexer;
//
//template<int* buf>
//class Lexer;

//编译时期就能确定的常量。
//template<int const length> class Buffer;
//template<int length> class Buffer;

//模板的模板参数
//template<template<typename X> class C>
//void f(C<int>* p);

//模板的模板参数，不能为union
//template<template<typename X> union C>
//void fo(C<int>* p);

////模板的模板参数，不能为struct
//template<template<typename X> struct C>
//void foo(C<int>* p);

//template<template<typename T,typename A=std::Allocator> class Container>
//class Adaptation{
//	Container<int> storage;//==>Container<int,std::Allocator> storage;
//};

//模板参数名称只能被自身其他参数的声明使用
//template<template<typename T,T*> class Buf>
//class Lexer{
//	static char storage[5];
//	Buf<char, &Lexer<Buf>::storage[0]> buf;
//};

//template<template<typename T> class List>
//class Node{
//	static T* storage;//模板的模板参数不能再这里使用,这里的类型T只在类模板参数中使用。不在本类中使用。
//};

////模板的模板参数不会在本模板中使用，可以省略不写。
//template<template<typename,typename=std::Allocator> class Container>
//class Adaptation{
//	Container<int> storage;
//};

//缺省模板实参
//template<typename T,typename Allocator=std::allocator<T>>//allocator模板依赖于前面的模板参数T
//class List;

//template<typename DstT,typename SrcT>
//inline DstT implicit_cast(SrcT const& x){
//	return x;
//}
//
//void test(){
//	double value = implicit_cast<double>(-1);
//}

//template<typename Func,typename T>
//void apply(Func func_ptr,T x){
//	func_ptr(x);
//}
//
//template<typename T>
//void single(T);
//
//template<typename T>
//void multi(T);
//
//template<typename T>
//void multi(T*);
//
//void test_apply(){
//	apply(&single<int>,3);//正确
//	//apply(&multi<int>,4);
//}

//SFISAE:substitution failure is not an error.函数模板可以重载的重要因素。允许试图创建无效的类型，但不允许创建无效的表达式。
//template<typename T>
//RT1 test(typename T::X const*);
//
//template<typename T>
//RT2 test(...);

//template<typename T>
//class IsFunctionT{
//private:
//	typedef char One;
//	typedef struct{ char a[2]; } Two;
//
//	template<typename U>
//	static One test(...);
//
//	template<typename U>
//	static Two test(U (*)[1]);
//public:
//	enum { Yes = sizeof(IsFunctionT<T>::test<T>(0)) == 1; };
//	enum { No = !Yes };
//};

//template<typename T>
//class TypeHasMemberTypeX{
//private:
//	typedef char One;
//	typedef struct{ char a[2]; } Two;
//
//	template<typename U>
//	Two test(...);
//
//	template<typename U>
//	One test(typename U::X const*);
//public:
//	enum { Yes =sizeof(TypeHasMemberTypeX<T>::test<T>(0)) == 1 };//从0到空指针常量的类型转换优先级高于绑定一个实参到省略号。
//	enum { No = !Yes };
//};
//
//template<typename T>
//class List{};
//
//typedef enum{red,green,blue} *ColorPtr;
//typedef struct{ double x, y, z; } point;
//
//
////void test(){
////	struct Association{
////		int* p;
////		int* q;
////	};
////	//List<Association*> error1;//error:模板参数使用了局部变量。
////	//List<ColorPtr> error2;//使用了未命名的类型
////	//List<point> ok;
////}
//
////有效的非类型模板实参的例子
//template<typename T,T nontype_param>
//class C;
//
//C<int, 33>* c1;
//
//int a;
//C<int*, &a>* c2;//外部变量的地址。
//
//void f();
//void f(int);
//C<void(*)(int), f>* c3;
//
//class X{
//public:
//	int n;
//	static bool b;
//};
//
//C<bool&, X::b>* c4;//静态类成员是可取的变量名称。
//
//C<int X::*, &X::n>* c5;//指向成员的指针变量
//
//template<typename T>
//void template_func();
//
//C<void(), &template_func<double>>* c6;//函数模板实例是函数

//
//template<typename T,T nontype_param>
//class C;
//
//class Base{
//public:
//	int i;
//};
//Base base;
//
//class Derived :public Base{ };
//Derived derived_obj;
//
////C<Base*, &derived_obj>* err1;//错误，这里不考虑派生类到基类的类型转换。
////C<int&, base.i>* err2;//
//
//int a[10];
////C<int*, &a[0]>* err3;//a数组在编译时期还没有被分配内存，不能确定为常量。不能模板参数。

//#include <memory>
//template<typename T1,
//	     typename T2,
//         template<typename T,typename=std::allocator<T> > class Container>
//class Relation{
//public:
//private:
//	Container<T1> dom1;
//	Container<T2> dom2;
//};
//
//void test(){
//	Relation<int, double, std::list> rel;//std::list是一个具有2个参数的模板。
//}

//template<typename T>
//class Node;
//
//template<typename T>
//class Tree{
//	friend class Factory;//即使这里是Factory的首次声明。
//	friend class Node<T>;//类模板声明为友元类，在声明的地方必须是可见的。
//};

//template<typename T1,typename T2>
//void combine(T1,T2);
//
//class Mixer{
//	friend void combine<>(int&,int&);
//	friend void combine<int,int>(int,int);
//	friend void combine<char>(char,int);
//	//friend void combine<char>(char&,int);
//	//friend void combine<>(long, long);
//};
//
//void multiply(void*);
//
//template<typename T>
//void multiply(T);
//    
//class Comrades{
//	friend void multiply(int){ }//没有域运算符，该名称一定不是模板实例。而是普通函数。首次声明即为定义。
//	friend void ::multiply(void*);//受限于域，该名称引用一个再此之前声明的函数或者函数模板。匹配优先级：普通函数>函数模板。
//	friend void ::multiply(int);
//	friend void ::multiply<double*>(double*);//强制使用模板，所以模板的声明必须是可见的。
//	//friend void ::error(){};//受限作用域的函数不能是定义。
//};
//
//template<typename T>
//class Node{
//	Node<T>* allocate();
//};
//
//template<typename T>
//class List{
//	friend Node<T>* Node<T>::allocate();
//};

//template<typename T>
//class Creator{
//	friend void appear(){};//不依赖域模板参数，每次类模板实例化的时候，都会生成相同的函数。违反One-definition rule.
//};
//
//Creator<void> mirable;//::appear()第一次生成
//Creator<double> ope;//::appear()第二次生成。生成错误。


////解决问题，友元函数依赖于模板参数，生成时，根据模板参数生成不同的实例。
//template<typename T>
//class Creator{
//	friend void feed(Creator<T>*){ }//每个T都生成不同的::feed()函数。
//};

////模板的所有实例都成为友元
//class Manager{
//	template<typename T>
//	friend class Task;
//
//	template<typename T>
//	friend void Schedule<T>::dispath(Task<T>*);
//
//	template<typename T>
//	friend int ticket(){
//		return ++Manger::counter;
//	}
//
//	static int counter;
//};


#endif//PARAMETER_DECLARATION_H