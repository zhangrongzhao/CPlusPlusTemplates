#include "../stdafx.h"

/*����ѡ��������á����ʽģ��ڵ㡱�ĸ���trait class
*--ͨ������£�������
*--����Scalar:��ֵ
*/

template<typename T>
class A_Scalar;

//primary template:reference
template<typename t>
class A_Traits{
public:
	typedef T const& ExprRef;//�����õ�����typedef��һ����������
};

//���Scalar���оֲ��ػ�
template<typename T>
class A_Traits<A_Scalar<T>>{
public:
	typedef A_Scalar<T> ExprRef;
};