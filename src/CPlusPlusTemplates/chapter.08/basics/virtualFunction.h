#include "../stdafx.h"

//类模板的成员函数模板不能为虚函数
template<typename T>
class Dynamic{
public:
	Dynamic();//普通成员函数
	virtual ~Dynamic();//普通成员函数

	template<typename T2>
    void copy(T2 const&);//类模板的成员函数模板不能为虚函数。原因：在确定Dynamic<T>实例的时候，并不知道Copy的个数。
};