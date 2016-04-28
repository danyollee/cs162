#include "isosceles.h"

// using namespace std;

Isosceles::Isosceles(){
	base=0;
}

Isosceles::Isosceles(int newBase, int newSideOne, int newHeight)
:Triangle(newHeight){
	base=newBase;
	sideOne=newSideOne;
}

int Isosceles::get_base() const{
	return base;
}

int Isosceles::get_side_one() const{
	return sideOne;
}

void Isosceles::set_base(int newBase){
	base=newBase;
}

void Isosceles::set_side_one(int newSideOne){
	sideOne=newSideOne;
}

Isosceles::~Isosceles(){

}

int Isosceles::get_perimeter() const{
	return ((2*sideOne)+base);
}

void Isosceles::print_info() const{
	cout << "\nPerimeter is " << get_perimeter() << endl;
	cout << "Area is " << get_area(base) << endl;
}
