#include "../stdafx.h"

#ifndef TEMPLATE_G_H
#define TEMPLATE_G_H
//the declaration of the primary template
template<typename T>
int g(T,T x=42){
	return x;
}

//特化声明禁止模板实例化，但为了避免出现重复定义错误，就不能把定义放在这里。
template<>
int g(int x,int y);

#endif// TEMPLATE_G_H
