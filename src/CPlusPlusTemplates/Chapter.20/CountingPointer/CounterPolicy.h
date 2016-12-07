#include "../stdafx.h"

#ifndef COUNTER_POLICY_H
#define COUNTER_POLICY_H

//�������ӿ����
class CounterPolicy{
public:
	//����4�������Ա(�������캯����һ������������һ��������ֵ����)
	//��ĳЩ�������Ҫ��ʾ�������������ǿɷ��ʵġ�
	CounterPolicy();
	CounterPolicy(CounterPolicy const&);
	~CounterPolicy();
	CounterPolicy& operator=(CounterPolicy const&);

	//����T�Ǳ�ָ��Ķ��������
	template<typename T> void init(T*);   //��ʼ��Ϊ1������Ϊ����������ռ�
	template<typename T> void dispose(T*);//�����漰�������ռ���ͷŲ���
	template<typename T> void increment(T*);//��1��ԭ�Ӳ���
	template<typename T> void decrement(T*);//��һ��Ժ�Ӳ���
	template<typename T> bool is_zero(T*);//����Ƿ�Ϊ0
};
#endif//COUNTER_POLICY_H