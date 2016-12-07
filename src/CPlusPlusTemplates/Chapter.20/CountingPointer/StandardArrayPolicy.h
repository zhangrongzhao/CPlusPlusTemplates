#include "../stdafx.h"

#ifndef STANDARD_ARRAY_POLICY_H
#define STANDAED_ARRAY_POLICY_H

class StandardArrayPolicy{
public:
	template<typename T>
	viod dispose(T* array){
		delete[] array;
	}
};

#endif//STANDARD_ARRAY_POLICY_H