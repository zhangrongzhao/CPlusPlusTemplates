#include "stdafx.h"

//����ģ��
template<typename T>
int g(T, T x = 42){ return x; }


//�ػ�:����ֻ���������壬��֪����������ʹ�û���ģ�壬ʹ���ػ�ģ�塣Ҳ�����ڲ�ͬ��Ԫ���ػ�ģ���ظ����塣
template<>
int g(int, int);
