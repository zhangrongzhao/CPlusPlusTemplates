#include "../stdafx.h"

#ifndef FUNCTION_POINTER_TYPE_H
#define FUNCTION_POINTER_TYPE_H

//primary template:���ڴ�����������������
template<typename RT,
	     typename P1=void,
		 typename P2=void,
		 typename P3=void>
class FunctionPtrT{
public:
	enum{ NumParams = 3 };
	typedef RT (*Type)(P1,P2,P3);
};

//���ڴ������������ľֲ��ػ�
template<typename RT,
	     typename P1,
         typename P2>
class FunctionPtrT<RT, P1, P2, void>{
public:
	enum{ NumParams = 2 };
	typedef RT (*Type)(P1,P2);
};

//���ڴ���һ�������ľֲ��ػ�
template<typename RT,typename P1>
class FunctionPtrT<RT, P1, void, void>{
public:
	enum{ NumParams = 1 };
	typedef RT(*Type)(P1);
};

//���ڴ���0�������ľֲ��ػ�
template<typename RT>
class FunctionPtrT<RT, void, void, void>{
public:
	enum{NumParams=0};
	typedef RT(*Type)();
};


#endif//FUNCTION_POINTER_TYPE_H