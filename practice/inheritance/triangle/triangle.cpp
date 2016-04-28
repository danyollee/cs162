#include "triangle.h"

Triangle::Triangle(){
	height=0;
}

Triangle::Triangle(int newHeight){
	height=newHeight;
}

int Triangle::get_height() const{
	return height;
}

void Triangle::set_height(int newHeight){
	height=newHeight;
}

Triangle::~Triangle(){

}

double Triangle::get_area(int base) const{
	return (.5*base*height);
}