#include "../stdafx.h"
#include <iostream>

//��ӡSTL������Ԫ��
template<typename T>
void printcol1(T const& col1){
	typename T::const_iterator pos;//���ڵ���col1�ĵ�����
	typename T::const_iterator end(col1.end());//����λ��

	for (pos = col1.begin(); pos != end;++pos){
		std::cout << *pos << " ";
	}
	std::cout << std::endl;
}

//class stlcontainer{
//	//typedef ... iterator//�ɶ�д�ĵ�����
//	//typedef ... const_iterator//ֻ�ܶ����ʵĵ�����
//};

//template<int N>
//void printBitset(std::bitset<N> const& bs){
//	//bs��������ģ�����N�Ĺ���
//	std::cout << bs.template to_string<char.char_traits<char>,allocator<char>>();
//}
