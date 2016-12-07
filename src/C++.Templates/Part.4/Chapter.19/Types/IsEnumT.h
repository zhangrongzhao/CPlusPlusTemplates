#include "../stdafx.h"

#ifndef IS_ENUM_TYPE_H
#define IS_ENUM_TYPE_H
#include "IsFundaT.h"
#include "CompoundT.h"
//�ж��Ƿ�Ϊö�����͡�
struct SizeOverOne{ char c[2]; };

//����ģ�壺�������ͣ��������Ͳ���ת��Ϊö������
template<typename T,bool convert_possible=!CompoundT<T>::IsFunctionT &&!CompoundT<T>::IsArrayT>
class ConsumeUDC{
public:
	//����ת����������غ���:����ģ��ʵ��ConsumeUDC<T>ת��ΪT����
	operator T() const;
};

//�ػ����������ͣ��������Ͳ���ת��Ϊö������
//     ���ṩ����ת����������ء�
template<typename T>
class ConsumeUDC<T,false>{ };


//�ػ���void���Ͳ���ת��Ϊö������
//     ���ṩ����ת����������ء�
template<bool convert_possible>
class ConsumeUDC<void,convert_possible>{ };

//���ö���������غ�����
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

//����ʣ����������
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