#include "../stdafx.h"

#ifndef MEMBER_REFERENCE_COUNT_H
#define MEMBER_REFERENCE_COUNT_H

//侵入式计数器模板
template<typename ObjectT,//包含计数器的类型
         typename CountT,//计数器的类型
		 CountT ObjectT::*CountP//计数器的位置
>
class MemberReferenceCount{
public:
	//缺省构造函数和析构函数都是允许的

	//让计数器的值初始化为1
	void init(ObjectT* object){
		object->*CountP = 1;
	}

	//对于计数器的释放，并不需要显示执行任何操作
	void dispose(ObjectT* object){}

	//计数值加1
	void increment(ObjectT* object){
		++(object->*CountP);
	}

	//计数器减1
	void decrement(ObjectT* object){
		--(object->*CountP);
	}

	//检查计数值是否为0
	template<typename T>
	bool is_zero(ObjectT* object){
		return (object->*CountP) == 0;
	}
};

#endif//MEMBER_REFERENCE_COUNT_H