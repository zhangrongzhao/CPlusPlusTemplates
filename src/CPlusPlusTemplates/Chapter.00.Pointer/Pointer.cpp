// Pointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//ע�⣺���ò���
template<typename T>
inline T const& max(T const &a, T const &b){
	std::cout << "&a:" << static_cast<const T*>(&a) << std::endl;
	std::cout << "&b:" << static_cast<const T*>(&b) << std::endl;
	return a < b ? b : a;
}

//template<typename T>
//inline T max(T a,T b){
//	std::cout << "&a:" << static_cast<T*>(&a) << std::endl;
//	std::cout << "&b:" << static_cast<T*>(&b) << std::endl;
//	return a < b ? b : a;
//}

//template<typename T>
//inline void foo(T instance)
//{
//	std::cout << "instance:" << static_cast<T*>(&instance) << std::endl;
//}

//template<typename T>
//inline void foo(T& instance)//&��ʾ��ʵ�ν����������ʹ���
//{
//	std::cout << "instance:" << static_cast<T*>(&instance) << std::endl;
//}

int _tmain(int argc, _TCHAR* argv[])
{
	char *str1 = "apple";
	char *str2 = "peach";
	::max(str1,str2);

	//int a = 0;
	//int b = 1;
	//int *pointerA = &a;
	//int *pointerB = &b;
	//std::cout<<"a:"<<static_cast<const void *>(pointerA) << std::endl;
	//std::cout<<"b:"<<static_cast<const void *>(pointerB) << std::endl;
	//class Person{
	//private:
	//	int _age;
	//public:
	//	Person(int age){ _age = age; };
	//	~Person(){};
	//};
	//Person *person1 = new Person(25);//new �����������������ڶ��ϣ�����ָ�룬ָ����еĸö���
	//Person me(30);//�����Ķ���������߳�ջ�ϡ�
	
    return 0;
}








