#include "../stdafx.h"

//primary template:����ģ��
template<typename T1,typename T2>
class MyClass{};

//�ֲ��ػ�1������ģ�����������ͬ����
template<typename T>
class MyClass <T,T> {};

//ͬ����ָ����ػ�
template<typename T>
class MyClass <T*,T*> {};

//�ֲ��ػ�2���ڶ���ģ�����������int
template<typename T>
class MyClass <T,int> {};

//�ֲ��ػ�2������ģ���������ָ������
template<typename T1,typename T2>
class MyClass <T1*, T2*> {};