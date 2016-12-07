#include "../stdafx.h"

//参数化类成员
template<int I>
class CupBoard{
public:
	void open();
	class Shelf;
	static double total_weight;
};

template<int I>
void CupBoard<I>::open(){//类模板的成员函数模板定义

}

template<int I>
class CupBoard<I>::Shelf{//类模板的嵌套类成员定义

};

template<int I>
double CupBoard<I>::total_weight = 0.0;



