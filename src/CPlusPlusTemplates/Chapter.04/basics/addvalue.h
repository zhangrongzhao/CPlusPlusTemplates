#include "../stdafx.h"

//为函数模板添加非类型参数
//非类型模板参数的限制：常整数（包括枚举值）或者指向外部链接对象的指针。
template<typename T,int VAL>
T addValue(T const& x){
	return x + VAL;
}

//ERROR:浮点数不能作为非类型模板参数
//template<double VAT>
//double process(double v){
//	return v*VAT;
//}


//类对象不能作为非类型模板参数
//illegal type for non-type template parameter 'name'
//template<std::string name>
//class MyClass{
//
//};


//非模板参数不能是一个内部链接对象
//template<char const* name>
//class MyClass{
//
//};
//
//char const* const s = "hello";//s是内部链接对象
//MyClass<s> x;//s是一个指向内部链接对象的指针


//非类型模板参数必须是：常整数（或者枚举），或者是指向外部链接对象的指针。
template<char const* name>
class MyClass{};
 
extern char const s[] = "hello";//s是外部链接对象。
MyClass<s> x;//



