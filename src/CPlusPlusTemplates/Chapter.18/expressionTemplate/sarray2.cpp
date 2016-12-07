#include "stdafx.h"

#include "sarray1.h"
#include "sarrayops2.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SArray<double> x(1000), y(1000);
	SArray<double> temp(x);

	temp *= y;
	x *= 1.2;
	x += temp;
	return 0;
}