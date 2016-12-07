#include "../stdafx.h"

template<typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<char>{
public:
	typedef int AccT;
	static AccT const zero = 0;
};

template<>
class AccumulationTraits<short>{
public:
	typedef int AccT;
	static AccT const zero = 0;
};

template<>
class AccumulationTraits<int>{
public:
	typedef long AccT;
	static AccT const zero = 0;
};

template<>
class AccumulationTraits<float>{
public:
	typedef double AccT;
	static double const zero;
};

double const AccumulationTraits<float>::zero = 0.0;