#include "../stdafx.h"

//Ϊ����ģ����ӷ����Ͳ���
//������ģ����������ƣ�������������ö��ֵ������ָ���ⲿ���Ӷ����ָ�롣
template<typename T,int VAL>
T addValue(T const& x){
	return x + VAL;
}

//ERROR:������������Ϊ������ģ�����
//template<double VAT>
//double process(double v){
//	return v*VAT;
//}


//���������Ϊ������ģ�����
//illegal type for non-type template parameter 'name'
//template<std::string name>
//class MyClass{
//
//};


//��ģ�����������һ���ڲ����Ӷ���
//template<char const* name>
//class MyClass{
//
//};
//
//char const* const s = "hello";//s���ڲ����Ӷ���
//MyClass<s> x;//s��һ��ָ���ڲ����Ӷ����ָ��


//������ģ����������ǣ�������������ö�٣���������ָ���ⲿ���Ӷ����ָ�롣
template<char const* name>
class MyClass{};
 
extern char const s[] = "hello";//s���ⲿ���Ӷ���
MyClass<s> x;//



