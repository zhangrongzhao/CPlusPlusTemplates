#include "../stdafx.h"

#ifndef PARTIAL_SPECIALIZATION_1_H
#define PARTIAL_SPECIALIZATION_1_H
/*��ģ��ľֲ��ػ�*/

//����ģ��
template<typename T1,typename T2>
class MyClass{  };

//partial specialization:�ֲ��ػ�
template<typename T>
class MyClass<T, T>{ };

template<typename T>
class MyClass<T,int>{ };

template<typename T>
class MyClass<T*, T*>{ };

template<typename T1,typename T2>
class MyClass<T1*,T2*>{ };
#endif//PARTIAL_SPECIALIZATION_1_H