#include "../stdafx.h"
#include "baseMemberPair.h"


class Empty{
public:
	typedef int Int32;//typedef ��Ա������ʹ���ɷǿ�
};
/*
class EmptyToo :public Empty {

};

class NonEmpty :public Empty,public EmptyToo{


};

template<typename T1,typename T2>
class MyClass:private T1,private T2{//1.ԭ������(int,union)2.T1,T2������ͬʱ3.�޸��˻��࣬�ı��˻���ӿڡ�
private:
	T1 a;
	T2 b;
};

void test(){
	MyClass<Empty, EmptyToo> oMyClass;//֮һΪ���࣬�˷�һ���ֽڵ��ڴ档
}
*/

/*
template<typename CustomClass>
class Optimizable{
private:
	CustomClass info;//����Ϊ��
	void* storage;//
}
*/

template<typename CustomClass>
class Optimizable{
public:
	BaseMemberPair<CustomClass, void*> info_and_storage;
};

