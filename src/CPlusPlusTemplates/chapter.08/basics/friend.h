#include "../stdafx.h"

////��Ԫ��
//template<typename T>
//class Node;
//
//template<typename T>
//class Tree{
//	friend class Factory;//��ȷ����ʹ������Factory���״�������
//	friend class Node<T>;//����һ���ض�����ģ��ʵ��Ϊ��Ԫ������ģ�����������ǿɼ��ģ�����ģ����ǰ�����������������ܿ���֮ǰ�Ķ��塣
//};

////��Ԫ����
//template<typename T1,typename T2>
//void combine(T1,T2);
//
//class Mixer{
//	friend void combine<>(int&,int&);//T1=int&,T2=int&����ģ��ʵ������Ϊfriend��
//	friend void combine<int,int>(int,int);//T1=int,T2=int
//	friend void combine<char>(char,int);//T1=char,T2=int
//	//friend void combine<char>(char&,int);//����ƥ�亯��ģ��
//	friend void combine<>(long, long);//��Ԫ�������ܳ��ֶ��塣
//};

//void multiply(void*);//��ͨ����
//
//template<typename T>
//void multiply(T);//����ģ��
//
//class Comrades{
//	friend void multiply(int){ };//�������Ʋ����ޣ������������������Ҫ���򣺷����޺������Ʋ�������ģ��ʵ����ֻ��������ͨ���������ڸô�û�п���ƥ�����ͨ��������ô�����Ԫ�������Ǻ������״��������ú��������Ƕ��塣
//	friend void ::multiply(void*);//���޺������Ʊ�������һ���ٴ�֮ǰ�����ĺ������ߺ���ģ�塣���ȼ�����ͨ����>����ģ�塣
//	friend void ::multiply(int);//����ģ��ʵ����
//	friend void ::multiply<double*>(double*);//�������ƿ�����һ�Լ����ţ�����ģ���ٴ˱����ǿɼ��ġ�
//	//friend void ::error(){};//���޵���Ԫ����������һ�����塣
//};

//template<typename T>
//class Node{
//	Node<T>* allocate();
//};
//
//template<typename T>
//class List{
//	friend Node<T>* Node<T>::allocate();
//};
//
//template<typename T>
//class Creator{
//	friend void appear(Creator<T>*){}//����Ԫ������Creatorʵ������Ŵ��ڡ�
//};
//
//Creator<void> miracle;//ʵ������������Ԫ����
//Creator<double> oops; //��Ԫ�����ڶ��α����ɣ��ظ����塣

//��Ԫģ��
class Manager{
	template<typename T>
	friend class Task;

	//template<typename T>
	//friend void Schedule<T>::dispath(Task<T>*);

	template<typename T>
	friend int ticket(){
		return ++Manager::counter;
	}
	static int counter;
};