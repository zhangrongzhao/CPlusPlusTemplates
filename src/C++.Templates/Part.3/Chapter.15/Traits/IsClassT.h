#include "../stdafx.h"

#ifndef IS_CLASS_TYPE_H
#define IS_CLASS_TYPE_H
#include <iostream>
template<typename T>
class IsClassT{
private:
	typedef char One;
	typedef struct{ char a[2]; } Two;

	template<typename C> 
	static One test(int C::*);//针对类类型，成员指针有效

	template<typename C> 
	static Two test(...);
public:
	enum{ Yes = sizeof(test<T>(0)) == sizeof(One) };
	enum{ No = !Yes };
};

//测试
class MyClass{ };
struct MyStruct{ };
union MyUnion{ };
void MyFunc(){ };
enum E{e1} e;

template<typename T>
void check(){
	if (IsClassT<T>::Yes){
		std::cout << "IsClassT " << std::endl;
	}else{
		std::cout << "!IsClassT " << std::endl;
	}
}

template<typename T>
void checkT(T){
	check<T>();
}

void test_class_type(){
	std::cout << "int: ";
	check<int>();

	std::cout << "MyClass: ";
	check<MyClass>();

	std::cout << "MyStruct: ";
	MyStruct s;
	checkT(s);

	std::cout << "MyUnion: ";
	check<MyUnion>();

	std::cout << "enum: ";
    checkT(e);

	std::cout << "myfunc: ";
	checkT(MyFunc);
}
#endif//IS_CLASS_TYPE_H