#include "../stdafx.h"

/*使用继承实现的桥接模式。
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

/*使用模板模式实现的桥接模式
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
		typedef ... const_iterator;//为常量vector而特定实现的迭代器类型
		const_iterator begin() const;//表示容器起始位置的迭代器
		const_iterator end() const;//表示容器结束位置的迭代器
	};

	template<typename T,...>
	class List{
	public:
		typedef ... const_iterator;//为常量List而特定实现的迭代器常量
		const_iterator begin() const;//表示容器起始位置的迭代器
		const_iterator end() const;//表示容器结束为指导额迭代器。
	};

	template<typename Iterator>
	Iterator max_element(Iterator beg, Iterator end){
		return NULL;
	}
	}*/