#include "../stdafx.h"
/**/
template<typename T>
class Array{
private:
	T* data;
public:
	Array(Array const&);
	Array<T>& operator=(Array<T> const&);

	void exchange_with(Array<T>* b){
		T* temp = data;
		data = b->data;
		b->data = temp;
	}

	T& operator[] (size_t k){
		return data[k];
	}
};

template<typename T>
inline void exchange(T* a,T* b){
	T temp(*a);//如果T类型占据大容量内存，这个将是一个繁重的copy操作。
	*a = *b;
	*b = temp;
}

template<typename T>
void exchange(Array<T>* a,Array<T>* b){
	T* p = &(*a)[0];
	T* q = &(*b)[0];
	for (size_t k = a->size(); k!= 0;K--){
		exchange(p++,q++);
	}
}


/*重载集合*/
template<typename T>
inline void quick_exchange(T* a,T* b){
	T temp(*a);
	*a = *b;
	*b = temp;
}

template<typename T>
inline void quick_exchange(Array<T>* a,Array<T>* b){
	a->exchange_with(b);
}

void demo(Array<int>* p1,Array<int>* p2){
	int x, y;
	quick_exchange(&x,&y);//(1)
	quick_exchange(p1,p2);//(2)
}

/*边缘效应*/
struct  S{
	int x;
} s1,s2;

void distinguish(Array<int> a1,Array<int> a2){
	int* p = &a1[0];
	int* q = &s1.x;

	a1[0] = s1.x = 1;
	a2[0] = s2.x = 2;
	quick_exchange(&a1,&a2);//*p==1
	quick_exchange(&s1,&s2);//*q==2
}

