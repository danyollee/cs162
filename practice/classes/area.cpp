#include <iostream>

using namespace std;

class Rectangle{
private:
	int length, width;
public:
	Rectangle(int, int);
	int area(int, int);
};

Rectangle::Rectangle(int x, int y){
	length=x;
	width=y;
}

int area(int length, int width){
	int areas;
	areas=length*width;
	return areas;
}

int main(){
	Rectangle rect1, rect2;
  	cout << "area of rect1: " << rect1.area(3, 4) << endl;
  	cout << "area of rect2: " << rect2.area(10, 10) << endl;

	return 0;
}