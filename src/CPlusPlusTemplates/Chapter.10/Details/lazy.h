#include "../stdafx.h"

template<typename T>
class Safe{ };

template<int N>
class Danger{
public:
	typedef char Block[N];//���N<=0,�������
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

	//virtual void suspect(){  };//ʵ����ʱ����Ҫ�����麯���Ķ��塣
	struct Nested{
		Danger<N> pfew;
	};

	union {//������union
		int align;
		Safe<T> anonymous;
	};
};
