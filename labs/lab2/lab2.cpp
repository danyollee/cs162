#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

#include "letters.h"

void file_input(string* file_name){
	cout << "Enter a file you'd like to open: ";
	getline(cin, *file_name);

	open_file(*file_name);
}

void open_file(string file_name){
	int counter[26];
	ifstream file_fun;

	for(int i=0; i<26; i++)
		counter[i]=0;

	file_fun.open(file_name.c_str());
	if(!file_fun){
		cout << "Error, file doesn't exist." << endl;
		file_input(&file_name);
	}
	count_letters(file_fun, counter);
}

void count_letters(ifstream& file_fun, int* counter){
	char temp;
	int arr_temp;

	for(int i=0; i<26; i++){
		while(!file_fun.eof()){
			file_fun >> temp;
			if(temp<95){
				arr_temp=temp-65;
				counter[arr_temp]++;
			}
			if(temp>95){
				arr_temp=temp-97;
				counter[arr_temp]++;
			}
		}
	}

	file_fun.close();

	user_wants_what(counter);
}

void user_wants_what(int* counter){
	char letter_to_show;
	int loc; //location for the array

	cout << "What letter do you want to see the amount of?: ";
	cin >> letter_to_show;

	if(letter_to_show>95)
		loc=letter_to_show-97;
	if(letter_to_show<95)
		loc=letter_to_show-65;

	cout << "There are " << counter[loc] << " " << letter_to_show << "'s in file_fun.txt" << endl;

	file_output(counter, loc, letter_to_show);

	exit(1);
}

void file_output(int* counter, int loc, char letter_to_show){
	string file_name;
	ofstream outFile;

	cout << "Whats the name of the file that you want to output to?: ";
	cin.ignore();
	getline(cin, file_name);

	open_out_file(file_name, counter, loc, letter_to_show);
}

void open_out_file(string file_name, int* counter, int loc, char letter_to_show){
	ofstream outFile;

	outFile.open(file_name.c_str());
	if(!outFile){
		cout << "Error, file doesn't exist." << endl;
		file_output(counter, loc, letter_to_show);
	}

	output_letters(outFile, counter, loc, letter_to_show);
}

void output_letters(ofstream& outFile, int* counter, int loc, char letter_to_show){
	outFile << "There are " << counter[loc] << " instances of the letter " << letter_to_show << " in the file." << endl;

	outFile.close();
}