
#include "../stdafx.h"
#include <stdexcept>

//declaration
template<typename T,int MAXSIZE=100>
class Stack{
private:
	T elements[MAXSIZE];
	int numElements;//Ԫ�صĵ�ǰ����
public:
	Stack();
	void push(T const&);
	T pop();
	T top() const;
	bool empty() const{
		return numElements == 0;
	}
	bool full() const{
		return numElements == MAXSIZE;
	}
};

//defination
template<typename T,int MAXSIZE>
Stack<T, MAXSIZE>::Stack()
	:numElements(0){//��ʼʱջ����Ԫ��
	//�����κ����顣
}

template<typename T,int MAXSIZE>
void Stack<T, MAXSIZE>::push(T const& element){
	if (numElements >= MAXSIZE){
		throw std::out_of_range("Stack<>::push(): stack is full.");
	}
	elements[numElements] = element;//����Ԫ��
	numElements++;//����Ԫ�ظ���
}

template<typename T,int MAXSIZE>
T Stack<T, MAXSIZE>::pop(){
	if (numElements <= 0){
		throw std::out_of_range("Stack<>::top(): stack is empty.");
	}
	T element = elements[numElements-1];
	numElements--;
	return element;
}

template<typename T,int MAXSIZE>
T Stack<T, MAXSIZE>::top() const{
	if (numElements <= 0){
		throw std::out_of_range("Stack<>::top(): stack is empty.");
	}
	return elements[numElements-1];
}