#include "../stdafx.h"

#ifndef DEFAULT_PARAMTER_H
#define DEFAULT_PARAMTER_H

template<typename T>
void foo(){
	T x = T();//T������ڽ����ͣ�x=0����x=false
}

template<typename T>
class MyClass{
private:
	T x;
public:
	MyClass() :x(){//ȷ��x�Ѿ���ʼ����
	
	}
};

#endif//DEFUALT_PARAMTER_H