#include "../stdafx.h"

#ifndef ARRAY_SCALAR
#define ARRAY_SCALAR

//���ڱ�ʾ�Ŵ����Ķ����������
template<typename T>
class A_Scalar{
private:
	T const& s;
public:
	//���캯�������ڳ�ʼ��ֵ
	A_Scalar(T const& v),s(v){
	 
	}

	//���������±�������ԣ�ÿ��Ԫ�ص�ֵ������scalar�Ŵ�����ֵ
	T operator[](size_t idx){
		return s;
	}

	//scalar�Ĵ�С����Ԫ�ظ���Ϊ��0
	size_t size() const{
		return 0;
	}
};
#endif//ARRAY_SCALAR