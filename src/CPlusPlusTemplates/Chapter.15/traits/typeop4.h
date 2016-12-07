#include "../stdafx.h"
//#include "typeop1.h"

template<>
class TypeOp<void>{//针对void的全局特化
public:
	typedef void ArgT;
	typedef void BareT;
	typedef void const ConstT;
	typedef void RefT;
	typedef void RefBareT;
	typedef void RefConstT;
};