#include "../stdafx.h"

#ifndef NAMED_PARAMETER_OF_TEMPLATE_H
#define NAMED_PARAMETER_OF_TEMPLATE_H
#include "DefaultPolicies.h"
#include "PolicySelector.h"

template<typename PolicySetter1 = DefaultPolicyArgs,
	     typename PolicySetter2 = DefaultPolicyArgs,
	     typename PolicySetter3 = DefaultPolicyArgs,
	     typename PolicySetter4 = DefaultPolicyArgs>
class BreadSlicer{ 
public:
	typedef PolicySelector<PolicySetter1, PolicySetter2, PolicySetter3, PolicySetter4> Policies;

	// π”√£∫
	//Policies::P1;
	//Policies::P2;
	//Policies::P3;
	//Policies::P4;
};

void test_Policy(){
	BreadSlicer<Policy4_is<int>> oBreadSlicer;
}
#endif//NAMED_PARAMETER_OF_TEMPLATE_H