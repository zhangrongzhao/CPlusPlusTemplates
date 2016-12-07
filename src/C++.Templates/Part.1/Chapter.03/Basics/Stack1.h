#include "../stdafx.h"

#ifndef STACK_1_H
#define STACK_1_H
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

template<typename T>
Stack<T>::Stack(){ }

template<typename T>
Stack<T>::Stack(Stack<T> const& stack){
    //首先判断是否自己赋值给自己
	if ((void*)this == (void*)(&stack)){
		return;
	}

	//清空自身元素
	elements.clear();
	Stack<T> temp(stack);
	//复制元素
	while (!temp.empty()){
		this->push(temp.pop());
	}
	return;
}

template<typename T>
Stack<T> Stack<T>::operator=(Stack<T> const& stack){
	if ((void*)this == (void*)(&stack)){
		return *this;
	}
	elements.clear();
	Stack<T> temp(stack);
	while (!temp.empty()){
		this->push(temp.pop());
	}
	return *this;
}

template<typename T>
template<typename T2>
Stack<T> Stack<T>::operator=(Stack<T2> const& stack){
	this->elements.clear();
	Stack<T2> temp(stack);
	while (!temp.empty()){
		this->push(temp.pop());
	}
	return *this;
}

template<typename T>
void Stack<T>::push(T const& element){
	elements.push_back(element);//把element附加到末尾。
}

template<typename T>
T Stack<T>::pop(){
	if (elements.empty()){
		throw std::out_of_range("Stack<T>::pop(): stack is empty.");
	}
	T element = elements.back();//先保存末端元素的拷贝
	elements.pop_back();//删除末端元素
	return element;//返回保存的末端元素
}

template<typename T>
T Stack<T>::top() const{
	if (elements.empty()){
		throw std::out_of_range("Stack<T>::top(): stack is empty.");
	}
	return elements.back();//返回末端元素的拷贝。
}
#endif//STACK_1_H