#include "../stdafx.h"
#include <cstring>
#include <cassert>
#include <stddef.h>
#include "csm1.h"

//��Ը���Ķ���λԪ������ʵ�ֵľֲ��ػ�
template<typename T>
class BitOrClassCSM<T,true>:public BitOrClassCSM<T,false>{
public:
	static void copy_n(T const* src,T* dst,size_t n){
	    //����n������Ķ���
		std::memcpy((void*)dst,(void*)src,n);
	}

	static void copy_init_n(T const* src,void* dst,size_t n){
	    //����n�δ��ʼ���Ĵ洢�ռ�
		std::memcpy(dst,(void*)src,n);
	}

	static void move_n(T* src,T* dst,size_t n){
	    //�ƶ�n����������n��
		assert(src!=dst);
		std::memcpy((void*)dst,(void*)src,n);
	}

	static void move_init_n(T const* src,void* dst,size_t n){
	    //�ƶ�n�δ��ʼ�����ڴ�ռ�
		assert(src!=dst);
		std::memcpy(dst,(void*)src,n);
	}
};