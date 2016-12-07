#include "../stdafx.h"
/*
template<typename PolicySetter1=DefaultPolicyArgs,
         typename PolicySetter2=DefaultPolicyArgs,
		 typename PolicySetter3=DefaultPolicyArgs,
		 typename PolicySetter4=DefaultPolicyArgs>
class BreadSlicer{
	typedef PolicySelector<PolicySetter1, 
		                   PolicySetter2, 
						   PolicySetter3, 
						   PolicySetter4> Policies;
	//使用Policies::p1,Policies::p2,来引用各个policies.
};


//PolicySelector<A,B,C,D>生成A,B,C,D作为基类
//Discriminator使Policy Selector可以多次继承自相同的基类
template<typename Base,int D>
class Discriminator :public Base{

};

template<typename Setter1,
	     typename Setter2,
		 typename Setter3,
		 typename Setter4>
class PolicySelector :public Discriminator<Setter1, 1>,
					  public Discriminator<Setter2, 2>,
					  public Discriminator<Setter3, 3>,
					  public Discriminator<Setter4, 4>{
		
};

//分别命名缺省值policies 为p1,p2,p3,p4
class DefaultPolicies{
public:
	typedef DefaultPolicy1 p1;
	typedef DefaultPolicy2 p2;
	typedef DefaultPolicy3 p3;
	typedef DefaultPolicy4 p4;
};

//一个为了使用缺省policy值的类
//如果我们多次派生自DefaultPolicies,下面的虚拟继承就避免了二义性
class DefaultPolicyArgs :virtual public DefaultPolicies{

};

template<typename Policy>
class Policy1_is :virtual public DefaultPolicies{
public:
	typedef Policy P1;//改写缺省的typedef
};

template<typename Policy>
class Policy2_is :virtual public DefaultPolicies{
public:
	typedef Policy P2;
};

template<typename Policy>
class Policy3_is :virtual public DefaultPolicies{
public:
	typedef Policy P3;
};

template<typename Policy>
class Policy4_is :virtual public DefaultPolicies{
public:
	typedef Policy P4;
};
*/



