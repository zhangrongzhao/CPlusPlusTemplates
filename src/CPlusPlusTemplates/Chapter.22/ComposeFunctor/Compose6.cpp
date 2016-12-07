#include "stdafx.h"

#include <iostream>
#include "..\FunctionPtr\FuncPtr.h"
#include "Compose6.h"

double add(double a,double b){
	return a + b;
}

double twice(double a){
	return 2 * a;
}

//int main(){
//	std::cout << "compute (20+7)*2:" << compose(func_ptr(add),func_ptr(twice))(20,7)<< std::endl;
//}