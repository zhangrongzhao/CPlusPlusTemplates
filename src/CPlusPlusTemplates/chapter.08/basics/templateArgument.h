#include "../stdafx.h"

//ģ��ʵ�Σ�ʵ����ģ��ʱ���滻ģ�������ֵ��

//template<typename T>
//inline T const& max(T const& a ,T const& b){
//	return a < b ? b : a;
//}
//
//
//template<typename DestT,typename SrcT>
//inline DestT implicit_Cast(SrcT const& x){//SrcT���Ա������DestT�������
//	return x;
//}

//template<typename Func,typename T>
//void apply(Func func_ptr,T x){
//	func_ptr(x);
//}
//
//template<typename T>
//void single(T){
//
//}
//
//template<typename T>
//void multi(T){
//
//}

//template<typename T>
//void multi(T*){
//
//}

//substitution-failure-is-not-an-error:SFINAE

//typedef char RT1;
//typedef struct{char a[2];} RT2;
//
//template<typename T>
//RT1 test(typename T::X const*);
//
//template<typename T>
//RT2 test(...);
//
////��
//#define type_has_number_type_X(T) (sizeof(test<T>(0))==1)

//template<int I>
//void f(int (&)[24/(4-I)]);
//
//template<int I>
//void f(int (&)[24/(4+I)]);

//template<int N>
//int g(){ return N; }
//
//template<int* p>
//int g(){ return *p; }

//template<typename T>
//class List{};
//
//typedef struct{ double x, y, z; } Point;
//
//typedef enum{red,green,blue} *ColorPtr;
//
//template<typename T>
//void clear(T p){
//	*p = 0;
//}
//
//template<typename T>
//inline void ignore(T const& p){}
//
//template<typename T>
//void shell(T p){
//	class ShallowChecks{
//		void dereference(T p){
//			ignore(*p);
//		}
//	};
//	clear(p);
//}

////�����͵�ģ��ʵ��
//template<typename T,T nontype_param>
//class C{ };
//
//C<int, 33>* c1;
//
//int a;
//C<int*, &a> c2;
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
//C<bool&, X::b>* c4;
//C<int X::*, &X::n> c5;

//template<typename T,T nontype_param>
//class C;
//
//class Base{
//public:
//	int i;
//} base;
//
//class Derived :public Base{
//
//} derived_obj;
//
////C<Base*, &derived_obj>* err1;//�������ﲻ�ῼ�������ൽ���������ת����
//
////C<int&, base.i>*  err2;//base.i�Ǳ����ڳ�����
//
//int const * const a = 0;
//
//C<int* , a>* err3;







