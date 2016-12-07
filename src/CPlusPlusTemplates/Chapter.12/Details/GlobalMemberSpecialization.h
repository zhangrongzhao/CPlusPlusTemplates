#include "../stdafx.h"
#include <iostream>
/*******************primary template****************************************/
template<typename T>
class Outer{//(1)
public:
	template<typename U>//(2)
	class Inner{
	private:
		static int count;//(3)
	};
	static int code;//(4)
	void print() const{//(5)
		std::cout << "generic" << std::endl;
	}
};

template<typename T>
int Outer<T>::code = 6;//(6)

template<typename T>
template<typename U>
int Outer<T>::Inner<U>::count = 7;//(7)
/******************specialize���ػ���Χģ��**********************************/
template<>
class Outer<bool> {//(8)
public:
	template<typename U>//(9)
	class Inner{
	private:
		static int count;//(10)
	};
	void print()const{//(11)

	}
};


template<>
int Outer<void>::code;//�Ƕ���������﷨���Ƕ�������

template<>
void Outer<void>::print() const;

/******************specialize���ػ��ڲ�ģ��**********************************/
template<>
template<typename X>
class Outer<wchar_t>::Inner{//������е��ڲ���û���κι�ϵ��
public:
	static long count;//��Ա���ͷ����ı�
};

template<>
template<typename X>
long Outer<wchar_t>::Inner<X>::count;

/******************specialize���ڲ�ģ���ȫ���ػ�**********************************/
template<>
template<>
class Outer<char>::Inner <wchar_t> {
public:
	enum{ count = 1 };
};

template<>
class Outer<bool>::Inner<wchar_t> {
public:
	enum{ count = 2 };
};