#include "../stdafx.h"

#ifndef LOOP2_H
#define LOOP2_H
//primary template
template<int Dim,typename T>
class DotProduct{
public:
	static T result(T* a,T* b){
		return (*a)*(*b) + DotProduct<Dim - 1, T>::result(a+1,b+1);
	}
};

//��Ϊ���������ľֲ��ػ�
template<typename T>
class DotProduct<1,T>{
public:
	static T result(T* a,T* b){
		return (*a)*(*b);
	}
};

//��������
template<int DIM,typename T>
inline T dot_product(T* a,T* b){
	return DotProduct<DIM, T>::result(a,b);
}

#endif//LOOP2_H