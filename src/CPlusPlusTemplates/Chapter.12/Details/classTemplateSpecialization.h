#include "../stdafx.h"
#include <iostream>

/*
template<typename T>
class S{
public:
	void info(){
		std::cout << "generic(S<T>::info())" << std::endl;
	}
};

template<>
class S<void> {//全局特化并不需要于原来的泛型实现有任何关联。允许包含有不同名称的成员函数。全局特化只和类模板的名称有关联。
	void msg(){
		std::cout << "fully specialized (S<void>::msg)" << std::endl;
	}
};
*/

/*
template<typename T>
class Types{
public:
	typedef int I;
};

template<typename T,typename U=typename Types<T>::I>
class S;//(1)

template<>
class S<void> {//(2)
public:
	void f();
};

template<>
class S<char,char>;//(3)

//template<>
//class S<char,0>;//错误，不能使用0来代替类型参数U;0不是类型。

template<>
class S<char,char> {

};
*/

/*
template<typename T>
class S;

template<>
class S<char**> {
public:
	void print() const;
};

//类模板特化后的类模板实例成员的实现，相当于普通类成员的实现.这里不能使用Template<>前缀。
void S<char**>::print()const{

}*/

/*
template<typename T>
class Outside{
public:
	template<typename U>
	class Inside{};
};

template<>
class Outside<void> {
public://下面定义的嵌套类和类模板中的嵌套类没有任何关系。
	template<typename U>
	class Inside{
	private:
		static int count;
	};
};

template<typename U>
int Outside<void>::Inside<U>::count = 1;

template<typename T>
class Invalid{};

template<>
class Invalid<double>{

};

Invalid<double> x1;
*/

/*
template<typename T>
int f(T){//(1)
	return 1;
}

template<typename T>
int f(T*){//(2)
	return 2;
}

template<>
int f(int){//OK,(1)处的特化。
	return 3;
}

template<>
int f(int*){
	return 4;//(2)的特化。
}
*/

/*
//template<typename T>
//int f(T,T x=42){
//	return x;
//}

//template<>
//int f(int,int=30){//全局函数模板特化不能包含缺省实参值。
//
//}
*/

template<typename T>
int g(T,T x=42){
	return x;
}

template<>
int g(int x,int y){
	return y / 2;
}

