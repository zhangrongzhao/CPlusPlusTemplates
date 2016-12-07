#include "stdafx.h"
#include <iostream>
int C;
class C{
private:
	int i[2];
public:
	static int f(){
		return sizeof(C);//C可以看做是一个非受限名称。
	}
};

int f(){
	return sizeof(C);
}

int main(){
	std::cout << "C::f()==" << C::f() << "," << std::endl;
	std::cout << "::f()" << ::f() << std::endl;
};