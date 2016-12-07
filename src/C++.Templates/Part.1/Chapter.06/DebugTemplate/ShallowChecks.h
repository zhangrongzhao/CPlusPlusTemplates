#include "../stdafx.h"

#ifndef SHALLOW_CHECKS_H
#define SHALLOW_CHECKS_H
template<typename T>
void clear(T const& ptr){
	*ptr = 0;//假设ptr是指针，做解引用，赋值初始值为0
}

template<typename T>
void core(T const& p){
	clear(p);
}

template<typename T>
void middle(typename T::Index p){
	core(i);
}

template<typename T>
void Ignore(T const&){ }

template<typename T>
void shell(T const& env){
	class shallowChecks{
		void deReference(typename T::Index ptr){
			Ignore(*ptr);
		}
	};

	typedef typename T::Index i;
	middle<T>(i);
}

//class client{
//public:
//	typedef int Index;
//};
//
//client main_client;
//
//void test(){
//	shell<client>(main_client);
//}





#endif//SHALLOW_CHECKS_H