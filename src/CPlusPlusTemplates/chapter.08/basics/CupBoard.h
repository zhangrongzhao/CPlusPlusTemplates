#include "../stdafx.h"

//���������Ա
template<int I>
class CupBoard{
public:
	void open();
	class Shelf;
	static double total_weight;
};

template<int I>
void CupBoard<I>::open(){//��ģ��ĳ�Ա����ģ�嶨��

}

template<int I>
class CupBoard<I>::Shelf{//��ģ���Ƕ�����Ա����

};

template<int I>
double CupBoard<I>::total_weight = 0.0;



