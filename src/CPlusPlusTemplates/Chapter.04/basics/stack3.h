#include "../stdafx.h"
#include <vector>
#include <stdexcept>

//declaration
//ȱʡģ��ʵ��
template<typename T,typename CONT=std::vector<T>>
class Stack{
private:
	CONT elements;//����Ԫ�ص�����
public:
	void push(T const&);
	T pop();
	T top() const;
	bool empty() const{
		return elements.empty();
	}
};

//defination
template<typename T,typename CONT>
void Stack<T, CONT>::push(T const& element){
	elements.push_back(element);
}

template<typename T,typename CONT>
T Stack<T, CONT>::pop(){
	if (elements.empty()){
		throw std::out_of_range("Stack<>::pop():empty Stack.");
	}

	T element = elements.back();
	elements.pop_back();
	return element;
}

template<typename T,typename CONT>
T Stack<T, CONT>::top() const{
	if (elements.empty()){
		throw std::out_of_range("Stack<>::top():empty stack.");
	}
	return elements.back();
}