#include "../stdafx.h"

#ifndef TEMPLATE_G_H
#define TEMPLATE_G_H
//the declaration of the primary template
template<typename T>
int g(T,T x=42){
	return x;
}

//�ػ�������ֹģ��ʵ��������Ϊ�˱�������ظ�������󣬾Ͳ��ܰѶ���������
template<>
int g(int x,int y);

#endif// TEMPLATE_G_H
