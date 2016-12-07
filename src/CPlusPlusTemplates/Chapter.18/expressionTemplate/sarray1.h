#include "../stdafx.h"

#ifndef SARRAY_H
#define SARRAY_H

#include <stddef.h>
#include <cassert>

template<typename T>
class SArray{
public:
	//创建一个具有初始值大小的数组
	explicit SArray(size_t s):storage(new T[s]),storage_size(s){
		init();
	}

	//拷贝构造函数
	SArray(SArray<T> const& orig):storage(new T[orig.size()]),storage_size(orig.size()){
		copy(orig);
	}

	//析构函数
	~SArray(){
		delete[] storage;
	}

	//赋值运算符
	SArray<T>& operator=(SArray<T> const& orig){
		if (&orig != this){
			copy(orig);
		}
		return *this;
	}

	//自加运算符
	SArray<T> operator+=(SArray<T> const& b);
	//自乘运算符
	SArray<T> operator*=(SArray<T> const& b);
	//放大倍数
	SArray<T> operator*=(T const& b);

	//返回数组大小
	size_t size() const{
		return storage_size;
	}

	//针对常数和下标运算符
	T operator[](size_t idx) const{
		return storage[idx];
	}

	T& operator[](size_t idx){
		return storage[idx];
	}

protected:
	//运用缺省构造函数来初始化值
	void init(){
		for (size_t idx = 0; idx < size();++idx){
			storage[idx] = T();
		}
	}

	//拷贝另一个数组的值
	void copy(SArray<T> const& orig){
		assert(size()==orig.size());
		for (size_t idx = 0; idx < size(); ++idx){
			storage[idx] = orig.storage[idx];
		}
	}

private:
	T* storage;//元素的存储空间
	size_t storage_size;//元素的个数。
};

#endif//SARRAY_H
