#include "../stdafx.h"

#ifndef DUO_TYPE_H
#define DUO_TYPE_H
#include "Duo.h"
//��ȡ��N��������͡�
//��ȡ���͵�˼·��
/*1.��Duo���͵ĵ�N���������==>void
  2.Duo���ͣ�
    2.1�ǵݹ�Duo����==>��һ�������ͣ��ڶ��������͡�
	2.2�ݹ�Duo����==>��N��������͡�
*/


//����ģ��:�����Duo���ͣ���ÿ����Ϊvoid���͡�
template<int N,typename T>
class DuoT{
public:
	typedef void ResultT;
};

//�ػ�1������Duo�ǵݹ����͡�ֻ��������
//��ȡ��һ��������
template<typename A,typename B>
class DuoT<1, Duo<A, B>> {
public:
	typedef A ResultT;
};
//��ȡ�ڶ��������͡�
template<typename A,typename B>
class DuoT <2, Duo<A, B>> {
public:
	typedef B ResultT;
};


//�ػ�2������Duo�ݹ����͡�
template<int N,typename A,typename B,typename C>
class DuoT<N,Duo<A,Duo<B,C>>>{
public:
	typedef typename DuoT<N - 1, Duo<B, C>>::ResultT ResultT;
};

//Ϊ�ػ�2��Ѱ�ҵݹ���ڡ�
template<typename A,typename B,typename C>
class DuoT<1,Duo<A,Duo<B,C>>>{
public:
	typedef A ResultT;
};

template<typename A,typename B,typename C>
class DuoT<2,Duo<A,Duo<B,C>> > {
public:
	typedef B ResultT;
};

#endif//DUO_TYPE_H