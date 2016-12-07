#include "../stdafx.h"
#include <stddef.h>

template<typename CountedType>
class ObjectCounter{
private:
	static size_t count;//存在对象的个数
protected:
	//缺省构造函数
	ObjectCounter(){
		++ObjectCounter<CountedType>::count;
	}

	//拷贝构造函数
	ObjectCounter(ObjectCounter<CountedType> const& ){
		++ObjectCounter<CountedType>::count;
	}

	//析构函数
	~ObjectCounter(){
		--ObjectCounter<CountedType>::count;
	}
public:
	//返回存在对象的个数
	static size_t live(){
		return ObjectCounter<CountedType>::count;
	}
};

//用0来初始化count
template<typename CountedType>
size_t ObjectCounter<CountedType>::count = 0;