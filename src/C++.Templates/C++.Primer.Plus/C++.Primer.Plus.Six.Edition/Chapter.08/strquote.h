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
	return temp;//返回前,将值拷贝到临时内存,然后临时变量占用的内存被销毁。调用函数将从临时内存获取字符串。
}

const std::string& version2(std::string& s1,const std::string& s2){
	s1 = s2 + s1 + s2;
	return s1;
}

const std::string& version3(const std::string& s1,const std::string& s2){
	std::string temp;
	temp = s2 + s1 + s2;
	return temp;//临时变量在返回时，已经销毁，占用的内存已经被回收。返回时，让引用类型引用已经释放的内存，系统会崩溃。
}

#endif//STR_QUOTE_H