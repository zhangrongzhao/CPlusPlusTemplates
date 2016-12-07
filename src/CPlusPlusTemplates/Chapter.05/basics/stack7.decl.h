#include "../stdafx.h"
#include <deque>

//declaration
template<typename T,
         template<typename ELEM> 
         class CONT=std::deque//声明一个类模板。
        >
class Stack{
private:
	CONT<T> elements;
public:
	void push(T const&);
	T pop();
	T top() const;
	bool empty() const {
		return element.empty();
	}
};

//definition
template<typename T,template<typename> class CONT>
void Stack<T, CONT>::push(T const& element){
	elements.push_back(element);
}

template<typename T,template<typename> class CONT>
T Stack<T, CONT>::pop(){
	if (elements.empty()){
		throw std::out_of_range("Stack<>::pop():Stack is empty");
	}
	T element = elements.back();
	elements.pop_back();
	return element;
}

template<typename T,template<typename> class CONT>
T Stack<T, CONT>::top() const(){
	if (elements.empty()){
		throw std::out_of_range("Stack<>::top():Stack is empty");
	}
	return elements.back();
}
 
