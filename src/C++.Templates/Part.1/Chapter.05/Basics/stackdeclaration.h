#include "../stdafx.h"

#ifndef STACK_DECLARATION_H
#define STACK_DECLARATION_H
#include <deque>

template<typename T>
class Stack{
private:
	std::deque<T> elements;
public:
	void push(T const&);
	T pop();
	T top() const;
	bool empty(){
		return elements.empty();
	}

	//成员模板
	template<typename T2>
	Stack<T>& operator=(Stack<T2> const& stack2);
};

template<typename T>
void Stack<T>::push(T const& element){
	elements.push_back(element);
}

template<typename T>
T Stack<T>::pop(){
	if (this->empty()){
		throw std::out_of_range("Stack<T>::pop():empty stack.");
	}
	T element = elements.back();
	elements.pop_back();
	return element;
}

template<typename T>
T Stack<T>::top() const{
	if (this->empty()){
		throw std::out_of_range("Stack<T>::top():empty stack.");
	}
	return elements.back();
}

template<typename T>
template<typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& stack2){
	if ((void*)this == (void*)(&stack2)){
		return *this;
	}
	
	Stack<T2> temp(stack2);
	this->elements.clear();
	while (!temp.empty()){
		elements.push_front(temp.top());//T2类型对象隐式转换为T类型
	}
	return *this;
}

#endif//STACK_DECLARATION_H