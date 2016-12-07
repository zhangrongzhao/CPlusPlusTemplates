#include "stdafx.h"
#include <stddef.h>
#include <iostream>

template<typename T>
class TypeSize{
public:
	static size_t const value = sizeof(T);
};



