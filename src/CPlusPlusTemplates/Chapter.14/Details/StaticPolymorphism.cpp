#include "stdafx.h"
#include "StaticPolymorphism.h"
#include <vector>
/*
//��������GeoObj
template<typename GeoObj>
void myDraw(GeoObj const& obj){
	obj.draw();//���ݶ�������͵�����Ӧ��draw()
}


//��������GeoObj����֮������ĵľ��롣
template<typename GeoObj1,typename GeoObj2>
void distance(GeoObj1 const& x1,GeoObj2 const& x2){
	x1.center_of_gravity();
	x2.center_of_gravity();
}

//�����������༯�ϵ�GeoObj����
template<typename GeoObj>
void drawElements(std::vector<GeoObj> const& elements){
	for (unsigned i = 0; i < elements.size(); i++){
		elements[i].draw();//����Ԫ�ص����͵�����Ӧ��draw()
	}
}

void test_StaticPolymorphism(){
	Line l;
	Circle c, c1, c2;
	
	myDraw(l);//myDraw<Line>(GeoObj&)=>Line::draw()
	myDraw(c);//myDraw<Circle>(GeoObj&)=>Circle::draw()

	distance(c1,c2);//distance<Circle,Circle>(GeoObj1&,GeoObj2&);
	distance(l, c);//distance<Line,Circle>(GeoObj1&,GeoObj2&);

	//std::vector<GeoObj*> coll;
	std::vector<Line> coll;//ͬ�༯��������������ġ�
	coll.push_back(l);

	drawElements(coll);
}
*/


