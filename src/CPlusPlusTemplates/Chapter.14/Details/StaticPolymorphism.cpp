#include "stdafx.h"
#include "StaticPolymorphism.h"
#include <vector>
/*
//画出任意GeoObj
template<typename GeoObj>
void myDraw(GeoObj const& obj){
	obj.draw();//根据对象的类型调用相应的draw()
}


//计算两个GeoObj对象之间的重心的距离。
template<typename GeoObj1,typename GeoObj2>
void distance(GeoObj1 const& x1,GeoObj2 const& x2){
	x1.center_of_gravity();
	x2.center_of_gravity();
}

//画出属于异类集合的GeoObj对象
template<typename GeoObj>
void drawElements(std::vector<GeoObj> const& elements){
	for (unsigned i = 0; i < elements.size(); i++){
		elements[i].draw();//根据元素的类型调用相应的draw()
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
	std::vector<Line> coll;//同类集合在这里是允许的。
	coll.push_back(l);

	drawElements(coll);
}
*/


