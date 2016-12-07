#include "../stdafx.h"
#ifndef MANAGED_TYPE_H
#define MANAGED_TYPE_H
#include "CountingPointer.h"
#include "MemberReferenceCount.h"

class ManagedType{
private:
	size_t ref_count;
public:
	typedef CountingPtr<ManagedType,
		                MemberReferenceCount<ManagedType, size_t, &ManagedType::ref_count>
	                   > Ptr;
};

#endif//MANAGED_TYPE_H


