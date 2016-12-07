#include "../stdafx.h"
//#include "typeop1.h"

template<typename T>
class TypeOp<T const>{//针对const类型的局部特化
public:
	typedef T const ArgT;
	typedef T BareT;
	typedef T const ConstT;
	typedef T const& RefT;
	typedef T & RefBareT;
	typedef T const& RefConstT;
};