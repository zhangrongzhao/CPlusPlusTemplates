#include "../stdafx.h"

class DefaultInitOnly{
public:
	DefaultInitOnly(){};
private:
	DefaultInitOnly(DefaultInitOnly const&);//不存在拷贝操作
};

template<typename T>
class Statics{
private:
	static T sm;
};

//特化声明：不存在可以用来提供一个定义的语法
template<>
DefaultInitOnly Statics<DefaultInitOnly>::sm;

