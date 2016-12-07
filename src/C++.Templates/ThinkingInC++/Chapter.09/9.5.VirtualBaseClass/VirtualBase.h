#include "../stdafx.h"

#ifndef VIRTUAL_BASE_H
#define VIRTUAL_BASE_H
//shows a shared subobject via a virtual base.
#include <iostream>
using namespace std;

class Top{
protected:
	int x;
public:
	//Top() :x(0){ }
	Top(int n){ x = n; }
	virtual ~Top(){ }

	friend ostream& operator<<(ostream& os,const Top& t){
		return os << t.x;
	}
};

class Left :virtual public Top{
protected:
	int y;
protected:
	void specialPrint(ostream& os) const{
		os << "," << y;
	}
public:
	Left(int m, int n) :Top(m){ y = n; }
	friend ostream& operator<<(ostream& os,Left const& l){
		return os << static_cast<const Top &>(l) << "," << l.y;
	}
};

class Right :virtual public Top{
protected:
	int z;
protected:
	void specialPrint(ostream& os) const{
		os << "," << z;
	}
public:
	Right(int m, int n) :Top(m){ z = n; }
	friend ostream& operator<<(ostream& os,Right const& r){
		return os << static_cast<const Top&>(r) << r.z;
	}
};

class Bottom :public Left, public Right{
private:
	int w;
public:
	Bottom(int i, int j, int k, int m) :Top(i), Left(0, j), Right(0, k){ w = m; }
	friend ostream& operator<<(ostream& os,const Bottom& b){
		//return os << b.x << "," << b.y << "," << b.z << "," << b.w;
		//return os << static_cast<Left const&>(b) << "," << static_cast<Right const&>(b) << "," << b.w;
		os << static_cast<Top const&>(b);
		b.Left::specialPrint(os);
		b.Right::specialPrint(os);
		return os << "," << b.w;
	}
};

void test_virtual_base(){
	Bottom b(1,2,3,4);
	//std::cout << sizeof(b) << std::endl;
	std::cout << b << std::endl;

	//std::cout << static_cast<void*>(&b) << std::endl;
	//Top* p = static_cast<Top*>(&b);
	//std::cout << *p << std::endl;
	//std::cout << static_cast<void*>(p) << std::endl;
	//std::cout << dynamic_cast<void*>(p) << std::endl;
}

#endif//VIRTUAL_BASE_H