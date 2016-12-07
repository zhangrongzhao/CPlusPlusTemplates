#include "../stdafx.h"

#ifndef STATIC_POLYMORPHISM_H
#define STATIC_POLYMORPHISM_H
#include "../Common/Coord.h"
#include <vector>
//Circle
class Circle{
public:
	void draw() const{ 	}
	Coord center_of_gravity()const{ 
		Coord coord;
		return coord;
	}
};

//Line
class Line{
public:
	void draw() const{ }
	Coord center_of_gravity() const{ 
		Coord coord;
		return coord;
	}
};

//Rectangle
class Rectangle{
	void draw() const{ }
	Coord center_of_gravity() const{ 
		Coord coord;
		return coord;
	}
};

template<typename GeoObj>
void myDraw(GeoObj const& obj){
	obj.draw();
}

template<typename GeoObj1,typename GeoObj2>
Coord distance(GeoObj1 const& x1,GeoObj2 const& x2){
	return x1.center_of_gravity() - x2.center_of_gravity();
}

template<typename GeoObj>
void drawElements(std::vector<GeoObj> const& elements){
	for (unsigned i = 0; i < elements.size();i++){
		elements[i].draw();
	}
}

void test_staicPolymorphism(){
	//Line l;
	//Circle c, c1, c2;

	////myDraw(l);
	////myDraw(c);

	////distance(c1,c2);
	////distance(l,c);

	//std::vector<Line> collection;
	//collection.push_back(l);
	//drawElements(collection);

}

#endif//STATIC_POLYMORPHISM_H