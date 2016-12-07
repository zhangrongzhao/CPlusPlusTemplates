#include "../stdafx.h"

#ifndef TRANSFER_CAPSULE_TEST_H
#define TRANSFER_CAPSULE_TEST_H
#include "../Holder/Holder.h"
#include "TransferCapsule.h"

class Something{ };

void read_something(Something*){ }

TransferCapsule<Something> load_something(){
	Holder<Something> result(new Something);
	read_something(result.get());
	return result;
}

void test_Holder_TransferCapsule(){
	Holder<Something> ptr(load_something());
}



#endif//TRANSFER_CAPSULE_TEST_H