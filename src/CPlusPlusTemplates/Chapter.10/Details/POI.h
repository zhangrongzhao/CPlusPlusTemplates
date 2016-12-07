#include "../stdafx.h"

/*函数模板的实例化
class MyInt{
public:
	MyInt(int i);
};

MyInt operator-(MyInt const&);
bool operator>(MyInt const&,MyInt const&);

typedef MyInt Int;

template<typename T>
void f(T i){
	if (i>0){
		g(-i);
	}
}

//(1)
void g(Int){
	//(2)
	f<Int>(42);//调用点
	//(3)
}
//(4)*/

/*类模板特化，POI位置不同于函数模板:包含这个实例引用的定义或声明之前的最近命名空间。
template<typename T>
class S{
public :
	T m;
};
//(5)-->POI
unsigned long h(){
	//(6)
	return (unsigned long) sizeof(sizeof(S<int>));
	//(7)
}
//(8)*/


/**/
template<typename T>
class S{
public:
	typedef int I;
};

//(1)
template<typename T>
void f(){
     S<char>::I var1 = 41;
	 typename S<T>::I var2 = 42;
}