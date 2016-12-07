#include "../stdafx.h"

#ifndef PERSON_SORT_CRITERION_H
#define PERSON_SORT_CRITERION_H

//�����׼
#include <set>
class Person{};

class PersonSortCriterion{
public:
	enum{ NumParams = 2 };
	typedef bool ReturnT;
	typedef Person const& Param1T;
	typedef Person const& Param2T;
	bool operator()(Person const& p1,Person const& p2) const{
	    //����p1�Ƿ�С��p2
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
	std::set<Person, std::less<Person>> c0, c1;//��operator<(С�ں�)��������
	std::set<Person, standard::greater<Person>> c2; //��operator>�����ںţ���������

	std::set<Person, PersonSortCriterion> c3;//���û��Զ������������������

	//my_sort<std::less<Person>>();

	//my_sort(Person,std::set<Person>());
}

//��Ϊģ������ʵ�εķº���
template<typename FO>
void my_sort(...){
	FO compare;//������������
	if (compare(x, y)){//ʹ�ú�������Ƚ�2��ֵ��
	   //...
	}
}

//��Ϊ��������ʵ�εķº���
//template<typename F>
//void my_sort(...,F compare=F()){//����������������ڹ��캯������
	//if (compare(x,y)){//ʹ�ú����������Ƚ�����ֵ��
	
	//}
//}

//��Ϻ������ò�����ģ�����Ͳ���
template<typename T>
bool my_criterion(T const& x,T const& y);

class RuntimeCmp{ };

void test(){
    //������ģ��ʵ�δ��ݽ����ķº�����������������
	my_sort<std::less<Person>>();

	//������ֵʵ�Σ�������ʵ�Σ����ݽ����ķº�����������������
	//my_sort(...,std::less<Person>());

	//������ֵʵ�Σ�������ʵ�Σ����ݽ�����ָ�룬�����ú���
	//my_sort(my_criterion);

	//�Ա�����ģ��ʵ�ε���ʽ�����������
	//ʹ�����������ȱʡ���캯��
	std::set<int, RuntimeCmp> c1;

	//�������ڹ��캯��ʵ�ε���ʽ�����������
	std::set<int, RuntimeCmp>(RumtimeCmp());

	LessThan order;
	//sort<order>(...);//����Ҫ�������ൽ�����ת��
	//sort<(MyCriterion&)order>();//������ģ��ʵ�������õı�����һ���򵥵����ƣ����ܺ���ת��

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

//������һ��ָ��class���Ͷ����ָ�����������Ϊ������ʵ�Ρ�
template<MyCriterion& F>
void sort(...);



//template<MyCriterion F>//Error:MyCriterion��һ��class���ͣ�������Ϊ�����͵�ģ��ʵ�Ρ�
//void my_sort();

//����ָ��ķ�װ
template<int (*FP)>
class FunctionReturningIntWrapper{
public:
	bool operator()(){
		return FP();//Ƕ�뺯������װΪ�º�����
	}
};




#endif//PERSON_SORT_CRTTERION_H