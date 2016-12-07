#include "../stdafx.h"

#ifndef R_PARAM_H
#define R_PARAM_H
#include <array>
#include "IsClassT.h"
#include "IfThenElse.h"

////ֻ���������ݣ�С��2��ָ���С�����ͣ�����ֵ���ݣ�����2��ָ���С�����ͣ�����(����const&)const&.
//template<typename T>
//class RParam{
//public:
//	typedef typename IfThenElse<(sizeof(T)<2*sizeof(void*)),T,T const&>::ResultT ResultT;
//};

//ֻ���������ݣ�������==>const&,��������==>ֵ���ݡ�
template<typename T>
class RParam{
public:
	typedef typename IfThenElse<IsClassT<T>::Yes,T const&,T>::ResultT Type;
};

////�ֲ��ػ��������������,����const&������ԭʼ���ݣ�����ԭʼ���ݼ��Ա�����ԭ��sizeof���غ�С��ֵ�����ǿ����漰������Ĺ��캯����
//template<typename T>
//class RParam<array<T> >{
//public:
//	typedef array<T> const& Type;
//};

#endif//R_PARAM_H