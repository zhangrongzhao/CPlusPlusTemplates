#include "../stdafx.h"

#ifndef ADD_VALUE_H
#define ADD_VALUE_H
#include <string>
template<typename T,int VALUE>
T addValue(T const& x){
	return x + VALUE;
}
//std::transform(source.begin(),source.end(),dest.begin(),(int (*)(int const&))addValue<int,5>);

//template<double VALUE>//error: illegal type for non-type template paramter 'VALUE'
//double process(double v){
//	return v*VALUE;
//}

//template<std::string name>//error:illegal type for non-type template paramter 'name'//�ַ����������ڲ����Ӷ��󣬾�����ͬ���Ƶ����ڲ�ͬģ����ַ�����������ȫ��ͬ�Ķ���
//class MyClass{};
//
//template<char const* name>
//class MyClass1{};

//MyClass1<"hello"> x;
//a template argument may not reference a non-external entity.
//
//char const * s = "hello";
//MyClass1<s> x;//expression must have a constant value  in compling time.


//extern char const s[] = "hello";//�ַ���������Ϊ�ⲿ���Ӷ���
//MyClass1<s> x;//

#endif//ADD_VALUE_H