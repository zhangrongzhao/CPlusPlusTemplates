#include "../stdafx.h"
#include <new>
#include <cassert>
#include <stddef.h>
#include "RParam.h"

//primary template
template<typename T,bool BitWise>
class BitOrClassCSM;

//用于对象安全拷贝的局部特化
template<typename T>
class BitOrClassCSM<T,true>{
public:
	static void copy(typename RParam<T>::ResultT src,T* dst){
		//把其中一项拷贝给所对应的另一项
		*dst = src;
	}
	
	static void copy_n(T const* src,T* dst,size_t n){
	    //将其中n项拷贝给其他n项
		for (size_t k = 0; K < n;++k){
			dst[k] = src[k];
		}
	}

	static void copy_init(typename RParam<T>::ResultT src,void* dst){
	    //拷贝一项到未初始化的存储空间
		::new(dst) T(src);
	}

	static void copy_init_n(T const* src,void* dst,size_t n){
	    //拷贝n项到未进行初始化的存储空间
		for (size_t k = 0; k < n;++k){
			::new((void*)((char*)dst + k)) T(src[k]);
		}
	}

	static void swap(T* a,T* b){
	    //交换其中两项
		T tmp(*a);
		*a = *b;
		*b = tmp;
	}

	static void swap_n(T* a,T* b,size_t n){
	    //交换n项
		for (size_t k = 0; k < n;k++){
			T tmp(a[k]);
			a[k] = b[k];
			b[k] = tmp;
		}
	}

	static void move(T* src,T* dst){
	    //移动一项到另一项所在的位置
		assert(src!=dst);
		*dst = *src;
		src->~T();
	}

	static void move_n(T* src,T* dst,size_t n){
	   //移动n项到另n项所在的位置
		assert(src!=dst);
		for (size_t k = 0; k < n;++k){
			dst[k] = src[k];
			src[k].~T();
		}
	}

	static void move_init(T* src,void* dst){
	    //移动一项到未初始化的存储空间
		assert(src!=dst);
		::new(dst) T(*src);
		src->~T(); 
	}

	static void move_init_n(T const* src,void* dst,size_t n){
	    //移动n项到未初始化的内存空间
		assert(src!=dst);
		for (size_t k = 0; k < n;k++){
			::new((void*)((char*)dst + k)) T(src[k]);
			src[k].~T();
		}
	}
};