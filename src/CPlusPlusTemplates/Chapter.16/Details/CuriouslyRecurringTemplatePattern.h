#include "../stdafx.h"

template<typename Derived>
class CuriousBase{};

class Curious :public CuriousBase<Curious>{};//�����ཫ������Ϊģ��������ݸ����ࡣ

template<typename T>
class CuriousTemplate :public CuriousBase<CuriousTemplate<T>>{};

/*2*/
template<template<typename> class Derived>
class MoreCuriousBase{};

template<typename T>
class MoreCurious :public MoreCuriousBase<MoreCurious>{};
