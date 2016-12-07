#include "../stdafx.h"
#include "stackDec.h"
#include <stdexcept>
#include <memory>
#include <deque>
//definition

template<typename T,
         template<typename ELEM,typename ALLOC>
         class CONT
>
Stack<T, CONT>::Stack(){}

template<typename T,
	     template<typename ELEM,typename ALLOC>
         class CONT>
void Stack<T, CONT>::push(T const& element){
			 elements.push_back(element);
}

template<typename T,
         template<typename ELEM,typename ALLOC> 
         class CONT>
T Stack<T, CONT>::pop(){
			 if (elements.empty()){
				 throw std::out_of_range("Stack<>::pop():Stack is empty.");
			 }
			 T element = elements.back();
			 elements.pop_back();
			 return element;
}

template<typename T,
         template<typename ELEM,typename ALLOC>
         class CONT
>
T Stack<T, CONT>::top() const{
			 if (elements.empty()){
				 throw std::out_of_range("Stack<>::top():Stack is empty.");
			 }
			 return elements.back();
}


template<typename T,
         template<typename ELEM,typename ALLOC>
         class CONT
>
template<typename T2,
         template<typename ELEM2,typename ALLOC>
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



		
