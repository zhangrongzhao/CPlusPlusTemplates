#include "../stdafx.h"
//#include "typeop1.h"

template<typename T>
class TypeOp<T&>{//������õľֲ��ػ�
public:
	typedef T& ArgT;
	typedef T& RefT;
	typedef T const ConstT;
	typedef typename TypeOp<T>::BareT BareT;
	typedef typename TypeOp<T>::BareT & RefBareT;
	typedef T const & RefConstT;
};