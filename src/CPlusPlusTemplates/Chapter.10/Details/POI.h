#include "../stdafx.h"

/*����ģ���ʵ����
class MyInt{
public:
	MyInt(int i);
};

MyInt operator-(MyInt const&);
bool operator>(MyInt const&,MyInt const&);

typedef MyInt Int;

template<typename T>
void f(T i){
	if (i>0){
		g(-i);
	}
}

//(1)
void g(Int){
	//(2)
	f<Int>(42);//���õ�
	//(3)
}
//(4)*/

/*��ģ���ػ���POIλ�ò�ͬ�ں���ģ��:�������ʵ�����õĶ��������֮ǰ����������ռ䡣
template<typename T>
class S{
public :
	T m;
};
//(5)-->POI
unsigned long h(){
	//(6)
	return (unsigned long) sizeof(sizeof(S<int>));
	//(7)
}
//(8)*/


/**/
template<typename T>
class S{
public:
	typedef int I;
};

//(1)
template<typename T>
void f(){
     S<char>::I var1 = 41;
	 typename S<T>::I var2 = 42;
}