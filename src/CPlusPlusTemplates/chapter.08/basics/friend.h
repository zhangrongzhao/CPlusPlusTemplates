#include "../stdafx.h"

////友元类
//template<typename T>
//class Node;
//
//template<typename T>
//class Tree{
//	friend class Factory;//正确：即使这里是Factory的首次声明。
//	friend class Node<T>;//命名一个特定的类模板实例为友元。该类模板在声明处是可见的：该类模板有前置声明或者声明处能看到之前的定义。
//};

////友元函数
//template<typename T1,typename T2>
//void combine(T1,T2);
//
//class Mixer{
//	friend void combine<>(int&,int&);//T1=int&,T2=int&函数模板实例声明为friend。
//	friend void combine<int,int>(int,int);//T1=int,T2=int
//	friend void combine<char>(char,int);//T1=char,T2=int
//	//friend void combine<char>(char&,int);//不能匹配函数模板
//	friend void combine<>(long, long);//友元声明不能出现定义。
//};

//void multiply(void*);//普通函数
//
//template<typename T>
//void multiply(T);//函数模板
//
//class Comrades{
//	friend void multiply(int){ };//函数名称不受限，不带域运算符。（首要规则：非受限函数名称不能引用模板实例，只能引用普通函数。）在该处没有看到匹配的普通函数，那么这个友元声明就是函数的首次声明，该函数可以是定义。
//	friend void ::multiply(void*);//受限函数名称必须引用一个再此之前声明的函数或者函数模板。优先级：普通函数>函数模板。
//	friend void ::multiply(int);//引用模板实例。
//	friend void ::multiply<double*>(double*);//受限名称可以有一对尖括号，但是模板再此必须是可见的。
//	//friend void ::error(){};//受限的友元函数不能是一个定义。
//};

//template<typename T>
//class Node{
//	Node<T>* allocate();
//};
//
//template<typename T>
//class List{
//	friend Node<T>* Node<T>::allocate();
//};
//
//template<typename T>
//class Creator{
//	friend void appear(Creator<T>*){}//该友元函数在Creator实例化后才存在。
//};
//
//Creator<void> miracle;//实例化后，生成友元函数
//Creator<double> oops; //友元函数第二次被生成，重复定义。

//友元模板
class Manager{
	template<typename T>
	friend class Task;

	//template<typename T>
	//friend void Schedule<T>::dispath(Task<T>*);

	template<typename T>
	friend int ticket(){
		return ++Manager::counter;
	}
	static int counter;
};