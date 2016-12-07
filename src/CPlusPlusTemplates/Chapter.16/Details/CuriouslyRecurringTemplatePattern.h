#include "../stdafx.h"

template<typename Derived>
class CuriousBase{};

class Curious :public CuriousBase<Curious>{};//派生类将本身作为模板参数传递给基类。

template<typename T>
class CuriousTemplate :public CuriousBase<CuriousTemplate<T>>{};

/*2*/
template<template<typename> class Derived>
class MoreCuriousBase{};

template<typename T>
class MoreCurious :public MoreCuriousBase<MoreCurious>{};
