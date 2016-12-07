#include "../stdafx.h"

#ifndef COUNTER_POLICY_H
#define COUNTER_POLICY_H
//计数器策略：多线程情况下，保证计数器的顺序执行。要引入显式或者隐式的锁。
template<typename T>
class CounterPolicy{
public:
	CounterPolicy();
	CounterPolicy(CounterPolicy<T> const&);
	~CounterPolicy();
	CounterPolicy<T>& operator=(CounterPolicy<T> const&);

	//计数操作。
	void init(T*);
	void dispose(T*);
	void increment(T*);
	void decrement(T*);
	bool is_zero(T*);
};

#endif//COUNTER_POLICY_H