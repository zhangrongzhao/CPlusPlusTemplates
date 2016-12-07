#include "../stdafx.h"

#ifndef INCLUSION_MODEL_DECLARATION_H
#define INCLUSION_MODEL_DECLARATION_H
#include <vector>
//类模板
template<typename T>
class Stack{
private:
	std::vector<T> elements;
public:
	//构造函数
	Stack();
	//复制构造函数(相同类型赋值构造)
	Stack(Stack<T> const& stack);

	//赋值运算符,相同类型的赋值运算符
	Stack<T> operator=(Stack<T> const& stack);

	//赋值运算符，不同类型的赋值运算符
	template<typename T2>
	Stack<T> operator=(Stack<T2> const& stack);

	void push(T const& element);
	T pop();
	T top() const;
	bool empty() const{
		return elements.empty();
	}
};

#endif//INCLUSION_MODEL_DECLARATION_H