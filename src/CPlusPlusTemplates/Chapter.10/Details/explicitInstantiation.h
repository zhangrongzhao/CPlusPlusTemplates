#include "../stdafx.h"

/*函数模板的显示实例化
//primary template
template<typename T>
void f(T)throw (T){}

//4个有效的实例化体
template void f<int>(int)throw(int);
template void f<>(float)throw(float);
template void f(long) throw (long);
template void f(char);
*/

/*类模板的显示实例化*/
template<typename T>
class S{
public:
	void f(){}
};

template void S<int>::f();
template class S<void>;


