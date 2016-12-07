#include "../stdafx.h"

#ifndef EXPR_OPS_1
#define EXPR_OPS_1

#include <stddef.h>
#include <cassert>
#include "exprops1a.h"

//������һ������class trait template.�Ӷ����ݲ�ͬ������жϾ������ԡ���ֵ���ķ�ʽ�������ԡ������á��ķ�ʽ�����õĶ�Ӧ�ġ����ʽģ��ڵ㡱

//��ʾ����������֮�͵Ķ����������
template<typename T,typename OP1,typename OP2>
class A_Add{
private:
	typename A_Traits<OP1>::ExprRef op1;//��һ��������
	typename A_Traits<OP2>::ExprRef op2;//�ڶ���������
public:
	//���캯�������ڳ�ʼ��ָ�������������
	A_Add(OP1 const& a,OP2 const& b):op1(a),op2(b){
	    
	}

	//����ֵ��ʱ������
	T operator[](size_t idx) const{
		return op1[idx] + op2[idx];
	}

	//size������������
	size_t size() const{
		assert(op1.size()==0||op2.size()==0||op1.size()==op2.size());
		return op1.size() != 0 ? op1.size() : op2.size();
	}
};

//������������֮���Ķ����������
template<typename T,typename OP1,typename OP2>
class A_Mult{
private:
	typename A_Traits<OP1>::ExprRef op1;//��һ��������
	typename A_Traits<OP2>::ExprRef op2;//�ڶ���������
public:
	//���캯�������ڳ�ʼ������ָ�������������
	A_Mult(OP1 const& a, OP2 const& b) :op1(a), op2(b){
	
	}

	//����ֵ��ʱ������
	T operator[](size_t idx) const{
		return op1[idx] * op2[idx];
	}

	//size��ʾ��������
	size_t size() const{
		assert(op1.size()==0||op2.size()==0||op1.size()==op2.size());
		return op1.size() != 0 ? op1.size() : op2.size();
	}
};


#endif//EXPR_OPS_1