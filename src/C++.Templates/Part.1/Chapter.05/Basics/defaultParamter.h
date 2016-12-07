#include "../stdafx.h"

#ifndef DEFAULT_PARAMTER_H
#define DEFAULT_PARAMTER_H

template<typename T>
void foo(){
	T x = T();//T如果是内建类型，x=0或者x=false
}

template<typename T>
class MyClass{
private:
	T x;
public:
	MyClass() :x(){//确认x已经初始化。
	
	}
};

#endif//DEFUALT_PARAMTER_H