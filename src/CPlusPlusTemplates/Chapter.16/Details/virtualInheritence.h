#include "../stdafx.h"
#include <iostream>
/*
class Top{
public:
	int a;
public:
	Top(){ a = -1; }
	Top(int _a){ a = _a; }
};

class Left :virtual public Top{
public:
	int b;
public:
	Left(){ b = -2; }
	Left(int _a,int _b):Top(_a){
		b = _b;
	}
};

class Right :virtual public Top{
public:
	int c;
public:
	Right(){ c = -3; }
	Right(int _a,int _c):Top(_a){
		c = _c;
	}
};

class Bottom :public Left, public Right{
public:
	int d;
public:
	Bottom(){ d = -4; }
	Bottom(int _a,int _b,int _c,int _d):Top(_a),Left(_a,_b),Right(_a,_c){
		d = _d;
	}
};

void test(){
	//Left* left = new Left();
	//Top* top1 = left;//top��leftָ��ͬһ��ַ��

	//Right* right = new Right();
	//Top* top2 = right;

	Bottom* bottom = new Bottom();
	//����Bottomָ��
	Left* left = bottom;

	Right* right = bottom;

	//Top* top = bottom;

	Top* topL = (Left*)bottom;
	Top* topR = (Right*)bottom;
	

	Bottom bottom(1,2,3,4);
	std::cout << bottom.Left::a << " "
		<< bottom.Right::a << " "
		<< bottom.b << " "
		<< bottom.c << " "
		<< bottom.d << " "
		<< std::endl;


	Bottom* b = new Bottom();
	Right* r = b;
	if (b == r)
	{
		std::cout << "Equal" << std::endl;
	}
}
*/
/*����̳�
class Top{
public:
	int a=0;
public:
	Top(){ a = -1; }
	virtual ~Top(){}
};

class Left :virtual public Top{
public:
	int b = 0;
};

class Right :virtual public Top{
public:
	int c = 0;
};

class Bottom : public Left, public Right{
public :
	int d = 0;
};

class AnotherBottom :public Left, public Right{
public:
	int e;
	int f;
};

void test_virtualInherit(){
	//����ת��
	//Bottom* bottom = new Bottom();
	//Left* left = bottom;

	//int p = left->a;

	//����ת��
	Bottom* bottom1 = new Bottom();
	AnotherBottom* bottom2 = new AnotherBottom();

	Top* top1 = bottom1;
	Top* top2 = bottom2;

	//Left* left = dynamic_cast<Left*>(top1);
}
*/