#include "../stdafx.h"

#ifndef STACK_6_DECL_H
#define STACK_6_DECL_H
#include <deque>
template<typename T,typename CONTAINER=std::deque<T>>
class Stack{
private:
	CONTAINER elements;
public:
	void push(T const&);
	T pop();
	T top() const;
	bool empty() const{
		return elements.empty();
	}

	template<typename T2,typename CONTAINER2>
	Stack<T, CONTAINER> operator=(Stack<T2,CONTAINER2> const&);
};

template<typename T,typename CONTAINER>
void Stack<T, CONTAINER>::push(T const& element){
	elements.push_back(element);
}

template<typename T,typename CONTAINER>
T Stack<T, CONTAINER>::pop(){
	if (this->empty()){
		throw std::out_of_range("Stack<T,CONTAINER>::pop(): empty stack.");
	}
	T element = elements.back();
	elements.pop_back();
	return element;
}

template<typename T,typename CONTAINER>
T Stack<T, CONTAINER>::top() const{
	if (this->empty()){
		throw std::out_of_range("Stack<T,CONTAINER>::top(): empty stack.");
	}
	return elements.back();
}

template<typename T,typename CONTAINER>
template<typename T2,typename CONTAINER2>
Stack<T, CONTAINER> Stack<T, CONTAINER>::operator=(Stack<T2,CONTAINER2> const& stack2){
	if ((void*)this == (void*)(&stack2)){
		return *this;
	}

	Stack<T2, CONTAINER2> temp(stack2);
	while (!temp.empty()){
		elements.push_front(temp.pop());
	}
	return *this;
}

#endif//STACK_6_DECL_H