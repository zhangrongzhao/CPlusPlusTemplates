#include "../stdafx.h"
#include <iostream>
//primary template
template<int N>
class Pow3{
public:
	//static int const result = 3 * Pow3<N-1>::result;//��̬��Ա����ֻ������ֵ����ֵ����������ʱ��������ǿ��ʵ������̬��Ա��������Ϊ�ö�������ڴ档���ھ����ڱ�����Ч����
	enum{ result = 3 * Pow3<N-1>::result };//
};

//global sepialization
template<>
class Pow3 <0> {
public:
	//static int const result = 1;
	enum{ result = 1 };
};

void test_pow3(){
	std::cout << "Pow3<7>::result" << Pow3<7>::result << std::endl;
}
