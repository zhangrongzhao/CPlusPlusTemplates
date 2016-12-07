#include "../stdafx.h"

#ifndef INCLUSION_MODEL_DEFINITION_H
#define INCLUSION_MODEL_DEFINITION_H
#include "declaration.h"

template<typename T>
Stack<T>::Stack(){ }

template<typename T>
Stack<T>::Stack(Stack<T> const& stack){
	//�����ж��Ƿ��Լ���ֵ���Լ�
	if ((void*)this == (void*)(&stack)){
		return;
	}

	//�������Ԫ��
	elements.clear();
	Stack<T> temp(stack);
	//����Ԫ��
	while (!temp.empty()){
		this->push(temp.pop());
	}
	return;
}

template<typename T>
Stack<T> Stack<T>::operator=(Stack<T> const& stack){
	if ((void*)this == (void*)(&stack)){
		return *this;
	}
	elements.clear();
	Stack<T> temp(stack);
	while (!temp.empty()){
		this->push(temp.pop());
	}
	return *this;
}

template<typename T>
template<typename T2>
Stack<T> Stack<T>::operator=(Stack<T2> const& stack){
	this->elements.clear();
	Stack<T2> temp(stack);
	while (!temp.empty()){
		this->push(temp.pop());
	}
	return *this;
}

template<typename T>
void Stack<T>::push(T const& element){
	elements.push_back(element);//��element���ӵ�ĩβ��
}

template<typename T>
T Stack<T>::pop(){
	if (elements.empty()){
		throw std::out_of_range("Stack<T>::pop(): stack is empty.");
	}
	T element = elements.back();//�ȱ���ĩ��Ԫ�صĿ���
	elements.pop_back();//ɾ��ĩ��Ԫ��
	return element;//���ر����ĩ��Ԫ��
}

template<typename T>
T Stack<T>::top() const{
	if (elements.empty()){
		throw std::out_of_range("Stack<T>::top(): stack is empty.");
	}
	return elements.back();//����ĩ��Ԫ�صĿ�����
}
#endif//INCLUSION_MODEL_DEFINITION_H