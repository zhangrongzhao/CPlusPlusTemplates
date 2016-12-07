#include "stdafx.h"
#include "DynamicPolymorphism.h"
#include <vector>

/*
//绘制任意几何图形
void myDraw(GeoObj const& obj){
	obj.draw();//根据对象的类型来调用对应的draw()
}

//计算两个GeoObj对象重心之间的距离
double distance(GeoObj const& x1,GeoObj const& x2){
	double c = x1.center_of_gravity() - x2.center_of_gravity();
	return c;
}

//画出属于异类几何的GeoObj对象。
void drawElems(std::vector<GeoObj*> const& elements){
	for (unsigned i = 0; i < elements.size(); i++){
		elements[i]->draw();//根据元素的类型来调用相应的draw()
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

