#include "../stdafx.h"

//void foo(){
//	int x;//xû�г�ʼ��������һ����ȷ����ֵ
//	int* ptr;//ptrָ��δ��ʼ����ָ��ĳ���ڴ档����������ָ��
//}


//template<typename T>
//void foo(){
//	T x;//���T���ڽ����ͣ���ôX������һ����ȷ����ֵ��
//}

//template<typename T>
//void foo(){
//	T x = T();//���T���ڽ����ͣ��������Ĭ�Ϲ����������ʼ��Ϊ0����false��
//}

template<typename T>
class MyClass{
private:
	T x;
	T y;
public:
	MyClass():x(),y(){//����x��Ĭ�Ϲ��캯�����г�ʼ�����ڽ����Ͷ���Ҳ����ˡ�
	}
};
