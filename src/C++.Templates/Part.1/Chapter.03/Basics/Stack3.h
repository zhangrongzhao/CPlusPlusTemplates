#include "../stdafx.h"

#ifndef STACK_3_H
#define STACK_3_H

//缺省默认参数
#include <vector>
#include <deque>
#include <iostream>
template<typename T,typename CONTAINERT=std::vector<T>>
class Stack{
private:
	CONTAINERT elements;
public:
	void push(T const&);
	T pop();
	T top() const;
	bool empty() const{
		return elements.empty();
	}
};

template<typename T, typename CONTAINERT>
void Stack<T, CONTAINERT>::push(T const& element){
	elements.push_back(element);
}

template<typename T, typename CONTAINERT>
T Stack<T, CONTAINERT>::pop(){
	if (this->empty()){
		throw std::out_of_range("Stack<T,CONT>::pop: empty stack.");
	}
	T element = elements.back();
	elements.pop_back();
	return element;
}

template<typename T, typename CONTAINERT>
T Stack<T, CONTAINERT>::top() const{
	if (this->empty()){
		throw std::out_of_range("Stack<T,CONT>::top: empty stack.");
	}
	return elements.back();
}

int test_Stack_3(){
	try{
		Stack<int> nStack;
		Stack<double, std::deque<double>> doubleStack;

		nStack.push(7);
		nStack.top();
		nStack.pop();

		doubleStack.push(42.42);
		doubleStack.pop();
		doubleStack.pop();
	}
	catch(std::exception const & ex){
		std::cout << "Exception:" << ex.what() << std::endl;
		return EXIT_FAILURE;
	}
}
#endif//STACK_3_H
