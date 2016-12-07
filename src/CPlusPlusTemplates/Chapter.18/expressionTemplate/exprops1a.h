#include "../stdafx.h"

/*用于选择如何引用“表达式模板节点”的辅助trait class
*--通常情况下：传引用
*--对于Scalar:传值
*/

template<typename T>
class A_Scalar;

//primary template:reference
template<typename t>
class A_Traits{
public:
	typedef T const& ExprRef;//所引用的类型typedef成一个常量引用
};

//针对Scalar进行局部特化
template<typename T>
class A_Traits<A_Scalar<T>>{
public:
	typedef A_Scalar<T> ExprRef;
};