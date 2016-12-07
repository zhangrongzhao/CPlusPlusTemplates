#include "../stdafx.h"

#ifndef DUO_TYPE_H
#define DUO_TYPE_H
#include "duo1.h"
#include "duo2.h"
//���ڻ�ȡduo�ĵ�N��������͵Ļ���ģ��
template<int N,typename T>
class DuoT{
public:
	typedef void ResultT;//һ������£��ṹ������void
};

//�����ͨduo�ĵ�һ������ػ�
template<typename A,typename B>
class DuoT<1,Duo<A,B>>{
public:
	typedef A ResultT;
};

//�����ͨduo��2������ػ�
template<typename A,typename B>
class DuoT<2,Duo<A,B>>{
public:
	typedef B ResultT;
};

//��Կɵݹ�Duo��N��������͵��ػ�
template<int N,typename A,typename B,typename C>
class DuoT<N,Duo<A,Duo<B,C>>>{
public:
	typedef typename DuoT<N - 1, Duo<B, C>>::ResultT ResultT;
};

//��Կɵݹ�duo��һ������ػ�
template<typename A,typename B,typename C>
class DuoT<1, Duo<A, Duo<B, C>> > {
public:
	typedef A ResultT;
};

//��Կɵݹ�duo�ĵڶ�����ľֲ��ػ�
template<typename A,typename B,typename C>
class DuoT<2,Duo<A,Duo<B,C>>>{
public:
	typedef B ResultT;
};

#endif//DUO_TYPE_H