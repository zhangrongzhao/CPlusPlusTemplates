#include "../stdafx.h"

#ifndef STANDARD_OBJECT_POLICY_H
#define STANDARD_OBJECT_POLICY_H

class StandardObjectPolicy{
public:
	template<typename T>
	void dispose(T* object){
		delete object;
	}
};

#endif//STANDARD_OBJECT_POLICY_H