#include "../stdafx.h"
#ifndef ACCUMULATION_TRAITS_H
#define ACCUMULATION_TRATTS_H

//����1��T=char�ǣ��ۼӼ��������
//�޸Ľ���:���������ģ�����T��ء����Ը���ģ�����T�����ͣ������ػ�����ȡ��ؼ����������͡�
template<typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<char>{
public:
	typedef char ElementT;
	typedef int ResultT;
	static ResultT zero(){
		return 0;
	};
};

template<>
class AccumulationTraits<short>{
public:
	typedef short ElementT;
	typedef int ResultT;
	static ResultT zero(){
		return 0;
	};
};

template<>
class AccumulationTraits<int>{
public:
	typedef int ElementT;
	typedef long ResultT;
	static ResultT zero(){
		return 1;
	};
};

template<>
class AccumulationTraits<unsigned int>{
public:
	typedef unsigned int ElementT;
	typedef unsigned long ResultT;
	static ResultT zero(){
		return 0;
	};
};

template<>
class AccumulationTraits<float>{
public:
	typedef float ElementT;
	typedef double ResultT;
	static ResultT zero(){
		return 0;
	};
};

//.....�������͡�
#endif//ACCUMULATION_TRAITS_H

