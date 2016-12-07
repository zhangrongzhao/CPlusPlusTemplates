#include "../stdafx.h"

#ifndef COUNTING_POINTER_TEST_H
#define COUNTING_POINTER_TEST_H
#include "CountingPointer.h"
#include "MemberReferenceCount.h"
class ManagedType{
private:
	size_t ref_count;
public:
	typedef CountingPointer<ManagedType, MemberReferenceCount<ManagedType, size_t, &ManagedType::ref_count>> ptr;

};


#endif//COUNTING_POINTER_TEST_H