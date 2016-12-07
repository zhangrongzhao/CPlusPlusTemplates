#include "../stdafx.h"

template<typename T>
class TypeOp{
public:
	typedef T ArgT;
	typedef T BareT;
	typedef T const ConstT;
	typedef T& RefT;
	typedef T& RefBareT;
	typedef T const & RefConstT;
};