#include "../stdafx.h"

#ifndef IS_FUNCTION_TYPE
#define IS_FUNCTION_TYPE
template<typename T>
class IsFunctionT{
private:
	typedef char One;
	typedef struct{ char a[2]; } Two;
	template<typename U> static One test(...);
	template<typename U> static Two test(U (*)[1]);
public:
	enum{ Yes = sizeof(IsFunctionT<T>::test<T>(0)) == 1 };
	enum{ No = !Yes };
};

template<typename T>
class IsFunctionT<T&>{
public:
	enum{ Yes = 0 };
	enum{ No = !Yes };
};

template<>
class IsFunctionT<void>{
public:
	enum{ Yes = 0 };
	enum{ No = !Yes };
};

template<>
class IsFunctionT<void const>{
public:
	enum{Yes=0};
	enum{No=!Yes};
};

#endif//IS_FUNCTION_TYPE