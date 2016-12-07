#include "../stdafx.h"

#ifndef SARRAY_H
#define SARRAY_H

#include <stddef.h>
#include <cassert>

template<typename T>
class SArray{
public:
	//����һ�����г�ʼֵ��С������
	explicit SArray(size_t s):storage(new T[s]),storage_size(s){
		init();
	}

	//�������캯��
	SArray(SArray<T> const& orig):storage(new T[orig.size()]),storage_size(orig.size()){
		copy(orig);
	}

	//��������
	~SArray(){
		delete[] storage;
	}

	//��ֵ�����
	SArray<T>& operator=(SArray<T> const& orig){
		if (&orig != this){
			copy(orig);
		}
		return *this;
	}

	//�Լ������
	SArray<T> operator+=(SArray<T> const& b);
	//�Գ������
	SArray<T> operator*=(SArray<T> const& b);
	//�Ŵ���
	SArray<T> operator*=(T const& b);

	//���������С
	size_t size() const{
		return storage_size;
	}

	//��Գ������±������
	T operator[](size_t idx) const{
		return storage[idx];
	}

	T& operator[](size_t idx){
		return storage[idx];
	}

protected:
	//����ȱʡ���캯������ʼ��ֵ
	void init(){
		for (size_t idx = 0; idx < size();++idx){
			storage[idx] = T();
		}
	}

	//������һ�������ֵ
	void copy(SArray<T> const& orig){
		assert(size()==orig.size());
		for (size_t idx = 0; idx < size(); ++idx){
			storage[idx] = orig.storage[idx];
		}
	}

private:
	T* storage;//Ԫ�صĴ洢�ռ�
	size_t storage_size;//Ԫ�صĸ�����
};

#endif//SARRAY_H
