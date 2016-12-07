#include "../stdafx.h"

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
//	void case1(typename Shell<T>::template In<N>::template Deep<N>* p){ }
//	void case2(typename Shell<T>::template In<N>::template Deep<N>& p){ }
//};

//namespace N{
//	class X{ };
//	
//	template<int I>
//	void select(X*);
//}
//
//void g(N::X* xp){
//	N::select<3>(xp);
//}

////非依赖型基类：非受限名称查找，先查找基类，在查找模板参数列表。
//template<typename X>
//class Base{
//public:
//	int basefield;
//	typedef int T;
//};
//
//class D1 :private Base<Base<void> > {
//public:
//	void f(){ Base<Base<void>>::basefield = 3; }
//};
//
//template<typename T>
//class D2 :private Base<double>{
//public:
//	void f(){ Base<double>::basefield = 7; }
//	Base<double>::T strange;
//};

//
//template<typename X>
//class Base{
//public:
//	int basefield;
//	typedef int T;
//};
//
//template<>
//class Base<bool> {
//public:
//	enum{ basefield=42};
//};
//
//template<typename T>
//class DD :public Base<T>{
//public :
//	void f(){ basefield = 0; }
//};
//
//template<typename T>
//class DD1 :public Base<T>{
//public:
//	void f(){ this->basefield = 0; }
//};
//
//template<typename T>
//class DD2 :public Base<T>{
//public:
//	void f(){ Base<T>::basefield = 0; }
//};
