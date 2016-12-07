#include "../stdafx.h"

#ifndef STACK_7_DECL_H
#define STACK_7_DECL_H

//模板参数本身就是模板
#include <stdexcept>
#include <deque>
template<typename T,template<typename ELEMENT,typename ALLOC=std::allocator<ELEMENT>>class CONTAINER=std::deque>
class Stack{
private:
	CONTAINER elements;
public:
	void push(T const&);
	T pop();
	T top() const;
	bool empty(){
		return elements.empty();
	}

	template<typename T2,template<typename ELEMENT,typename ALLOC> class CONTAINER2>
	Stack<T, CONTAINER>& operator=(Stack<T,CONTAINER2> const&);
};

template<typename T,template<typename ELEMENT,typename ALLOC> class CONTAINER>
void Stack<T, CONTAINER>::push(T const& element){
	elements.push_back(element);
}

template<typename T,template<typename ELEMENT,typename ALLOC> class CONTAINER>
T Stack<T, CONTAINER>::pop(){
	if (this->empty()){
		throw std::out_of_range("Stack<T,CONTAINER>::pop(): empty stack.");
	}
	T element = elements.back();
	elements.pop_back();
	return element;
}

template<typename T,template<typename ELEMENT,typename ALLOC> class CONTAINER>
T Stack<T, CONTAINER>::top() const{
	if (this->empty()){
		throw std::out_of_range("Stack<T,CONTAINER>::top(): empty stack.");
	}
	return elements.back();
}

template<typename T,template<typename ELEMENT,typename ALLOC> class CONTAINER>
template<typename T2,template<typename ELEMENT,typename ALLOC> class CONTAINER2>
Stack<T, CONTAINER> Stack<T, CONTAINER>::operator=(Stack<T2,CONTAINER2> const& stack2){
	if ((void*)this==(void*)(&stack2)){
		return *this;
	}
	Stack<T2, CONTAINER2> temp(stack2);
	elements.clear();
	while (!temp.empty()){
		elements.push_front(temp.pop());
	}
	return *this;
}

#endif//STACK_7_DECL_H