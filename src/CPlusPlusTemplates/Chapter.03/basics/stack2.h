#include "../stdafx.h"
#include <deque>
#include <string>
#include <stdexcept>

#include "stack1.h"

//ģ���ػ����ػ���ʵ�ֺͻ�����ģ���ʵ����ȫ��ͬ��
//declaration
template<>
class Stack <std::string> {
private:
	std::deque<std::string> elements;//double-ended queue.˫�˶���
public:
	void push(std::string const&);
	std::string pop();
	std::string top() const;
	bool empty() const{
		return elements.empty();
	}
};

//defination
void Stack<std::string>::push(std::string const& element){
	elements.push_back(element);
}

std::string Stack<std::string>::pop(){
	if (elements.empty()){
		throw std::out_of_range("Stack<std::string>::pop():empty stack.");
	}
	std::string element = elements.back();
	elements.pop_back();
	return element;
}

std::string Stack<std::string>::top() const{
	if (elements.empty()){
		throw std::out_of_range("Stack<std::string>::top():empty stack.");
	}
	return elements.back();
}


