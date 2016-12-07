#include "../stdafx.h"
#include <List>
/*使用缺省模板实参，可以避免提供显示模板参数
template<typename T=double>
void f(T const&=T());

void test(){
	f(1);//f<int>(1);
	f<long>(2);
	f<char>('\0');
	f(0);
	}
*/

/*
template<typename T1,
	     typename T2,
         template<typename ElementType,typename Alloc=std::allocator<ElementType>> 
         class Container
>
class Relation{
public:
private:
	Container<T1> dom1;
	Container<T2> dom2;
};

void test(){
	Relation<int, double, std::list> rel;//incorrect
}
*/

/**/
template<typename T>
T const& max(T const&,T const&);

template<typename T>
T* const& max<T*>(T* const&,T* const&);
