#include "stdafx.h"
//#include "dynahier.h"
//#include <vector>
//
//void myDraw(GeoObj const& obj){
//	obj.draw();//根据对象类型调用对象的draw.
//}
//
//Coord distance(GeoObj const& x1,GeoObj const& x2){
//	return x1.center_of_gravity() - x2.center_of_gravity();
//}
//
////处理不同类型的集合。
//void drawElems(std::vector<GeoObj*> const& elements){
//	for (unsigned i = 0; i < elements.size();++i){
//		elements[i]->draw();
//	}
//}
//
//void test_DynamicPolymorphism(){
//	Line l;
//	Circle c, c1, c2;
//	
//	myDraw(l);
//	myDraw(c);
//	distance(c1,c2);
//	distance(l,c);
//}
//
//int main(){
//	test_DynamicPolymorphism();
//}