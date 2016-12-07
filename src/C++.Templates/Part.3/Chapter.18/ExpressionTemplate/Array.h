#include "../stdafx.h"

#ifndef ARRAY_OP_H
#define ARRAY_OP_H
#include "SArray.h"

//��ֵ���������
template<typename T,typename Rep=SArray<T>>
class Array{
private:
	Rep expr_rep;//������������ݡ�
public:
	//��ʽ�������г�ʼ��С������
	explicit Array(size_t size) :expr_reg(size){ }

	//�����������ʹ�������
	Array(Rep const& rb):expr_rep(rb){ }

	//ͬ���͵ĸ�ֵ�����
	Array<T>& operator=(Array<T> const& b){
		assert(size()==b.size());
		for (size_t idx = 0; idx < size();idx++){
			expr_rep[idx] = b[idx];
		}
		return *this;
	}

	//��ͬ���͵ĸ�ֵ�����
	template<typename T2,typename Rep2>
	Array<T>& operator=(Array<T2,Rep2> const& b){
		assert(size()==b.size());
		for (size_t idx = 0; idx < size();idx++){
			expr_rep[idx] = b[idx];
		}
		return *this;
	}


	T operator[](size_t idx){
		assert(idx<b.size());
		return expr_rep[idx];
	}

	T& operator[](size_t idx){
		assert(idx<size());
		return expr_rep[idx];
	}

	size_t size() const{
		return expr_rep.size();
	}

	Rep const& rep() const{
		return expr_rep;
	}

	Rep& rep(){
		return expr_rep;
	}
};


#endif//ARRAY_OP_H