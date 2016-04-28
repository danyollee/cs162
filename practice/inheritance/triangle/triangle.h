#include <iostream>

using namespace std;

class Triangle{
private:
	int height;
public:
	Triangle();
	Triangle(int);
	int get_height() const;
	void set_height(int);
	~Triangle();
	double get_area(int) const;
};
