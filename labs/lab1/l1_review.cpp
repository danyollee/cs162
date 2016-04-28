#include <iostream>
#include <cstdlib>
#include "./mult_div.h"

using namespace std;

int main(int argc, char* argv []){
	int r, c;

	//cout << "Usage: exe -r # -c #" << endl << endl;

	r = atoi(argv[1]);
	c = atoi(argv[2]);

	if(argc != 3){
		cout << "Usage error: exe -r # -c #" << endl << endl;
	}

	check_input(r, c);

	return 0;
}

bool check_input(int r, int c){
	if(r < 0 || c < 0){
		cout <<"Error, invalid dimensions, try again! " << endl;
	}
	else{
		make_table(r, c);
	}
}

Values** make_table(int r, int c){
	Values** table;
	table = new Values*[r];
	for(int i = 0; i < r; i++){
		table[i] = new Values [c];
	}

	set_mult(table, r, c);
	set_div(table, r, c);
}

void set_mult(Values **table, int r, int c){
	Values m;
	cout <<"Multiplication Table: " << endl;
	cout << endl;

	for (int i = 1; i < r+1; i++){
		for (int j = 1; j < c+1; j++){
			m.mult = i*j;
			cout <<" " << m.mult;
		}
		cout <<" " << endl;
	}

	cout << endl;
}

void set_div(Values **table, int r, int c){
	Values d;
	cout <<"Divison Table: " << endl;
	cout << endl;

	for (double i = 1; i < r+1; i++){
		for (double j = 1; j < c+1; j++){
			d.div = i / j;
			cout <<" " << d.div;
		}
		cout <<" " << endl;
	}

	cout << endl;

	run_again(r, c);
}

void delete_table(Values **table, int r){
	for (int i = 0; i < r; i++){
		delete &table[i];
	}

	delete [] table;
}


void run_again(int r, int c){
	bool ask = true;
	char choice;

	while (ask == true){
		cout << "Make another matrix? " << endl;
		cout << "1 - Yes " << endl;
		cout << "0 - No " << endl;
		cin >> choice;

		if (choice == '1'){
			new_matrix(r, c);
		}

		else if (choice == '0'){
			cout << "Thank you, goodbye!" << endl << endl;
			ask = false;
		}

		else{
			cout << "Please enter a 1 or 0." << endl << endl;
			ask = true;
		}
	}
}

void new_matrix(int r, int c){
	cout << "Rows: ";
	cin >> r;

	cout << "Columns: ";
	cin >> c;

	check_input(r, c);
}
