#include "../stdafx.h"

#ifndef TYPENAME_H
#define TYPENAME_H

//typename:ģ���ڲ��ı�ʶ��������һ������

template<typename T>
class MyClass{
private:
	typename T::SubType* ptr;//SubType�Ƕ�����T�ڲ���һ�����͡�ptr��ָ��T::SubType���͵�ָ�롣�����ʹ��typename�ؼ��֣�SubType����ΪT���͵ľ�̬��Ա��
};

#endif//TYPENAME_H