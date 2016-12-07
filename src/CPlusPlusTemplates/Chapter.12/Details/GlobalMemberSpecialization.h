#include "../stdafx.h"
#include <iostream>
/*******************primary template****************************************/
template<typename T>
class Outer{//(1)
public:
	template<typename U>//(2)
	class Inner{
	private:
		static int count;//(3)
	};
	static int code;//(4)
	void print() const{//(5)
		std::cout << "generic" << std::endl;
	}
};

template<typename T>
int Outer<T>::code = 6;//(6)

template<typename T>
template<typename U>
int Outer<T>::Inner<U>::count = 7;//(7)
/******************specialize：特化外围模板**********************************/
template<>
class Outer<bool> {//(8)
public:
	template<typename U>//(9)
	class Inner{
	private:
		static int count;//(10)
	};
	void print()const{//(11)

	}
};


template<>
int Outer<void>::code;//非定义的声明语法：非定义声明

template<>
void Outer<void>::print() const;

/******************specialize：特化内部模板**********************************/
template<>
template<typename X>
class Outer<wchar_t>::Inner{//与基类中的内部类没有任何关系。
public:
	static long count;//成员类型发生改变
};

template<>
template<typename X>
long Outer<wchar_t>::Inner<X>::count;

/******************specialize：内部模板的全局特化**********************************/
template<>
template<>
class Outer<char>::Inner <wchar_t> {
public:
	enum{ count = 1 };
};

template<>
class Outer<bool>::Inner<wchar_t> {
public:
	enum{ count = 2 };
};