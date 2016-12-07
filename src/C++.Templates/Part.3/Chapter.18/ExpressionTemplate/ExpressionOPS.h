#include "../stdafx.h"

#ifndef EXPRESSIONS_OPS_H
#define EXPRESSIONS_OPS_H
#include <cassert>
#include "A_Traits.h"
//ʹ����ʱ������6000��read��4000��wirte��������ܵ��¡�
//�Ľ����飺����ʹ����ʱ������������ֵ�����ʱ��������ʽ��ֵ��֮ǰ��ת��Ϊ���ʽģ�塣

//x=1.2*x+x*yת��Ϊ���ʽģ��
//������Ŀ����ʽģ��=>A_Add<A_Multi<A_Scalar<double>,Array<double> >,
//                          A_Multi<Array<double>,Array<double>>
//                         >;


//������ֵ�������
template<typename T,typename OP1,typename OP2>
class A_Add{
private:
	 typename A_Traits<OP1>::ExprRef op1;//��һ��������
	 typename A_Traits<OP2>::ExprRef op2;//�ڶ���������
public:
	A_Add(OP1 const& a,OP1 const& b):op1(a),op2(b){ }

	//����ֵ��ʱ������
	T operator[](size_t idx) const{
		return op1[idx] + op2[idx];
	}

	//size�������������
	size_t size() const(){
		assert(op1.size()==0||op2.size()==0||op1.size()==op2.size());
		return op1.size() != 0 ? op1.size() : op2.size();
	}
};

//������ֵ�������
template<typename T,typename OP1,typename OP2>
class A_Multi{
private:
	typename A_Traits<OP1>::ExprRef op1;
	typename A_Traits<OP2>::ExprRef op2;
public:
	//���캯����ָ������������á�
	A_Multi(OP1 const& a,OP2 const& b) :op1(a), op2(b){	}

	//����ֵ��ʱ�����˻�
	T operator[](size_t idx){
		return op1[idx] * op2[idx];
	}

	//�����������
	size_t size() const{
		assert(op1.size()==0||op2.size()==0||op1.size()==op2.size());
		return op1.size() != 0 ? op1.size() : op2.size();
	}
};

template<typename T,typename A1,typename A2>
class A_Subscript{
private:
	A1 const& a1;
	A2 const& a2;
public:
	A_Subscript(A1 const& a,A2 const& b) :a1(a), a2(b){ }

	T operator[](size_t idx) const{
		return a1[a2[idx]];
	}

	T& operator[](size_t idx){
		return a1[a2[idx]];
	}

	size_t size() const{
		return a2.size();
	}
};

#endif//EXPRESSIONS_OPS_H