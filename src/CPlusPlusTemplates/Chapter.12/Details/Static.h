#include "../stdafx.h"

class DefaultInitOnly{
public:
	DefaultInitOnly(){};
private:
	DefaultInitOnly(DefaultInitOnly const&);//�����ڿ�������
};

template<typename T>
class Statics{
private:
	static T sm;
};

//�ػ������������ڿ��������ṩһ��������﷨
template<>
DefaultInitOnly Statics<DefaultInitOnly>::sm;

