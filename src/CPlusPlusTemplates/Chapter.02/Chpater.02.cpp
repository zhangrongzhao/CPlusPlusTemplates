// Chpater.02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include "basics/max3a.h"


int _tmain(int argc, _TCHAR* argv[])
{
	::max(7,42,68);

	const char *s1 = "frederic";
	const char *s2 = "anica";
	const char *s3 = "lucas";

	::max(s1,s2,s3);

	return 0;
}

