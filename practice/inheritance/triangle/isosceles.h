#include <iostream>
#include "triangle.h"

// using namespace std;

class Isosceles : public Triangle{
private:
	int base;
	int sideOne;
public:
	Isosceles();
	Isosceles(int, int, int);
	int get_base() const;
	int get_side_one() const;
	void set_base(int);
	void set_side_one(int);
	~Isosceles();
	int get_perimeter() const;
	void print_info() const;
};