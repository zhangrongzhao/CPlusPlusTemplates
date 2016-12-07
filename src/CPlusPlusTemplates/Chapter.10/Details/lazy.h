#include "../stdafx.h"

template<typename T>
class Safe{ };

template<int N>
class Danger{
public:
	typedef char Block[N];//如果N<=0,将会出错
};

template<typename T,int N>
class Tricky{
public :
	virtual ~Tricky(){}
	void no_body_here(Safe<T> = 3);
	void inclass(){
		Danger<N> no_boom_yet;
	}

	//void error(){Danger<0> boom;}
	void unsafe(T (*p)[N]);

	T operator->();

	//virtual void suspect(){  };//实例化时，需要看到虚函数的定义。
	struct Nested{
		Danger<N> pfew;
	};

	union {//匿名的union
		int align;
		Safe<T> anonymous;
	};
};
