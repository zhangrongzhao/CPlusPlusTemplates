#ifndef STACK_HPP
#define STACK_HPP

#include "../stdafx.h"
#include <deque>
#include <stdexcept>
#include <memory>

//declaration
template<typename T,
	     template<typename ELEM,typename ALLOC=std::allocator<ELEM>>
         class CONT = std::deque//声明一个类模板。
        >
class Stack{
private:
	CONT<T> elements;
public:
	void push(T const&);
	T pop();
	T top() const;
	bool empty() const {
		return elements.empty();
	}

	template<typename T2,
		     template<typename ELEM2,typename ALLOC2=std::allocator>
	         class CONT2 = std::deque
	         > 
	Stack<T, CONT>& operator=(Stack<T2,CONT2> const& op2);
};

//definition
template<typename T, template<typename,typename> class CONT>
void Stack<T, CONT>::push(T const& element){
	elements.push_back(element);
}

template<typename T, template<typename,typename> class CONT>
T Stack<T, CONT>::pop(){
	if (elements.empty()){
		throw std::out_of_range("Stack<>::pop():Stack is empty");
	}
	T element = elements.back();
	elements.pop_back();
	return element;
}

template<typename T, template<typename,typename> class CONT>
T Stack<T, CONT>::top() const{
	if (elements.empty()){
		throw std::out_of_range("Stack<>::top():Stack is empty");
	}
	return elements.back();
}

template<typename T,
	     template<typename ELEM,typename ALLOC>
         class CONT
        >
template<typename T2,
         template<typename ELEM2,typename ALLOC2>
		 class CONT2
        >
Stack<T, CONT>& Stack<T, CONT>::operator=(Stack<T2,CONT2> const& op2){
			 if ((void*)this == (void*)&op2){
				 return *this;
			 }
			 Stack<T2, CONT2> temp(op2);
			 elements.clear();
			 while (!temp.empty()){
				 elements.push_front(temp.pop());
			 }
			 return *this;
}

#endif //STACK_HPP

