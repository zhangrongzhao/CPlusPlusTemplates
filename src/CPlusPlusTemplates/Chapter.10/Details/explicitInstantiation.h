#include "../stdafx.h"

/*����ģ�����ʾʵ����
//primary template
template<typename T>
void f(T)throw (T){}

//4����Ч��ʵ������
template void f<int>(int)throw(int);
template void f<>(float)throw(float);
template void f(long) throw (long);
template void f(char);
*/

/*��ģ�����ʾʵ����*/
template<typename T>
class S{
public:
	void f(){}
};

template void S<int>::f();
template class S<void>;


