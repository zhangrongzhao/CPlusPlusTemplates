#include "../stdafx.h"

#ifndef ACCUM_H
#define ACCUM_H
#include <iterator>
template<typename Iter>
inline typename std::iterator_traits<Iter>::value_type accum(Iter start,Iter end){
	typedef typename std::iterator_traits<Iter>::value_type VT;
	VT total = VT();//假设VT()生成一个0的值
	while (start!=end){
		total += *start;
		++start;
	}
	return total;
}

namespace std{
    template<typename T>
	struct iterator_traits<T*>{
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef ptrdiff_t difference_type;
		typedef random_access_iterator_tag iterator_category;
	};
}

#endif//ACCUM_H
