#include "../stdafx.h"

#ifndef COUNTER_POLICY_H
#define COUNTER_POLICY_H
//���������ԣ����߳�����£���֤��������˳��ִ�С�Ҫ������ʽ������ʽ������
template<typename T>
class CounterPolicy{
public:
	CounterPolicy();
	CounterPolicy(CounterPolicy<T> const&);
	~CounterPolicy();
	CounterPolicy<T>& operator=(CounterPolicy<T> const&);

	//����������
	void init(T*);
	void dispose(T*);
	void increment(T*);
	void decrement(T*);
	bool is_zero(T*);
};

#endif//COUNTER_POLICY_H