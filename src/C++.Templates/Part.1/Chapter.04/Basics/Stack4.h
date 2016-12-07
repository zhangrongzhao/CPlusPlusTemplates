#include "../stdafx.h"

#ifndef STACK_4_H
#define STACK_4_H
#include <stdexcept>

//非类型模板参数
template<typename T,int MAXSIZE=100>
class Stack{
private:
	T elements[MAXSIZE];
	int currentPos;
public:
	Stack();

	void push(T const& element);
	T pop();
	T top() const;
	bool empty() const{
		return currentPos < 0;
	}
	bool full() const{
		return ++currentPos >= MAXSIZE;
	}
};

template<typename T,int MAXSIZE>
void Stack<T, MAXSIZE>::Stack() :currentPos(0){ }

template<typename T,int MAXSIZE>
void Stack<T, MAXSIZE>::push(T const& element){
	if (this->full()){
		throw std::out_of_range("Stack<T,MAXSIZE>::push(): full stack.");
	}
	elements[currentPos] = element;
	currentPos++;
}

template<typename T,int MAXSIZE>
T Stack<T, MAXSIZE>::pop() {
	if (this->empty()){
		throw std::out_of_range("Stack<T,MAXSIZE>::pop(): empty stack.");
	}
	elements[currentPos] = NULL;
	currentPos--;
}

template<typename T,int MAXSIZE>
T Stack<T, MAXSIZE>::top() const{
	if (this->empty()){
		throw std::out_of_range("Stack<T,MAXSIZE>::top(): empty stack.");
	}
	return elements[currentPos];
}


#endif//STACK_4_H