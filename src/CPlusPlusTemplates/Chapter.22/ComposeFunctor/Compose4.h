#include "../stdafx.h"

#ifndef COMPOSE_4_H
#define COMPOSE_4_H

//Ϊ����̳��ظ����࣬����һ���̳в������
template<typename C,int N>
class BaseMem :public C{
public:
	BaseMem(C& c):C(c){ }
	BaseMem(C const& c):C(c){ }
};

#endif//COMPOSE_4_H