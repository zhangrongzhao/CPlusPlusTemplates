#include "../stdafx.h"

#ifndef IS_ENUM_TYPE_H
#define IS_ENUM_TYPE_H
#include "IsFundaT.h"
#include "CompoundT.h"
//判断是否为枚举类型。
struct SizeOverOne{ char c[2]; };

//基本模板：函数类型，数组类型不能转换为枚举类型
template<typename T,bool convert_possible=!CompoundT<T>::IsFunctionT &&!CompoundT<T>::IsArrayT>
class ConsumeUDC{
public:
	//类型转换运算符重载函数:将类模板实例ConsumeUDC<T>转换为T类型
	operator T() const;
};

//特化：函数类型，数组类型不能转换为枚举类型
//     不提供类型转换运算符重载。
template<typename T>
class ConsumeUDC<T,false>{ };


//特化：void类型不能转换为枚举类型
//     不提供类型转换运算符重载。
template<bool convert_possible>
class ConsumeUDC<void,convert_possible>{ };

//检测枚举类型重载函数：
char enum_check(bool);
char enum_check(char);
char enum_check(signed char); 
char enum_check(unsigned char);
char enum_check(wchar_t);

char enum_check(signed short);
char enum_check(unsigned short);
char enum_check(signed int);
char enum_check(unsigned int);
char enum_check(signed long);
char enum_check(unsigned long);

#if LONGLONG_EXISTS
    char enum_check(signed long long);
    char enum_check(unsigned long long);
#endif//LONGLONG_EXISTS

char enum_check(float);
char enum_check(double);
char enum_check(long double);
SizeOverOne enum_check(...);

//捕获剩余的所有情况
template<typename T>
class IsEnumT{
public:
	enum{ Yes = IsFundaT<T>::No 
		     &&!CompoundT<T>::IsPointerT
			 &&!CompoundT<T>::IsReferenceT 
			 &&!CompoundT<T>::IsPointerToMemberT 
			 &&sizeof(enum_check(ConsumeUDC<T>())) == sizeof(char)
	};
	enum{ No = !Yes };
};

#endif//IS_ENUM_TYPE_H