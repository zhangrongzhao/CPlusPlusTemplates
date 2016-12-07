#include "../stdafx.h"

#ifndef OBJECT_POLICY_H
#define OBJECT_POLICY_H

//ObjectPolicy接口设计
class ObjectPolicy{
public:
	//以下4个特殊成员(两个构造函数，一个析构函数，一个拷贝赋值运算符)
	//在某些情况下不需要显示声明，但必须是可访问的
	ObjectPolicy();
	ObjectPolicy(ObjectPolicy const&);
	~ObjectPolicy();
	ObjectPolicy& operator=(ObjectPolicy const&);

	//假设T是所指向对象的类型
	template<typename T> void dispose(T*);
};

#endif//OBJECT_POLICY_H