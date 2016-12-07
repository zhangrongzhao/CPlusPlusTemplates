#include "../stdafx.h"

#ifndef IS_ENUM_TYPE
#define IS_ENUM_TYPE
#include "CompoundType.h"
#include "FundamentalType.h"

struct SizeOverOne{ char c[2]; };

template<typename T,bool convert_possible=!CompoundT<T>::IsFuncT && !CompoundT<T>::IsArrayT>
class ConsumeUDC{
public:
	operator T() const;
};

//到函数类型的转型是不允许的
template<typename T>
class ConsumeUDC<T,false>{
};

//到void类型的转型是不允许的
template<bool convert_possible>
class ConsumeUDC<void,convert_possible>{

};

char enum_check(bool);
char enum_check(char);
char enum_check(signed char);
char enum_check(unsigned char);
char enum_check(wchar_t);

char enum_check(signed short);
char enum_check(unsigned short);
char enum_check(signed int);
char enum_check(unsigned short);
char enum_check(signed long);
char enum_check(unsigned long);

#if LONGLONG_EXISTS
char enum_check(signed long long);
char enum_check(unsigned long long);
#endif//LONGLONG_EXISTS

//避免从float从int的意外转型
char enum_check(float);
char enum_check(double);
char enum_check(long double);

SizeOverOne enum_check(...);//捕获剩余的所有情况

template<typename T>
class IsEnumT{
public:
	enum{Yes =  !IsFundaT<T>::Yes &&//不是基本类型
				!CompoundT<T>::IsPtrT&&//不是指针类型
				!CompoundT<T>::IsRefT&&//不是引用类型
				!CompoundT<T>::IsArrayT&&//不是数组类型
				!CompoundT<T>::IsPtrMemT&&//不是成员指针类型
				sizeof(enum_check(ConsumeUDC<T>())) == 1};
	enum{No=!Yes};
};


#endif//IS_ENUM_TYPE