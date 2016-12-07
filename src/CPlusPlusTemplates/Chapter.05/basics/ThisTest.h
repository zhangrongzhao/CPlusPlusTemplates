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
		Base<T>::exit();//编译不能通过。fatal error.//9.4.2小节详细讨论。
	}
};