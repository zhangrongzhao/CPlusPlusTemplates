#include "../stdafx.h"
//#include "typeop1.h"

template<typename T>
class TypeOp<T const>{//���const���͵ľֲ��ػ�
public:
	typedef T const ArgT;
	typedef T BareT;
	typedef T const ConstT;
	typedef T const& RefT;
	typedef T & RefBareT;
	typedef T const& RefConstT;
};