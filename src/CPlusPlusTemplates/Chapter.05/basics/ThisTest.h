#include "../stdafx.h"

template<typename T>
class Base{
public:
	void exit();
};

template<typename T>
class Derived:Base<T>{
public:
	void foo(){
		Base<T>::exit();//���벻��ͨ����fatal error.//9.4.2С����ϸ���ۡ�
	}
};