#include "../stdafx.h"
#include <iostream>

/*
template<typename T>
class S{
public:
	void info(){
		std::cout << "generic(S<T>::info())" << std::endl;
	}
};

template<>
class S<void> {//ȫ���ػ�������Ҫ��ԭ���ķ���ʵ�����κι�������������в�ͬ���Ƶĳ�Ա������ȫ���ػ�ֻ����ģ��������й�����
	void msg(){
		std::cout << "fully specialized (S<void>::msg)" << std::endl;
	}
};
*/

/*
template<typename T>
class Types{
public:
	typedef int I;
};

template<typename T,typename U=typename Types<T>::I>
class S;//(1)

template<>
class S<void> {//(2)
public:
	void f();
};

template<>
class S<char,char>;//(3)

//template<>
//class S<char,0>;//���󣬲���ʹ��0���������Ͳ���U;0�������͡�

template<>
class S<char,char> {

};
*/

/*
template<typename T>
class S;

template<>
class S<char**> {
public:
	void print() const;
};

//��ģ���ػ������ģ��ʵ����Ա��ʵ�֣��൱����ͨ���Ա��ʵ��.���ﲻ��ʹ��Template<>ǰ׺��
void S<char**>::print()const{

}*/

/*
template<typename T>
class Outside{
public:
	template<typename U>
	class Inside{};
};

template<>
class Outside<void> {
public://���涨���Ƕ�������ģ���е�Ƕ����û���κι�ϵ��
	template<typename U>
	class Inside{
	private:
		static int count;
	};
};

template<typename U>
int Outside<void>::Inside<U>::count = 1;

template<typename T>
class Invalid{};

template<>
class Invalid<double>{

};

Invalid<double> x1;
*/

/*
template<typename T>
int f(T){//(1)
	return 1;
}

template<typename T>
int f(T*){//(2)
	return 2;
}

template<>
int f(int){//OK,(1)�����ػ���
	return 3;
}

template<>
int f(int*){
	return 4;//(2)���ػ���
}
*/

/*
//template<typename T>
//int f(T,T x=42){
//	return x;
//}

//template<>
//int f(int,int=30){//ȫ�ֺ���ģ���ػ����ܰ���ȱʡʵ��ֵ��
//
//}
*/

template<typename T>
int g(T,T x=42){
	return x;
}

template<>
int g(int x,int y){
	return y / 2;
}

