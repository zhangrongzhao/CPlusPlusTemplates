#include "../stdafx.h"
#include <iostream>
/*�������Ʋ���
int x;

class B{
public:
	int i;
};

class D :public B{

};

//�������Ʋ��ң������������һ���࣬��ô���ҷ�Χ���Ե������Ļ���
void f(D* pd){
	pd->i = 3;//�ҵ������е�i,�����������һ���࣬��ô���ҷ�Χ���Ե������Ļ��ࡣ���ǲ��ῼ�ǵ���Χ������
	//D::x;//class D has no member 'X'
}*/

/*���������Ʋ��ң�������ͨ���ң��Ȳ��ҵ�ǰ������{}��Ȼ��������������Χ
* �����ڲ�����ĳ�Ա�������Ȳ��������༰������������Ȼ�������Χ���������

extern int count;
int lookup_example(int count){
	if (count < 0){
		int count = 1;
		lookup_example(count);//���������Ʋ��ң���
	}

	return count + ::count;
}
*/

/*ADL:argument-dependent lookup,���������Ĳ���
template<typename T>
inline T const& max(T const& a,T const& b){
	return a < b ? b : a;
}

//������һ�������ռ���ʹ�����ģ�庯��
namespace BigMath{
	class BigNumber{};
	bool operator<(BigNumber const&,BigNumber const&);
}

using BigMath::BigNumber;
void g(BigNumber const& a,BigNumber const& b){
	BigNumber x = max(a,b);
	//ʹ����ͨ��ʽ����max����������ǰ�����������ϣ�ȥ���ҵ�ǰ���������Χ����Χmax��������֪��BigMath�����ռ䣬�����޷�Ӧ��BigMath�����ռ��µ�operator�������
	//Ҫ��Ӧ��BigMath�����ռ��µ�Operator<��ʹ��ADL��argument-dependent lookup,�����������ң�������������ơ�
}
*/

/*�����ռ�N��usingָ���������
namespace X{
   template<typename T>
   void f(T){
	   std::cout << "X::f(X::T) called\n";
   }
}

namespace N{
	//using namespace X;//��usingָ��������ԡ�
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

/*��Ԫ���ƵĲ���
template<typename T>
class C{
	friend void f();//��Ԫ��������Χ�����ǲ��ɼ��ġ�
	friend void f(C<T> const&);//��Ԫ��������Χ�����ǲ��ɼ��ġ�
};

void g(C<int>* p){
	//f();
	//f(p);
	}*/

/*����������
int C;

class C{
private:
	int i[2];
public :
	static int f(){
		return sizeof(C);//�����ڲ�����������ơ������Ǹ����������еķ��������ơ�
	}
};

int f(){
	return sizeof(C);
}*/

/*��ģ��Ҳ�����в���ʽ������
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

/*��������������
//template<typename T>
//class Trap{
//	public enum{x};//����x����һ�����͡�
//};
//
//template<typename T>
//class Victim{
//	int y;
//	void poof(){
//		Trap<T>::x*y;//����or�˻���
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
//		p->template Deep<N>::f();//��ֹ�麯�����á�
//	}
//
//	void case2(typename Shell<T>::template In<N>::template Deep<N>& p){
//		p.template Deep<N>::f();//��ֹ�麯�����á�
//	}
//};

*/

/*using-declaration�е�����������
class BX{
public:
	void f(int);
	void f(char const*);
	void g();
};

class DX :private BX{
public:
	using BX::f;//1.���ƻ��ƣ�����ע�������Ƿ���һ����һ������
	            //2.���ܷ��ʵĳ�Ա�����ڱ�ɿɷ��ʵġ�
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
	using typename BXT<T>::Mystery;//��ʾָ�����͡�
	Mystery* p;//������治ʹ��typename��������һ���﷨����
};

//template<typename T>
//class DXTM :private BXT <T> {
//public:
//	using BXT<T>::template Magic;//����ָ��������������һ��ģ��
//	Magic<T> sMagic;
//};*/

/*ADL����ʾģ��ʵ��
namespace N{
	class X{};

	template<int I>
	void select(X*);
}

void g(N::X* xp){
	N::select<3>(xp);
}

*/

/*��������ģ��
//�������ͻ���
template<typename X>
class Base{
public:
	int baseField;
	typedef int T;
};

class D1 :public Base<Base<void> > {//ʵ���ϲ���ģ��
public:
	void f(){ baseField = 3; }
};

template<typename T>
class D2 :public Base<double> {//�������ͻ���
public:
	void f(){
		baseField = 7;//�������ʼ̳г�Ա
	}
	T strange;//T��Base<double>::T,����ģ������������T������������������һ�����������ƣ��Ȳ��ҷ������ͻ��ۣ�Ȼ��Ų���ģ������б�
};

void g(D2<int*>& d2,int* p){
	d2.strange = p;
}*/

/*�����ͻ���
*C++��׼�涨��1.����ģ���еķ����������ƣ������ڿ����ĵ�һʱ����в��ҡ�
*C++��׼������2.�����������Ʋ����������ͻ����н��в��ҡ�
*C++������two-phase lookup:�״ο���ģ�嶨���ʱ�򣬽��е�һ�β��ң���ʵ����ģ���ʱ�򣬽��еڶ��β��ҡ�

template<typename T>
class Base{
public :
	int baseField;
	typedef int T;
};

template<typename T>
class DD :public Base<T> {//�����ͻ���
public :
	void f(){ Base<T>::baseField = 0; };//(1) �������������Ƹ�Ϊ���������ơ����������Ƶ�ʵ������ʱ��Ž��в��ҡ�
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
		typename D<T>::E e;//this->E����һ����Ч���﷨
		this->zero();//B<T>::zero()���ֹ�麯���ĵ��ã�B<T>�Ѿ��޶��ǵ��û����zero������
		one(e);//ʵ��ʱ�����͵ġ�
	}
};

template<typename T>
class DD3 :public Base <T> {
public:
	using Base<T>::baseField;//��������������λ�ڸ�������
	void f(){ baseField = 0; }//��ȷ
};







