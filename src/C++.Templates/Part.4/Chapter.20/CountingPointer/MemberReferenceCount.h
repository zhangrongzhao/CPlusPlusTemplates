#include "../stdafx.h"

#ifndef MEMBER_REFERENCE_COUNT_H
#define MEMBER_REFERENCE_COUNT_H
template<typename ObjectT,//包含计数器的类型。
	     typename CountT,//计数器的类型。
		 CountT ObjectT::*CountP>//计数器的位置。
class MemberReferenceCount{
public:
	//缺省构造函数和析构函数都是允许的。

	//让计数器的值初始化为1
	void init(ObjectT* object){
		object->*CountP = 1;
	}

	void dispose(ObjectT*){ }

	void increment(ObjectT* object){
		++object->*CountP;
	}

	void decrement(ObjectT* object){
		--object->*CountP;
	}

	void is_zero(ObjectT* object){
		return object->CountP == 0;
	}
};
#endif//MEMBER_REFERENCE_COUNT_H