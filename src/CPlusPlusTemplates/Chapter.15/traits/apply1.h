#include "../stdafx.h"
#include "typeop1.h"
#include "typeop2.h"
#include "typeop3.h"
#include "typeop4.h"

//template<typename T>
//void apply(T& arg,void(*func)(T)){
//	func(arg);
//}

template<typename T>
void apply(typename TypeOp<T>::RefT arg,void(*func)(T)){
	func(arg);
}
