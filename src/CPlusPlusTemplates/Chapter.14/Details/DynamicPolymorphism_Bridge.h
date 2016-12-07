#include "../stdafx.h"

/*ʹ�ü̳�ʵ�ֵ��Ž�ģʽ��
class Implementation{
public:
	virtual void operationA() = 0;
	virtual void operationB() = 0;
	virtual void operationC() = 0;
};

class ImplementionA :public Implementation{
public:
	virtual void operationA(){};
	virtual void operationB(){};
	virtual void operationC(){};
};

class ImplementationB :public Implementation{
public:
	virtual void operationA(){};
	virtual void operationB(){};
	virtual void operationC(){};
};

class Interface{
private:
	Implementation* body;
public:
	void operationA(){
		body->operationA();
	}
	void operationB(){
		body->operationB();
		body->operationC();
	}
};
*/

/*ʹ��ģ��ģʽʵ�ֵ��Ž�ģʽ
class ImplementationA{
public:
	void operationA(){}
	void operationB(){}
	void operationC(){}
};

class ImplementationB{
public:
	void operationA(){}
	void operationB(){}
	void operationC(){}
};


template<typename Impl>
class Interface{
private:
	Impl body;
public:
	void operationA(){
		body.operationA();
	}
	void operationB(){
		body.operationB();
		body.operationC();
	}
};

void test_Bridge(){
	ImplementationA a;
	ImplementationB b;

	Interface<ImplementationA> oInterface1;
	oInterface1.operationA();
	oInterface1.operationB();

	Interface<ImplementationB> oInterface2;
	oInterface2.operationA();
	oInterface2.operationB();
}
*/

/*


namespace standard{
	template<typename T,...>
	class vector{
	public:
		typedef ... const_iterator;//Ϊ����vector���ض�ʵ�ֵĵ���������
		const_iterator begin() const;//��ʾ������ʼλ�õĵ�����
		const_iterator end() const;//��ʾ��������λ�õĵ�����
	};

	template<typename T,...>
	class List{
	public:
		typedef ... const_iterator;//Ϊ����List���ض�ʵ�ֵĵ���������
		const_iterator begin() const;//��ʾ������ʼλ�õĵ�����
		const_iterator end() const;//��ʾ��������Ϊָ�����������
	};

	template<typename Iterator>
	Iterator max_element(Iterator beg, Iterator end){
		return NULL;
	}
	}*/