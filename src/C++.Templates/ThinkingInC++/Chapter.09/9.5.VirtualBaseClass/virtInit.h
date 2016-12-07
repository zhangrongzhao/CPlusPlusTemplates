#include "../stdafx.h"

#ifndef VIRTUAL_INIT_H
#define VIRTUAL_INIT_H
#include <iostream>
#include <string>

class M{
public:
	M(const std::string& s) { std::cout << "M" << s << std::endl; }
};

class A{
	M m;
public:
	A(const std::string& s):m(" in A"){ std::cout << "A " << s << std::endl;}
	virtual ~A(){ }
};

class B{
	M m;
public :
	B(std::string const& s) :m(" in B"){ std::cout << "B" << s << std::endl;}
	virtual ~B(){ }
};

class C{
	M m;
public:
	C(std::string const& s) :m(" in C"){ std::cout << "C" << s<< std::endl; }
	virtual ~C(){ }
};

class D{
	M m;
public:
	D(std::string const& s) :m(" in D"){ std::cout << "D" << s << std::endl; }
	virtual ~D(){ }
};

class E :public A, virtual public B, virtual public C{
	M m;
public:
	E(std::string const& s):A("from E"),B("from E"),C("from E"),m("in E"){std::cout << "E" << s << std::endl;}
	//virtual ~E(){ }
};

class F :virtual public B, virtual public C, public D{
	M m;
public:
	F(std::string const& s) :B("from F"), C("from F"), D("from F"), m("in F"){ std::cout << "F" << s << std::endl; }
	//virtual ~F(){}
};

class G :public E, public F{
	M m;
public:
	G(std::string const& s) :B(" from G"),C("from G"),E("from G"), F("from G"),m(" in G"){
		std::cout << "G" << s << std::endl;
	}
};

void test_virtual_init(){
	G g("from main");
}
#endif//VIRTUAL_INIT_H