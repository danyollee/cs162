//Function headers

#include <iostream>
#include <string>

using namespace std;

#ifndef BMI_H
#define BMI_H

class BMI{
public:
	//Default constructor
	BMI();

	//Overload constructor
	BMI(string, int, double);

	//Destructor
	~BMI();

	//Accessor functions
	string getName() const; //getname returns the name of the student
	int getHeight() const; //getHeight returns the height of the student
	double getWeight() const; //getWeight returns the weight of the student

	//Mutator functions
	void setName(string); //sets the name of the student
	void setHeight(int); //sets the height of the student
	void setWeight(double); //sets the weight of the student

	double calculateBMI(); //calculates BMI of students and returns a double

private:
	//Member variables
	string newName;
	int newHeight;
	double newWeight;
};

#endif 