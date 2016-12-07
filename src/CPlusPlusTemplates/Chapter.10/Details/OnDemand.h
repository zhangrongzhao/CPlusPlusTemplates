#include "../stdafx.h"

/*On-Demand 实例化
template<typename T>
class C;//这里只有声明

C<int>* p = 0;//正确，不需要C<int>的定义

template<typename T>
class C{
public:
	void f();//成员声明
};//类模板定义结束

void g(C<int>& c){//只是用类模板声明
	c.f();//需要C<int>::f的定义
}

C<int>* p = new C<int>;
*/

/*C++的重载解析要求：如果候选函数的参数是class类型，那么该类型所对应的类就必须是可见的。*/
template<typename T>
class C{
public :
	C(int);//具有单参数的构造函数
};

void candidate(C<double> const&);//(1)
void candidate(int){ }

void call(){
	candidate(42);//精确匹配要优于(优先于)显式转型所获得的匹配。
}

