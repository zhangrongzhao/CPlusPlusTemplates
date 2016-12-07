#include "../stdafx.h"
#include "maxDec.h"

template<typename T>
T const& max(T const& a,T const& b){
	return a < b ? b : a;
}

