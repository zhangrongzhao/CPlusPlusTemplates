#include "../stdafx.h"
#include "IfThenElse.h"

/*
template<typename T>
Array<T> operator+(Array<T> const&,Array<T> const&);

template<typename T1,typename T2>
Array<?> operator+(Array<T1> const&,Array<T2> const&);


template<typename T1,typename T2>
Array<typename Promotion<T1, T2>::ResultT> operator+(Array<T1> const&,Array<T2> const&);

template<typename T1,typename T2>
typename Promotion<Array<T1>, Array<T2>>::ResultT operator+(Array<T1> const&,Array<T2> const&);
*/

//declaration template
template<typename T1,typename T2>
class Promotion; //Promotion模板没有明确定义，就先声明不定义。

//primary template
//针对类型提升(type promotion)的基本模板
template<typename T1,typename T2>
class Promotion{
public:
	typedef typename IfThenElse<(sizeof(T1)>sizeof(T2)),
		                        T1,
								typename IfThenElse<(sizeof(T1)<sizeof(T2)),
								                    T2,
													void
								                   >::ResultT
								>::ResultT ResultT;

};

//partial specialization
//针对两个相同类型的局部特化
template<typename T>
class Promotion<T,T>{
public:
	typedef T ResultT;
};

//partial specialization
//元素类型不同的数组类型提升
template<typename T1,typename T2>
class Promotion<Array<T1>,Array<T2> >{
public:
	typedef Array<typename Promotion<T1,T2>::ResultT> ResultT;
};

//partial specialization
template<typename T>
class Promotion<Array<T>,Array<T> >{
public:
	typedef Array<typename Promotion<T,T>::ResultT> ResultT;
};







