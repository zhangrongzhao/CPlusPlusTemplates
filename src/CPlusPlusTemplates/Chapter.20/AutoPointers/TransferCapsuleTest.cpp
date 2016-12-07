#include "stdafx.h"

#include "Holder2.h"
#include "TransferCapsule.h"

class Something{};

void read_something(Something* x){ }

TransferCapsule<Something> load_something(){
	Holder<Something> result(new Something());
	read_something(result.get());
	return result;
}

//int main(){
//	Holder<Something> ptr(load_something());
//}