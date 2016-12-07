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
	Stack<T>& operator=(Stack<T2> const&);//��д��ֵ�������Ŀ�ģ���������ͬ����ջ�����໥��ֵ
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
	if ((void*)this == (void*)&op2){//��ֵ��������
		return *this;
	}

	//op2����const���������ڲ�����Ϊ��ջ��Ԫ�ؽ����޸ģ�����Ҫ��ԭջ��ȡһ������������
	Stack<T2> temp(op2);//��ԭʼջ�л�ȡһ������������
	elements.clear();//�����ǰջ�е�����Ԫ��
	while (!temp.empty()){//�������е�Ԫ�ص�������ѹ�뵱ǰջ�С�
		elements.push_front(temp.pop());//���ͼ��
	}
	return *this;//���ص�ǰջ����
}


