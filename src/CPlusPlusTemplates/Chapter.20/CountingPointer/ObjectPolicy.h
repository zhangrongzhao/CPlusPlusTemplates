#include "../stdafx.h"

#ifndef OBJECT_POLICY_H
#define OBJECT_POLICY_H

//ObjectPolicy�ӿ����
class ObjectPolicy{
public:
	//����4�������Ա(�������캯����һ������������һ��������ֵ�����)
	//��ĳЩ����²���Ҫ��ʾ�������������ǿɷ��ʵ�
	ObjectPolicy();
	ObjectPolicy(ObjectPolicy const&);
	~ObjectPolicy();
	ObjectPolicy& operator=(ObjectPolicy const&);

	//����T����ָ����������
	template<typename T> void dispose(T*);
};

#endif//OBJECT_POLICY_H