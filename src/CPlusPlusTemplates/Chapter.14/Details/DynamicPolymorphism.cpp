#include "stdafx.h"
#include "DynamicPolymorphism.h"
#include <vector>

/*
//�������⼸��ͼ��
void myDraw(GeoObj const& obj){
	obj.draw();//���ݶ�������������ö�Ӧ��draw()
}

//��������GeoObj��������֮��ľ���
double distance(GeoObj const& x1,GeoObj const& x2){
	double c = x1.center_of_gravity() - x2.center_of_gravity();
	return c;
}

//�����������༸�ε�GeoObj����
void drawElems(std::vector<GeoObj*> const& elements){
	for (unsigned i = 0; i < elements.size(); i++){
		elements[i]->draw();//����Ԫ�ص�������������Ӧ��draw()
	}
}

void test_DynamicPolymorphism(){
	Line l;
	Circle c, c1, c2;

	myDraw(l);//Line::draw()
	myDraw(c);//Circle::draw()

	distance(c1,c2);
	distance(l,c);

	std::vector<GeoObj*> coll;
	coll.push_back(&l);
	coll.push_back(&c);

	drawElems(coll);
}
*/

