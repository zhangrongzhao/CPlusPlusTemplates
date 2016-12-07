#include "stdafx.h"

#include <iostream>
#include "apply1.h"

void increment(int& a){
	++a;
}

void print(int a){
	std::cout << a << std::endl;
}

/*
int main(){
	//int x = 7;
	//apply(x,increment);
	//apply(x,print);

}*/
