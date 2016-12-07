#include "../stdafx.h"
#include <cstring>
#include <cassert>
#include <stddef.h>
#include "csm1.h"

//针对更快的对象位元拷贝而实现的局部特化
template<typename T>
class BitOrClassCSM<T,true>:public BitOrClassCSM<T,false>{
public:
	static void copy_n(T const* src,T* dst,size_t n){
	    //拷贝n项到其他的对象
		std::memcpy((void*)dst,(void*)src,n);
	}

	static void copy_init_n(T const* src,void* dst,size_t n){
	    //拷贝n项到未初始化的存储空间
		std::memcpy(dst,(void*)src,n);
	}

	static void move_n(T* src,T* dst,size_t n){
	    //移动n项到其他对象的n项
		assert(src!=dst);
		std::memcpy((void*)dst,(void*)src,n);
	}

	static void move_init_n(T const* src,void* dst,size_t n){
	    //移动n项到未初始化的内存空间
		assert(src!=dst);
		std::memcpy(dst,(void*)src,n);
	}
};