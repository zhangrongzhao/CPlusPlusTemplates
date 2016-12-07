#include "../stdafx.h"

#ifndef IS_FUNCTION_TYPE_H
#define IS_FUNCTION_TYPE_H
//����Ԫ�����Ͳ���Ϊvoid���������ͣ��������͡�
//���ģ�����T������������֮һ����testģ��ѡ��ʡ�Ժ�Ϊ������ģ�塣
//Ȼ���ų�void���������͡���ʣ�µ����;��Ǻ������͡�
template<typename T>
class IsFunctionT{
private:
	typedef char One;
	typedef struct { char c[2]; } Two;

	template<typename U> static Two test(U(*)[1]);
	template<typename U> static One test(...);
public:
	enum{ Yes = sizeof(test<T>(0)) == sizeof(One) };
	enum{ No = !Yes };
};

//�ػ����ų�void����,void���Ͳ��Ǻ�������
template<>
class IsFunctionT<void>{
public:
	enum{ Yes = 0 };
	enum{ No = !Yes };
};

//�ػ����ų��������ͣ��������Ͳ��Ǻ������͡�
template<typename T>
class IsFunctionT<T&>{
public:
	enum{ Yes = 0 };
	enum{ No = !Yes };
};


#endif//IS_FUNCTION_TYPE_H