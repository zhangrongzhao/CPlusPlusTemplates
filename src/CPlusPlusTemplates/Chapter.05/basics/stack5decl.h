#include "../stdafx.h"
#include <deque>

//declaration
template<typename T>
class Stack{
private:
	std::deque<T> elements;
public:
	void push(T const&);
	T pop();
	T top() const;
	bool empty() const{
		return elements.empty();
	}

	template<typename T2>
	Stack<T>& operator=(Stack<T2> const&);//重写赋值运算符，目的：是两个不同类型栈可以相互赋值
};

//definition
template<typename T>
void Stack<T>::push(T const& element){
	elements.push_back(element);
}

template<typename T>
T Stack<T>::pop(){
	if (elements.empty()){
		throw std::out_of_range("Stack<>::pop(): stack is empty.");
	}
	T element = elements.back();
	elements.pop_back();
	return element;
}

template<typename T>
T Stack<T>::top() const{
	if (elements.empty()){
		throw std::out_of_range("Stack<>::pop():stack is empty.");
	}
	return elements.back();
}

template<typename T>
template<typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& op2){
	if ((void*)this == (void*)&op2){//赋值给自身吗
		return *this;
	}

	//op2由于const参数限制内部不能为该栈内元素进行修改，所以要从原栈获取一份完整副本。
	Stack<T2> temp(op2);//从原始栈中获取一份完整副本。
	elements.clear();//清除当前栈中的所有元素
	while (!temp.empty()){//将副本中的元素弹出，并压入当前栈中。
		elements.push_front(temp.pop());//类型检查
	}
	return *this;//返回当前栈对象。
}


