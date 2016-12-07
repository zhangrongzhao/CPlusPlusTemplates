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

//���������͵�ת���ǲ������
template<typename T>
class ConsumeUDC<T,false>{
};

//��void���͵�ת���ǲ������
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

//�����float��int������ת��
char enum_check(float);
char enum_check(double);
char enum_check(long double);

SizeOverOne enum_check(...);//����ʣ����������

template<typename T>
class IsEnumT{
public:
	enum{Yes =  !IsFundaT<T>::Yes &&//���ǻ�������
				!CompoundT<T>::IsPtrT&&//����ָ������
				!CompoundT<T>::IsRefT&&//������������
				!CompoundT<T>::IsArrayT&&//������������
				!CompoundT<T>::IsPtrMemT&&//���ǳ�Աָ������
				sizeof(enum_check(ConsumeUDC<T>())) == 1};
	enum{No=!Yes};
};


#endif//IS_ENUM_TYPE