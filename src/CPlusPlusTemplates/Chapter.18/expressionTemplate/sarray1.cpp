#include "stdafx.h"
#include "sarray1.h"
#include "sarrayops1.h"

void test_SArray(){
	SArray<double> x(1000), y(1000);
	x = 1.2*x + x*y;
}
