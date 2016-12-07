#include "../stdafx.h"
#include <deque>
#ifndef STACK_H
#define STACK_H
template<typename T,
	     template<typename ELEM,typename ALLOC=std::allocator<ELEM>>
         class CONT=std::deque
        >
class Stack{
private:
	CONT<T> elements;
public:
	Stack();
	void push(T const&);
	T pop();
	T top() const;
	bool empty() const{
		return elements.empty();
	};

	template<typename T2,
		     template<typename ELEM2,typename ALLOC=std::allocator<ELEM2>>
	         class CONT2>
	Stack<T, CONT>& operator=(Stack<T2,CONT2> const&);
};
#endif//STACK_H
