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
class Promotion; //Promotionģ��û����ȷ���壬�������������塣

//primary template
//�����������(type promotion)�Ļ���ģ��
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
//���������ͬ���͵ľֲ��ػ�
template<typename T>
class Promotion<T,T>{
public:
	typedef T ResultT;
};

//partial specialization
//Ԫ�����Ͳ�ͬ��������������
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







