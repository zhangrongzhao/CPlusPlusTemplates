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
//    //��ͨ��Ա�������麯��
//	virtual ~Dynamic();
//
//	////��Ա����ģ�岻������Ϊ�麯��
//	//template<typename T2>
//	//virtual void copy(T2 const&);
//};
//
//int C;
//class C;//�����ƺͷ�������λ�ڲ�ͬ�����ֿռ䡣

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

////�������������Ϳ���ָ��Ϊ��ģ�����
//template<int buf[]>//��ʽint* 
//class Lexer;
//
//template<int* buf>
//class Lexer;

//����ʱ�ھ���ȷ���ĳ�����
//template<int const length> class Buffer;
//template<int length> class Buffer;

//ģ���ģ�����
//template<template<typename X> class C>
//void f(C<int>* p);

//ģ���ģ�����������Ϊunion
//template<template<typename X> union C>
//void fo(C<int>* p);

////ģ���ģ�����������Ϊstruct
//template<template<typename X> struct C>
//void foo(C<int>* p);

//template<template<typename T,typename A=std::Allocator> class Container>
//class Adaptation{
//	Container<int> storage;//==>Container<int,std::Allocator> storage;
//};

//ģ���������ֻ�ܱ�������������������ʹ��
//template<template<typename T,T*> class Buf>
//class Lexer{
//	static char storage[5];
//	Buf<char, &Lexer<Buf>::storage[0]> buf;
//};

//template<template<typename T> class List>
//class Node{
//	static T* storage;//ģ���ģ���������������ʹ��,���������Tֻ����ģ�������ʹ�á����ڱ�����ʹ�á�
//};

////ģ���ģ����������ڱ�ģ����ʹ�ã�����ʡ�Բ�д��
//template<template<typename,typename=std::Allocator> class Container>
//class Adaptation{
//	Container<int> storage;
//};

//ȱʡģ��ʵ��
//template<typename T,typename Allocator=std::allocator<T>>//allocatorģ��������ǰ���ģ�����T
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
//	apply(&single<int>,3);//��ȷ
//	//apply(&multi<int>,4);
//}

//SFISAE:substitution failure is not an error.����ģ��������ص���Ҫ���ء�������ͼ������Ч�����ͣ�������������Ч�ı��ʽ��
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
//	enum { Yes =sizeof(TypeHasMemberTypeX<T>::test<T>(0)) == 1 };//��0����ָ�볣��������ת�����ȼ����ڰ�һ��ʵ�ε�ʡ�Ժš�
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
////	//List<Association*> error1;//error:ģ�����ʹ���˾ֲ�������
////	//List<ColorPtr> error2;//ʹ����δ����������
////	//List<point> ok;
////}
//
////��Ч�ķ�����ģ��ʵ�ε�����
//template<typename T,T nontype_param>
//class C;
//
//C<int, 33>* c1;
//
//int a;
//C<int*, &a>* c2;//�ⲿ�����ĵ�ַ��
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
//C<bool&, X::b>* c4;//��̬���Ա�ǿ�ȡ�ı������ơ�
//
//C<int X::*, &X::n>* c5;//ָ���Ա��ָ�����
//
//template<typename T>
//void template_func();
//
//C<void(), &template_func<double>>* c6;//����ģ��ʵ���Ǻ���

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
////C<Base*, &derived_obj>* err1;//�������ﲻ���������ൽ���������ת����
////C<int&, base.i>* err2;//
//
//int a[10];
////C<int*, &a[0]>* err3;//a�����ڱ���ʱ�ڻ�û�б������ڴ棬����ȷ��Ϊ����������ģ�������

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
//	Relation<int, double, std::list> rel;//std::list��һ������2��������ģ�塣
//}

//template<typename T>
//class Node;
//
//template<typename T>
//class Tree{
//	friend class Factory;//��ʹ������Factory���״�������
//	friend class Node<T>;//��ģ������Ϊ��Ԫ�࣬�������ĵط������ǿɼ��ġ�
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
//	friend void multiply(int){ }//û�����������������һ������ģ��ʵ����������ͨ�������״�������Ϊ���塣
//	friend void ::multiply(void*);//�������򣬸���������һ���ٴ�֮ǰ�����ĺ������ߺ���ģ�塣ƥ�����ȼ�����ͨ����>����ģ�塣
//	friend void ::multiply(int);
//	friend void ::multiply<double*>(double*);//ǿ��ʹ��ģ�壬����ģ������������ǿɼ��ġ�
//	//friend void ::error(){};//����������ĺ��������Ƕ��塣
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
//	friend void appear(){};//��������ģ�������ÿ����ģ��ʵ������ʱ�򣬶���������ͬ�ĺ�����Υ��One-definition rule.
//};
//
//Creator<void> mirable;//::appear()��һ������
//Creator<double> ope;//::appear()�ڶ������ɡ����ɴ���


////������⣬��Ԫ����������ģ�����������ʱ������ģ��������ɲ�ͬ��ʵ����
//template<typename T>
//class Creator{
//	friend void feed(Creator<T>*){ }//ÿ��T�����ɲ�ͬ��::feed()������
//};

////ģ�������ʵ������Ϊ��Ԫ
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