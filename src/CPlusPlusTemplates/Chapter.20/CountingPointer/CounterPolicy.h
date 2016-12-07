#include "../stdafx.h"

#ifndef COUNTER_POLICY_H
#define COUNTER_POLICY_H

//计数器接口设计
class CounterPolicy{
public:
	//以下4个特殊成员(两个构造函数，一个析构函数，一个拷贝赋值函数)
	//在某些情况不需要显示声明，但必须是可访问的。
	CounterPolicy();
	CounterPolicy(CounterPolicy const&);
	~CounterPolicy();
	CounterPolicy& operator=(CounterPolicy const&);

	//假设T是被指向的对象的类型
	template<typename T> void init(T*);   //初始化为1，可能为计数器分配空间
	template<typename T> void dispose(T*);//可能涉及计数器空间的释放操作
	template<typename T> void increment(T*);//增1的原子操作
	template<typename T> void decrement(T*);//减一的院子操作
	template<typename T> bool is_zero(T*);//检查是否为0
};
#endif//COUNTER_POLICY_H