#include "../stdafx.h"

extern "C++" template<typename T>//Ĭ������ı�׼����,Ĭ������¿��Բ�д
void normal();

//extern "C" template<typename T>
//void invalid();
//
//extern "Xroma" template<typename T>
//void xroma_link();

template<typename T>
void external();//��Ϊһ������������λ�������ļ�����ͬ���Ƶ�ʵ�塣������λ�������ļ���external()����ģ�壬Ҳ��Ϊǰ��������

template<typename T>
static void internal();//�������ļ��о�����ͬ���Ƶ�ģ��û�й�ϵ���������ⲿ���ӡ�
