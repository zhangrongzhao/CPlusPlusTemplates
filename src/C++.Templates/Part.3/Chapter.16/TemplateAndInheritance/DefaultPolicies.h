#include "../stdafx.h"

#ifndef DEFAULT_POLICY_H
#define DEFAULR_POLICY_H

class DefaultPolicy1{ };
class DefaultPolicy2{ };
class DefaultPolicy3{ };
class DefaultPolicy4{ };

class DefaultPolicies{
public:
	typedef DefaultPolicy1 P1;
	typedef DefaultPolicy2 P2;
	typedef DefaultPolicy3 P3;
	typedef DefaultPolicy4 P4;
};

//使用虚继承,获取默认参数
class DefaultPolicyArgs:virtual public DefaultPolicies{ };

//使用虚继承，重写相应参数。
template<typename Policy>
class Policy1_is:virtual public DefaultPolicies{
public:
	typedef Policy P1;
};

template<typename Policy>
class Policy2_is :virtual public DefaultPolicies{
public:
	typedef Policy P2;
};

template<typename Policy>
class Policy3_is{
public:
	typedef Policy P3;
};

template<typename Policy>
class Policy4_is{
public:
	typedef Policy P4;
};

#endif//DEFAULT_POLICY_H