#include "../stdafx.h"

/*On-Demand ʵ����
template<typename T>
class C;//����ֻ������

C<int>* p = 0;//��ȷ������ҪC<int>�Ķ���

template<typename T>
class C{
public:
	void f();//��Ա����
};//��ģ�嶨�����

void g(C<int>& c){//ֻ������ģ������
	c.f();//��ҪC<int>::f�Ķ���
}

C<int>* p = new C<int>;
*/

/*C++�����ؽ���Ҫ�������ѡ�����Ĳ�����class���ͣ���ô����������Ӧ����ͱ����ǿɼ��ġ�*/
template<typename T>
class C{
public :
	C(int);//���е������Ĺ��캯��
};

void candidate(C<double> const&);//(1)
void candidate(int){ }

void call(){
	candidate(42);//��ȷƥ��Ҫ����(������)��ʽת������õ�ƥ�䡣
}

