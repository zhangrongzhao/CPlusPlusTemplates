#include "../stdafx.h"

#ifndef COMPOSE_4_H
#define COMPOSE_4_H

//为解决继承重复基类，增加一个继承层来解决
template<typename C,int N>
class BaseMem :public C{
public:
	BaseMem(C& c):C(c){ }
	BaseMem(C const& c):C(c){ }
};

#endif//COMPOSE_4_H