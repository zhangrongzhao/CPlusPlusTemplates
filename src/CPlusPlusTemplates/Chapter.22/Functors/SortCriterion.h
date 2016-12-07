#include "../stdafx.h"

#ifndef PERSON_SORT_CRITERION_H
#define PERSON_SORT_CRITERION_H

//排序标准
#include <set>
class Person{};

class PersonSortCriterion{
public:
	enum{ NumParams = 2 };
	typedef bool ReturnT;
	typedef Person const& Param1T;
	typedef Person const& Param2T;
	bool operator()(Person const& p1,Person const& p2) const{
	    //返回p1是否小于p2
		return false;
	}
};

namespace standard{
   template<typename T>
   class less{
   public:
	   bool operator()(T const& x,T const& y) const{
		   return x < y;
	   }
   };

   template<typename T>
   class greater{
   public:
	   bool operator()(T const& x,T const& y) const{
		   return x > y;
	   }
   };

   template<typename T>
   class equal{
   public:
	   bool operator()(T const& x,T const& y) const{
		   return x == y;
	   }
   };

   template<typename T>
   class notEqual{
   public:
	   bool operator()(T const& x,T const& y) const{
		   return x != y;
	   }
   };
}

void foo(){
	std::set<Person, std::less<Person>> c0, c1;//用operator<(小于号)进行排序
	std::set<Person, standard::greater<Person>> c2; //用operator>（大于号）进行排序

	std::set<Person, PersonSortCriterion> c3;//用用户自定义的排序规则进行排序

	//my_sort<std::less<Person>>();

	//my_sort(Person,std::set<Person>());
}

//作为模板类型实参的仿函数
template<typename FO>
void my_sort(...){
	FO compare;//创建函数对象
	if (compare(x, y)){//使用函数对象比较2个值。
	   //...
	}
}

//作为函数调用实参的仿函数
//template<typename F>
//void my_sort(...,F compare=F()){//允许调用者在运行期构造函数对象
	//if (compare(x,y)){//使用函数对象，来比较两个值。
	
	//}
//}

//结合函数调用参数和模板类型参数
template<typename T>
bool my_criterion(T const& x,T const& y);

class RuntimeCmp{ };

void test(){
    //借助于模板实参传递进来的仿函数，来调用排序函数
	my_sort<std::less<Person>>();

	//借助于值实参（即函数实参）传递进来的仿函数，来调用排序函数
	//my_sort(...,std::less<Person>());

	//借助于值实参（即函数实参）传递进来的指针，来调用函数
	//my_sort(my_criterion);

	//以编译期模板实参的形式传递排序规则
	//使用排序规则额的缺省构造函数
	std::set<int, RuntimeCmp> c1;

	//以运行期构造函数实参的形式传递排序规则
	std::set<int, RuntimeCmp>(RumtimeCmp());

	LessThan order;
	//sort<order>(...);//错误：要求派生类到基类的转型
	//sort<(MyCriterion&)order>();//非类型模板实参所引用的必须是一个简单的名称，不能含有转型

}

class SomeType{};
class MyCriterion{
public:
	virtual bool operator()(SomeType const&, SomeType const&) const = 0;
};

class LessThan :public MyCriterion{
public:
	virtual bool operator()(SomeType const&, SomeType const&) const;
};

//可以让一个指向class类型对象的指针或者引用作为非类型实参。
template<MyCriterion& F>
void sort(...);



//template<MyCriterion F>//Error:MyCriterion是一个class类型，不能作为非类型的模板实参。
//void my_sort();

//函数指针的封装
template<int (*FP)>
class FunctionReturningIntWrapper{
public:
	bool operator()(){
		return FP();//嵌入函数，封装为仿函数。
	}
};




#endif//PERSON_SORT_CRTTERION_H