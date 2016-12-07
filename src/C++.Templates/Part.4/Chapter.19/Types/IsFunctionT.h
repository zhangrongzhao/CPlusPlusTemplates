#include "../stdafx.h"

#ifndef IS_FUNCTION_TYPE_H
#define IS_FUNCTION_TYPE_H
//数组元素类型不能为void，引用类型，函数类型。
//如果模板参数T是这三种类型之一，则test模板选择省略号为参数的模板。
//然后排除void，引用类型。则剩下的类型就是函数类型。
template<typename T>
class IsFunctionT{
private:
	typedef char One;
	typedef struct { char c[2]; } Two;

	template<typename U> static Two test(U(*)[1]);
	template<typename U> static One test(...);
public:
	enum{ Yes = sizeof(test<T>(0)) == sizeof(One) };
	enum{ No = !Yes };
};

//特化：排除void类型,void类型不是函数类型
template<>
class IsFunctionT<void>{
public:
	enum{ Yes = 0 };
	enum{ No = !Yes };
};

//特化：排除引用类型，引用类型不是函数类型。
template<typename T>
class IsFunctionT<T&>{
public:
	enum{ Yes = 0 };
	enum{ No = !Yes };
};


#endif//IS_FUNCTION_TYPE_H