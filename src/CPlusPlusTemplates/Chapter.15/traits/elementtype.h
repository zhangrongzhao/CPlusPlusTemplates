#include "../stdafx.h"

#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <typeinfo>

/*确定元素类型*/
template<typename T>
class ElementT;  //primary template

template<typename T>
class ElementT<std::vector<T>>{//partial specialization
public:
	typedef T Type;
};

template<typename T>
class ElementT<std::list<T>>{//partial specialization
public:
	typedef T Type;
};

template<typename T>
class ElementT<std::stack<T>>{//partial specialization
public:
	typedef T Type;
};

template<typename ContainerType>
class ElementT{
public:
	typedef typename ContainerType::value_type Type;
};

//template<typename T1,typename T2>
//class X{
//public:
//	typedef T1 ...;
//	typedef T2 ...;
//
//};