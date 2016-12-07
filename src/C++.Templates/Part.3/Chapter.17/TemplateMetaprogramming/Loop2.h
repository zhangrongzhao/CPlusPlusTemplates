#include "../stdafx.h"

#ifndef LOOP_2_H
#define LOOP_2_H

template<int Dim,typename T>
class DotProduct{
public:
	static T result(T* a,T* b){
		return (*a)*(*b) + DotProduct<Dim - 1, T>::result(a+1,b+1);
	}
};

template<typename T>
class DotProduct<1,T>{
public:
	static T result(T* a,T* b){
		return (*a)*(*b);
	}
};
#endif//LOOP_2_H