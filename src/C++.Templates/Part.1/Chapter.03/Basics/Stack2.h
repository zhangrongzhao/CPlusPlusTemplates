#include "../stdafx.h"

#ifndef STACK_2_H
#define STACK_2_H
#include <deque>
#include "Stack1.h"
//Stack<T>基本模板的全局特化
template<>
class Stack<std::string>{
private:
	std::deque<std::string> elements;
public:
	Stack(){ }
	Stack(Stack<std::string> const&);
	Stack<std::string> operator=(Stack<std::string> const&);
	template<typename T2>
	Stack<std::string> operator=(Stack<T2> const&);

	void push(std::string const&);
	std::string pop();
	std::string top() const;
	bool empty() const{
		return elements.empty();
	}
};

//实现成员函数
Stack<std::string>::Stack(){}
Stack<std::string>::Stack(Stack<std::string> const& stack){
	if ((void*)this==(void*)(&stack)){
		return;
	}
	elements.clear();
	Stack<std::string> temp(stack);
	while (!temp.empty()){
		this->push(temp.pop());
	}
}
Stack<std::string> Stack<std::string>::operator=(Stack<std::string> const& stack){
	if ((void*)this==(void*)(&stack)){
		return *this;
	}

	elements.clear();
	Stack<std::string> temp(stack);
	while (!temp.empty()){
		this->push(temp.pop());
	}
	return *this;
}

template<typename T2>
Stack<std::string> Stack<std::string>::operator=(Stack<T2> const& stack){
	if ((void*)this==(void*)(&stack)){
		return *this;
	}
	elements.clear();
	Stack<T2> temp(stack);
	while (!temp.empty()){
		this->push(temp.pop());
	}
	return *this;
}

void Stack<std::string>::push(std::string const& element){
	elements.push_back(element);
}

std::string Stack<std::string>::pop(){
	if (this->empty()){
		throw std::out_of_range("Stack<std::string>::pop: empty stack.");
	}
	std::string element = elements.back();
	elements.pop_back();
	return element;
}

std::string Stack<std::string>::top() const{
	if (this->empty()){
		throw std::out_of_range("Stack<std::string>::top: empty stack.");
	}
	return elements.back();
}
#endif//STACK_2_H