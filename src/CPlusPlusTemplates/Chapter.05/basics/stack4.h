
#include "../stdafx.h"
#include <stdexcept>

//declaration
template<typename T,int MAXSIZE=100>
class Stack{
private:
	T elements[MAXSIZE];
	int numElements;//元素的当前个数
public:
	Stack();
	void push(T const&);
	T pop();
	T top() const;
	bool empty() const{
		return numElements == 0;
	}
	bool full() const{
		return numElements == MAXSIZE;
	}
};

//defination
template<typename T,int MAXSIZE>
Stack<T, MAXSIZE>::Stack()
	:numElements(0){//初始时栈不含元素
	//不做任何事情。
}

template<typename T,int MAXSIZE>
void Stack<T, MAXSIZE>::push(T const& element){
	if (numElements >= MAXSIZE){
		throw std::out_of_range("Stack<>::push(): stack is full.");
	}
	elements[numElements] = element;//附加元素
	numElements++;//增加元素个数
}

template<typename T,int MAXSIZE>
T Stack<T, MAXSIZE>::pop(){
	if (numElements <= 0){
		throw std::out_of_range("Stack<>::top(): stack is empty.");
	}
	T element = elements[numElements-1];
	numElements--;
	return element;
}

template<typename T,int MAXSIZE>
T Stack<T, MAXSIZE>::top() const{
	if (numElements <= 0){
		throw std::out_of_range("Stack<>::top(): stack is empty.");
	}
	return elements[numElements-1];
}