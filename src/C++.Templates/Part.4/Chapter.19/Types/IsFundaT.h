#include "../stdafx.h"

#ifndef IS_FUNDA_T
#define IS_FUNDA_T

//基本模板：默认情况，T不是基本类型。
template<typename T>
class IsFundaT{
public:
	enum{ Yes = 0 };
	enum{ No = 1 };
};

//用于特化基本类型的宏
#define MK_FUNDA_TYPE(T) \
template<>               \
class IsFundaT <T> {     \
public:                  \
	enum{ Yes = 1 };     \
	enum{ No = 0 };      \
};                       \

MK_FUNDA_TYPE(void);

MK_FUNDA_TYPE(bool);
MK_FUNDA_TYPE(char);
MK_FUNDA_TYPE(signed char);
MK_FUNDA_TYPE(unsigned char);
MK_FUNDA_TYPE(wchar_t);

MK_FUNDA_TYPE(signed short);
MK_FUNDA_TYPE(unsigned short);
MK_FUNDA_TYPE(signed int);
MK_FUNDA_TYPE(unsigned int);
MK_FUNDA_TYPE(signed long);
MK_FUNDA_TYPE(unsigned long);

#if LONGLOING_EXISTS
   MK_FUNDA_TYPE(signed long long);
   MK_FUNDA_TYPE(unsigned long long);
#endif//LONGLONG_EXISTS

MK_FUNDA_TYPE(float);
MK_FUNDA_TYPE(double);
MK_FUNDA_TYPE(long double);

#endif//IS_FUNDA_H