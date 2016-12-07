#include "../stdafx.h"
//#include 

//declaration
template<typename T>
class List{
public :
	template<typename T2>
	List(List<T2>& const&);//成员函数模板（构造函数）
};

//definition
template<typename T>
template<typename T2>
List<T>::List(List<T2> const&){};//位于类外部的成员函数模板定义

template<typename T>
int length(List<T> const&);//位于外部名字空间作用域的函数模板

class Collection{
	
	template<typename T>
	class Node{};//位于类内部的成员类模板的定义

	template<typename T>
	class Handle;//位于类内部的成员类模板的声明，此处没有定义

    template<typename T>
	T* alloc(){};//位于类内部的成员函数模板的定义，也是一个显示内联函数
};


//template<typename T>
//class Collection:Handle{//一个在类的外部定义的成员类模板，此处为该类模板的定义
//
//};


template<typename T>
union AllocChunk{//union模板，被看做是类模板中的一种。
	T object;
	unsigned char bytes[sizeof(T)];
};

//函数模板声明可以具有缺省调用实参
template<typename T>
void report_top(Stack<T> const&,int number=0);

template<typename T>
void fill(Array<T>*,T const&=T());//对于基本类型T()为0，缺省调用实参可以依赖于模板参数T

class Value{
public:
	//Value();
	Value(int);
};

//
//void init(Array<Value>* array){
//	Value zero(0);
//
//	fill(array,zero);//没有使用默认构造函数=T()
//	fill(array);//不提供第二个参数，则使用第二个参数默认的构造函数Value()，由于Value类型没有提供默认的无参构造函数，编译错误。
//
//}





