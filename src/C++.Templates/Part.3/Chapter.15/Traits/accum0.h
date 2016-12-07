#include "../stdafx.h"

#ifndef ACCUM_0_H
#define ACCUM_0_H

#include <iterator>
template<typename Iter>
inline typename std::iterator_traits<Iter>::value_type accumulate(Iter start,Iter end){
	typedef typename std::iterator_traits<Iter>::value_type VT;
	VT total = VT();
	while (start!=end){
		total += *start;
		start++;
	}
	return total;
}

//namespace std{
//	template<typename T>
//	struct iterator_traits{ };
//
//    template<typename T>
//	struct iterator_traits<T*> {
//		typedef T value_type;
//		typedef ptrdiff_t difference_type;
//		typedef random_access_iterator_tag iterator_category;
//		typedef T* pointer;
//		typedef T& reference;
//	};
//}


#endif//ACCUM_0_H