#include "../stdafx.h"

#ifndef S_ARRAY_H
#define S_ARRAY_H
#include <cassert>
template<typename T>
class SArray{
private:
	T* storage;//元素的存储空间。
	size_t storage_size;//元素的个数。
protected:
	void init(){
		for (size_t idx = 0; idx < storage_size; idx++){
			storage[idx] = T();
		}
	}
	void copy(SArray<T> const& orig){
		assert(size()==orig.size());
		for (size_t idx = 0; idx < size();idx++){
			storage[idx] = orig.storage[idx];
		}
	}
public:
	explicit SArray(size_t s) :storage(new T[s]), storage_size(s){ }
	SArray(SArray<T> const& orig):storage(new T[orig.size()]),storage_size(orig.size()){
		copy(orig);
	}
	~SArray(){ delete[] storage; }

	SArray<T>& operator=(SArray<T> const& orig){
		if (&orig != this){
			copy(orig);
		}
		return *this;
	}
	SArray<T>& SArray<T>::operator+=(SArray<T> const& b);
	SArray<T>& SArray<T>::operator*=(SArray<T> const& b);
	SArray<T>& SArray<T>::operator*=(T const& scalar);

	T operator[] (size_t idx) const{
		return storage[idx];
	}

	T& operator[] (size_t idx){
		return storage[idx];
	}

	size_t size() const{
		return storage_size;
	}
};
#endif//S_ARRAY_H