#include "../stdafx.h"
#ifndef STR_QUOTE_H
#define STR_QUOTE_H

//#include <iostream>
#include <string>

//declaration:function prototype
std::string version1(const std::string& s1,const std::string& s2);
const std::string& version2(std::string& s1, const std::string& s2);
const std::string& version3(std::string& s1,const std::string& s2);

//defination
std::string version1(const std::string& s1,const std::string& s2){
	std::string temp;
	temp = s2 + s1 + s2;
	return temp;//����ǰ,��ֵ��������ʱ�ڴ�,Ȼ����ʱ����ռ�õ��ڴ汻���١����ú���������ʱ�ڴ��ȡ�ַ�����
}

const std::string& version2(std::string& s1,const std::string& s2){
	s1 = s2 + s1 + s2;
	return s1;
}

const std::string& version3(const std::string& s1,const std::string& s2){
	std::string temp;
	temp = s2 + s1 + s2;
	return temp;//��ʱ�����ڷ���ʱ���Ѿ����٣�ռ�õ��ڴ��Ѿ������ա�����ʱ�����������������Ѿ��ͷŵ��ڴ棬ϵͳ�������
}

#endif//STR_QUOTE_H