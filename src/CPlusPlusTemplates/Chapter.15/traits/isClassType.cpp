#include "stdafx.h"
#include <iostream>
#include "isClassType.h"

class MyClass{};

struct MyStruct{};

union MyUnion{};

void myFun(){};

enum E{e1} e;

//��ģ��ʵ�εķ�ʽ�������ͣ����Ը����ͽ��м��
template<typename T>
void check(){
	if (IsClassType<T>::Yes){
		std::cout << "IsClassType " << std::endl;
	}
	else{
		std::cout << "!IsClassType " << std::endl;
	}
}

//�Ժ������õķ�ʽ�������ͣ����Ը����ͽ��м��
template<typename T>
void checkT(T){
	check<T>();
}

