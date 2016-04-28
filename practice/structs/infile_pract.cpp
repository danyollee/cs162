#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int main(){
	int counter=0, x, y;
	string item;

	ifstream inFruits, inNumbers;
	inFruits.open("fruits.txt");

	//check for errors
	if(inFruits.fail()){
		cout << "Error opening file" << endl;
		exit(1);
	}

	//reads the file until it reaches the end
	while(!inFruits.eof()){
		inFruits >> item;
		if(item=="apple")
			counter++;
	}

	cout << counter << " instances of apples found!" << endl;

	inFruits.close();

	inNumbers.open("numbers.txt");

	if(inNumbers.fail()){
		cout << "Error opening numbers.txt" << endl;
		exit(1);
	}

	inNumbers >> x >> y;

	cout << "Num 1: " << x << endl;
	cout << "Num 2: " << y << endl;

	inNumbers.close();

	return 0;
}