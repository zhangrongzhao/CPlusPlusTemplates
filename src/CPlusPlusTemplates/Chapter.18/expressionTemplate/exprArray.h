#include "../stdafx.h"

#ifndef EXPRESSION_ARRAY
#define EXPRESSION_ARRAY
#include <stddef.h>
#include <cassert>
#include "sarray1.h"

template<typename T,typename Rep=SArray<T>>
class Array{
private:
	Rep expr_rep;//(����)���������
public:
	//�������г�ʼ��С������
	explicit Array(size_t s):expr_rep(s){
	   
	}

	//�����������ܵı�ʾ����������
	Array(Rep const& rb):expr_rep(rb){
	   
	}

	//�����ͬ���͵ĸ�ֵ�����
	Array& operator=(Array const& b){
		assert(size()==b.size());
		for (size_t idx = 0; idx < b.size();++idx){
			expr_rep[idx] = b[idx];
		}
		return *this;
	}

	//��Բ�ͬ���͵ĸ�ֵ�����
	template<typename T2,typename Rep2>
	Array& operator=(Array<T2,Rep2> const& b){
		assert(size()==b.size());
		for (size_t idx = 0; idx < size();idx++){
			expr_rep[idx] = b[idx];
		}
		return *this;
	}

	//size������ʾ���ݵĴ�С
	size_t size() const{
		return expr_rep.size();
	}

	//�ֱ���Գ����ͱ������������±꣩�����
	T operator[](size_t idx) const{
		assert(idx < size());
		return expr_rep[idx];
	}

	T& operator[](size_t idx){
		assert(idx<size());
		return expr_rep[idx];
	}

	//����������������ʾ�Ķ���
	Rep const& rep() const{
		return expr_rep;
	}

	Rep& rep(){
		return expr_rep;
	}
};

#endif//EXPRESSION_ARRAY

