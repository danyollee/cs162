/******************************************************
** Program: a1.cpp
** Author: Daniel Lee
** Date: 04/10/2016
** Description: Takes in information from states and provides statistics on them.
** Input: Command line arguments
** Output: Statistics
******************************************************/ 

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

#include "a1.h"

int main(int argc, char** argv){
	is_valid_arguments(argc, argv);
	ifstream stateFile;
	char namefile[20];
	
	state* state_array;
	int amount_of_states;

	strcpy(namefile, argv[4]);
	string filename=namefile;

	amount_of_states=atoi(argv[2]);
	stateFile.open(filename.c_str());
	while(!stateFile){
		stateFile.open(filename.c_str());
		cout << "Error, file doesn't exist. Try again: ";
		getline(cin, filename);
	}

	state_array=create_states(amount_of_states);

	get_state_data(amount_of_states, state_array, stateFile);

	compare_spopulation(state_array, amount_of_states);
	compare_cpopulation(state_array, amount_of_states);
	compare_county_income(state_array, amount_of_states);
	compare_household_costs(state_array, amount_of_states);
	sort_states_name(state_array, amount_of_states);
	sort_county_names(state_array, amount_of_states);

	delete_info(state_array, stateFile);

	again();

	return 0;
}