#include "../stdafx.h"

#ifndef POLICY_SELECTOR_H
#define POLICY_SELECTOR_H

template<typename Base, int N>
class Discriminator :public Base{ };

template<typename Policy1, typename Policy2, typename Policy3, typename Policy4>
class PolicySelector : public Discriminator<Policy1, 1>,
	                   public Discriminator<Policy2, 2>,
	                   public Discriminator<Policy3, 3>,
	                   public Discriminator<Policy4, 4>{

};
#endif//POLICY_SELECTOR_H