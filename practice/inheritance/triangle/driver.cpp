#include <iostream>
#include "isosceles.h"

using namespace std;

int main(){
	int base, height, equal_side;

	cout << "Please type in a base length: ";
	cin >> base;
	cout << "Please type in the height: ";
	cin >> height;
	cout << "Please type in the side that is equal: ";
	cin >> equal_side;

	Isosceles myTriangle(base, equal_side, height);

	cout << endl;
	myTriangle.print_info();

	return 0;
}