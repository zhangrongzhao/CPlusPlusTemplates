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
	//	f(&dl);//���滻��ģ���β�P������ģ��ʵ��A���͵Ļ��ࡣ���ģ��ʵ��A��ָ�����ͣ�ģ���βο�����һ��ָ�����ͣ�����ָ���������A��ָ������͵Ļ��ࡣ
	//}
	
	//template<typename T>
	//class S{
	//private:
	//	T a;
	//public:
	//	S(T b) :a(b){}
	//};
	//
	//S<int> x(12);//��ģ�岻��ͨ�����캯������ģ��ʵ�������ģ�������ʾָ��ģ��ʵ�Ρ�

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
	//	init(&s,S(7,42));//T==>S,�ڶ���������ʾ�ṩ�˹��캯����Ĭ�Ϲ��캯���Ͳ�����������
	//}

	template<typename T>
	void f(T x=42){ }

	void test(){
		f<int>();
		//f();//������Ĭ�ϵ���ʵ��������ģ�������
	}
}




#endif//ARGUMENT_CAST_H