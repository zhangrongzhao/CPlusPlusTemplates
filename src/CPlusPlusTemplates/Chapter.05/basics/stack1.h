#include "../stdafx.h"
#include <vector>
#include <stdexcept>

//declaration 模板声明
template<typename T>
class Stack{
private:
	std::vector<T> elements;
public:
	//Stack();//构造函数
	//Stack(Stack<T> const&);//拷贝构造函数
	//Stack<T>& operator=(Stack<T> const&);//赋值运算符

	void push(T const&);
	T pop();
	T top() const;
	bool empty() const{
		return elements.empty();
	}
};

//defination 模板定义
//template<typename T>
//Stack<T>::Stack(){}
//
//template<typename T>
//Stack<T>::Stack(Stack<T> const& stack1) {}
//
//template<typename T>
//Stack<T>& Stack<T>::operator=(Stack<T> const& stack1){}

template<typename T>
void Stack<T>::push(T const& element){
	elements.push_back(element);
}

template<typename T>
T Stack<T>::pop(){
	if (elements.empty()){
		throw std::out_of_range("Stack<>::pop(): empty stack.");
	}
	T element = elements.back();
	elements.pop_back();//只删除元素，不返回该元素
	return element;
}


template<typename T>
T Stack<T>::top() const{
	if (elements.empty()){
		throw std::out_of_range("Stack<>::top(): empty stack.");
	}
	return elements.back();
}


