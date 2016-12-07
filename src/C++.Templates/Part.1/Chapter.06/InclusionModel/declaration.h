#include "../stdafx.h"

#ifndef INCLUSION_MODEL_DECLARATION_H
#define INCLUSION_MODEL_DECLARATION_H
#include <vector>
//��ģ��
template<typename T>
class Stack{
private:
	std::vector<T> elements;
public:
	//���캯��
	Stack();
	//���ƹ��캯��(��ͬ���͸�ֵ����)
	Stack(Stack<T> const& stack);

	//��ֵ�����,��ͬ���͵ĸ�ֵ�����
	Stack<T> operator=(Stack<T> const& stack);

	//��ֵ���������ͬ���͵ĸ�ֵ�����
	template<typename T2>
	Stack<T> operator=(Stack<T2> const& stack);

	void push(T const& element);
	T pop();
	T top() const;
	bool empty() const{
		return elements.empty();
	}
};

#endif//INCLUSION_MODEL_DECLARATION_H