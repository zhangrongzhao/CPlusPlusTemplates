#include "../stdafx.h"

/*
template<int N>
class X{
public:
	typedef int I;
	void f(int){}
};

template<int N>
void fppm(void (X<N>::*p)(typename X<N>::I)){};
*/

/*
template<typename T>
void f(X<Y<T>,Y<T> >);
*/

/*ָ������ָ�룬ָ����ģ��
template<typename T>
void f(T,T);

void(*pf)(char, char) = &f;
*/

/*
class S{
public:
	template<typename T,int N> operator T[N](&)();
};
*/

/*ģ��ʵ������ֻ��Ӧ���ں���ģ��ͳ�Ա����ģ�塣
template<typename T>
class B{};

template<typename T>
class D :public B<T> {};

template<typename T>
void f(B<T>*){};

template<typename T>
void f(D<T>*){};//

void g(D<long> d1){
	f(&d1);//��ȷƥ�����ȣ������ȷƥ�䲻���ڵ�����£���ʹ�ÿ���ƥ�䡣
}
*/

/*��ģ�����
template<typename T>
class S{
private:
	T a;
public:
	S(T b) :a(b){
	}
};

//S x(12); //���󣺲��ܴӹ��캯���ĵ���ʵ��12������ģ�����T
*/

/*ȱʡ����ʵ��
template<typename T>
void init(T* loc,T const& val=T()){
	*loc = val;
}

class S{
public:
	S(int, int){};
};
*/

/*
template<typename T>
void f(T x = 42){

}

void g(){
	f<int>();//��ʾ�ƶ�ģ��ʵ��T=int.
	//f();//���󣺲���ͨ��ȱʡ����ʵ��������T
}
*/



