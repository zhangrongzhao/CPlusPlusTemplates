#include "../stdafx.h"

#ifndef PRINT_COLLECTION_H
#define PRINT_COLLECTION_H

#include <iostream>
#include <bitset>
template<typename T>
void printCollection(T const& collection){
	typename T::const_iterator pos;//����collection�ĵ�����
	typename T::const_iterator end(collection.end());//����λ��

	for (pos = collection.begin(); pos != end;++pos){
		std::cout << *pos << "";
	}
	std::cout << std::endl;
}

//class stlContainer{
//	typedef ... iterator;//��д������
//	typedef ... const_iterator;//ֻ��������
//};

////���ƵĹ���
//template<int N>
//void printBitset(std::bitset<N> const& bs){
//	std::cout << bs.template to_string<char,char_trait<char>,allocator<char> >();//bs��������ģ�����N�Ĺ��죬.template��֪������to_string��������ģ�����N�Ķ���bs�ĳ�Ա����ģ�塣
//}


template<typename T>
class Base{
public:
	exit();
};

template<typename T>
class Derived:Base<T>{
public:
	void foo(){
		//Base<T>::exit();
		this->exit();//ʹ��Base<T>,����this->�޶��Գ�Ա�����ķ��ʡ�
	}
}





#endif//PRINT_COLLECTION_H