#include "../stdafx.h"
//#include "typeop1.h"

template<>
class TypeOp<void>{//���void��ȫ���ػ�
public:
	typedef void ArgT;
	typedef void BareT;
	typedef void const ConstT;
	typedef void RefT;
	typedef void RefBareT;
	typedef void RefConstT;
};