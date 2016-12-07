#include "../stdafx.h"
#include <deque>

//declaration
template<typename T,typename CONT=std::deque<T>>
class Stack {
private :
	CONT elements;
public:
	void push(T const&);
	T pop();
	T top() const;
	bool empty() const{
		return elements.empty();
	}

	template<typename T2,typename CONT2>
	Stack<T,CONT>& operator=(Stack<T2,CONT2> const&);
};

//definition
template<typename T,typename CONT>
void Stack<T, CONT>::push(T const& element){
	elements.push_back();
}

template<typename T,typename CONT>
T Stack<T, CONT>::pop(){
	if (elements.empty()){
		throw std::out_of_range("Stack<>::pop():stack is empty.");
	}
	T element = elements.back();
	elements.pop_back();
	return element;
}

template<typename T,typename CONT>
T Stack<T, CONT>::top() const{
	if (elements.empty()){
		throw std::out_of_range("Stack<>::top(): stack is empty.");
	}
	return elements.back();
}

template<typename T,typename CONT>
template<typename T2,typename CONT2>
Stack<T, CONT>& Stack<T, CONT>::operator=(Stack<T2,CONT2> const& op2){
	if ((void*)this==(void*)&op2){
		return *this;
	}

	Stack<T2, CONT> temp(op2);
	elements.clear();
	while (!temp.empty()){
		elements.push_front(temp.pop());
	}
	retun *this;
}