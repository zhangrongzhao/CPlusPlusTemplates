#include "stdafx.h"

#include <string>
#include <iostream>
#include "BindConv.h"
#include "..\FunctionPtr\FuncPtr.h"

bool func(std::string const& str,double d,float f){
	std::cout << str << ":" << d << (d < f ? "<" : ">=") << f << "\n";
	return d < f;
}

int main(){
	bool result = bind<1>(func_ptr(func),"Comparing")(1.0,2.0);
	std::cout << "bound function reeturned " << result << "\n";
}