#include <iostream>
#include <string>
#include "BMI.h"

int main(){

	string name;
	int height;
	double weight;

	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your height(in inches): ";
	cin >> height;
	cout << "Enter your weight(in pounds): ";
	cin >> weight;

	BMI Student_1(name, height, weight);

	cout << endl << "Patient name: " << Student_1.getName() << endl << 
	"Height: " << Student_1.getHeight() << endl << 
	"Weight: " << Student_1.getWeight() << endl;

	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your height(in inches): ";
	cin >> height;
	cout << "Enter your weight(in pounds): ";
	cin >> weight;


	BMI Student_2;

	Student_2.setName(name);

	cout << endl << "Patient name: " << Student_1.getName() << endl << 
	"Height: " << Student_1.getHeight() << endl << 
	"Weight: " << Student_1.getWeight() << endl <<
	"BMI: " << Student_2.calculateBMI() << endl;

	cout << endl << "Student 1 name: " << Student_1.getName() << endl;

	return 0;
}