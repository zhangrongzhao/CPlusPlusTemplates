#include "../stdafx.h"

#ifndef ARRAY_SCALAR
#define ARRAY_SCALAR

//用于表示放大倍数的对象的所属类
template<typename T>
class A_Scalar{
private:
	T const& s;
public:
	//构造函数，用于初始化值
	A_Scalar(T const& v),s(v){
	 
	}

	//对于索引下标操作而言，每个元素的值都等于scalar放大倍数的值
	T operator[](size_t idx){
		return s;
	}

	//scalar的大小（即元素个数为）0
	size_t size() const{
		return 0;
	}
};
#endif//ARRAY_SCALAR