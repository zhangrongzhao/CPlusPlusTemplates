#include "../stdafx.h"

#ifndef MATH_1_H
#define MATH_1_H

#include <cmath>
#include <cstdlib>

class Abs{
public:
	//"��������"
	double operator()(double v) const{
		return std::abs(v);
	}
};

class Sine{
public:
	//��������
	double operator()(double a) const{
		return std::sin(a);
	}
};

//�ȼ�������Ƕȵ�����ֵ��Ȼ���ڼ�������ֵ�þ���ֵ
class AbsSins{
public:
	double operator()(double a){
		return std::abs(std::sin(a));
	}
};

//ȱ�㣺Ϊÿ������ɷº����Ĺ�����Ϲ��ܶ���дһ���µķº��������������㡣
//��дһ��ʵ����������º������ܵ�С����


#endif//MATH_1_H