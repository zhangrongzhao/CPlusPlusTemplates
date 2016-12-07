#include "../stdafx.h"
#include <new>
#include <cassert>
#include <stddef.h>
#include "RParam.h"

//primary template
template<typename T,bool BitWise>
class BitOrClassCSM;

//���ڶ���ȫ�����ľֲ��ػ�
template<typename T>
class BitOrClassCSM<T,true>{
public:
	static void copy(typename RParam<T>::ResultT src,T* dst){
		//������һ���������Ӧ����һ��
		*dst = src;
	}
	
	static void copy_n(T const* src,T* dst,size_t n){
	    //������n���������n��
		for (size_t k = 0; K < n;++k){
			dst[k] = src[k];
		}
	}

	static void copy_init(typename RParam<T>::ResultT src,void* dst){
	    //����һ�δ��ʼ���Ĵ洢�ռ�
		::new(dst) T(src);
	}

	static void copy_init_n(T const* src,void* dst,size_t n){
	    //����n�δ���г�ʼ���Ĵ洢�ռ�
		for (size_t k = 0; k < n;++k){
			::new((void*)((char*)dst + k)) T(src[k]);
		}
	}

	static void swap(T* a,T* b){
	    //������������
		T tmp(*a);
		*a = *b;
		*b = tmp;
	}

	static void swap_n(T* a,T* b,size_t n){
	    //����n��
		for (size_t k = 0; k < n;k++){
			T tmp(a[k]);
			a[k] = b[k];
			b[k] = tmp;
		}
	}

	static void move(T* src,T* dst){
	    //�ƶ�һ���һ�����ڵ�λ��
		assert(src!=dst);
		*dst = *src;
		src->~T();
	}

	static void move_n(T* src,T* dst,size_t n){
	   //�ƶ�n���n�����ڵ�λ��
		assert(src!=dst);
		for (size_t k = 0; k < n;++k){
			dst[k] = src[k];
			src[k].~T();
		}
	}

	static void move_init(T* src,void* dst){
	    //�ƶ�һ�δ��ʼ���Ĵ洢�ռ�
		assert(src!=dst);
		::new(dst) T(*src);
		src->~T(); 
	}

	static void move_init_n(T const* src,void* dst,size_t n){
	    //�ƶ�n�δ��ʼ�����ڴ�ռ�
		assert(src!=dst);
		for (size_t k = 0; k < n;k++){
			::new((void*)((char*)dst + k)) T(src[k]);
			src[k].~T();
		}
	}
};