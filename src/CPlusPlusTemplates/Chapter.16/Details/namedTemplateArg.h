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
	//ʹ��Policies::p1,Policies::p2,�����ø���policies.
};


//PolicySelector<A,B,C,D>����A,B,C,D��Ϊ����
//DiscriminatorʹPolicy Selector���Զ�μ̳�����ͬ�Ļ���
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

//�ֱ�����ȱʡֵpolicies Ϊp1,p2,p3,p4
class DefaultPolicies{
public:
	typedef DefaultPolicy1 p1;
	typedef DefaultPolicy2 p2;
	typedef DefaultPolicy3 p3;
	typedef DefaultPolicy4 p4;
};

//һ��Ϊ��ʹ��ȱʡpolicyֵ����
//������Ƕ��������DefaultPolicies,���������̳оͱ����˶�����
class DefaultPolicyArgs :virtual public DefaultPolicies{

};

template<typename Policy>
class Policy1_is :virtual public DefaultPolicies{
public:
	typedef Policy P1;//��дȱʡ��typedef
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



