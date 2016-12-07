#include "../stdafx.h"

#ifndef ARRAY_H
#define ARRAY_H
template<typename T>
class Array{
private:
	T* data;
public:
	Array(Array<T> const&);
	Array<T>& operator=(Array<T> const&);

	vid exchange_with(Array<T>* b){
		T* temp = data;
		data = b->data;
		b->data = temp;
	}

	T& operator[](size_t k){
		return data[k];
	}
};

template<typename T>
inline void exchange(T* a,T* b){
	T temp(*a);
	*a = *b;
	*b = temp;
}

template<typename T>
void exchange(Array<T>* a,Array<T>* b){
	T* p = &a[0];
	T* q = &b[0];
	for (size_t k = a->size(); k != 0; k--){
		exchange(p++, q++);
	}
}

//∫Ø ˝ƒ£∞Â÷ÿ‘ÿ
template<typename T>
void quick_exchange(T* a,T* b){ 
	T temp(*a);
	*a = *b;
	*b = temp;
}

template<typename T>
void quick_exchange(Array<T>* a,Array<T>* b){
	a->exchange_with(b);
}

void test(Array<int>* p1,Array<int>* p2){
	int x, y;
	quick_exchange(&x,&y);
	quick_exchange(p1,p2);
}

struct S{
	int x;
} s1,s2;


void distinguish(Array<int> a1,Array<int> a2){
	int* p = &a1[0];
	int* q = &(s1.x);
	a1[0] = s1.x = 1;
	a2[0] = s2.x = 2;
	quick_exchange(&a1,&a2);	
}


#endif//ARRAY_H