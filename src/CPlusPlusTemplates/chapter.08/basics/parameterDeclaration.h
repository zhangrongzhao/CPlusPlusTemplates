#include "../stdafx.h"
//#include 

//declaration
template<typename T>
class List{
public :
	template<typename T2>
	List(List<T2>& const&);//��Ա����ģ�壨���캯����
};

//definition
template<typename T>
template<typename T2>
List<T>::List(List<T2> const&){};//λ�����ⲿ�ĳ�Ա����ģ�嶨��

template<typename T>
int length(List<T> const&);//λ���ⲿ���ֿռ�������ĺ���ģ��

class Collection{
	
	template<typename T>
	class Node{};//λ�����ڲ��ĳ�Ա��ģ��Ķ���

	template<typename T>
	class Handle;//λ�����ڲ��ĳ�Ա��ģ����������˴�û�ж���

    template<typename T>
	T* alloc(){};//λ�����ڲ��ĳ�Ա����ģ��Ķ��壬Ҳ��һ����ʾ��������
};


//template<typename T>
//class Collection:Handle{//һ��������ⲿ����ĳ�Ա��ģ�壬�˴�Ϊ����ģ��Ķ���
//
//};


template<typename T>
union AllocChunk{//unionģ�壬����������ģ���е�һ�֡�
	T object;
	unsigned char bytes[sizeof(T)];
};

//����ģ���������Ծ���ȱʡ����ʵ��
template<typename T>
void report_top(Stack<T> const&,int number=0);

template<typename T>
void fill(Array<T>*,T const&=T());//���ڻ�������T()Ϊ0��ȱʡ����ʵ�ο���������ģ�����T

class Value{
public:
	//Value();
	Value(int);
};

//
//void init(Array<Value>* array){
//	Value zero(0);
//
//	fill(array,zero);//û��ʹ��Ĭ�Ϲ��캯��=T()
//	fill(array);//���ṩ�ڶ�����������ʹ�õڶ�������Ĭ�ϵĹ��캯��Value()������Value����û���ṩĬ�ϵ��޲ι��캯�����������
//
//}





