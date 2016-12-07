#include "../stdafx.h"

#ifndef BIT_OR_CLASS_CSM_H
#define BIT_OR_CLASS_CAM_H
#include <new>
#include <cstring>
#include <cassert>
#include <stddef.h>
#include "RParam.h"

//基本模板
template<typename T,bool Bitwise>
class BitOrClassCSM;

//用户对象安全copy的局部特化
template<typename T>
class BitOrClassCSM<T,false>{
public:
	static void copy(typename RParam<T>::Type src,T* dst){
	     //把源对象copy赋值给目标对象
		*dst = src;
	}

	//从源数据中copy数据n项到目标
	static void copy_n(T const* src,T* dst,size_t n){
		for (size_t k = 0; k < n;k++){
			dst[k] = src[k];
		}
	}

	//copy源数据一项到未初始化的存储空间
	static void copy_init(typename RParam<T>::Type src,void* dst){
		::new(dst) T(src);
	}

	//copy源数据N项到未初始化的存储空间
	static void copy_init_n(T const* src,void* dst,size_t n){
		for (size_t k = 0; k < n;k++){
			::new((void*)((char*)dst + k)) T(src[k]);
		}
	}

	//交换：
	static void swap(T* a,T* b){
		T temp(*a);
		*a = *b;
		*b = temp;
	}

	static void swap_n(T* a,T* b,size_t n){
		for (size_t k = 0; k < n;k++){
			T temp(a[k]);
			a[k] = b[k];
			b[k] = tem;
		}
	}

	//移动：
	static void move(T* src,T* dst){
		assert(src!=dst);
		*dst = *src;
		src->~T();
	}

	static void move_n(T* src,T* dst,size_t n){
		assert(src!=dst);
		for (size_t k = 0; k < n;k++){
			dst[k] = src[k];
			src[k].~T();
		}
	}

	static void move_init(T* src,void* dst){
		assert(src!=dst);
		::new(dst) T(*src);
		src->~T();
	}

	static void move_init_n(T const* src,void* dst,size_t n){
		assert(src!=dst);
		for (size_t k = 0; k < n;k++){
			::new((void*)((char*)dst+k)) T(src[k]);
			src[k].~T();
		}
	}
};

//针对更快的对象位元copy而实现的局部特化
template<typename T>
class BitOrClassCSM<T, true> :public BitOrClassCSM<T,false>{
public:
	static void copy_n(T const* src,T* dst, size_t n){
		std::memcpy((void*)dst,(void*)src,n);
	}

	static void copy_init_n(T const* src,void* dst,size_t n){
		std::memcpy(dst,(void*)src,n);
	}

	static void move_n(T* src,T* dst,size_t n){
		assert(src!=dst);
		std::memcpy((void*)dst,(void*)src,n);
	}

	static void move_init_n(T const* src,void* dst,size_t n){
		assert(src!=dst);
		std::memcpy(dst,(void*)src,n);
	}
};

#endif//BIT_OR_CLASS_CSM_H