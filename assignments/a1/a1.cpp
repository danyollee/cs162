#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

#include "a1.h"

/*********************************************************************
 ** Function: is_valid_arguments
 ** Description: just checks if the command line arguments are correctly formmated
 ** Parameters: argc and argv. the amount of arguments and what they are.
 ** Pre-Conditions: none
 ** Post-Conditions: checks to see if it's valid for the rest of the program.
 *********************************************************************/
void is_valid_arguments(int argc, char** argv){
	if(argc!=5 || strcmp(argv[1], "-s")!=0 || strcmp(argv[3], "-f")!=0){
		cout << "Error, not enough arguments. Please try again. \n(i.e a.out -s 2 -f stateInfo.txt)" << endl;
		exit(1);
	}
}

/*********************************************************************
 ** Function: create_states
 ** Description: creates the array for the state structs
 ** Parameters: amount_of_states
 ** Pre-Conditions: the command line arguments had to be valid
 ** Post-Conditions: creates the array of structs for states
 *********************************************************************/
state* create_states(int amount_of_states){
	state* state_array=new state[amount_of_states];
	return state_array;
}

/*********************************************************************
 ** Function: get_state_data
 ** Description: reads into a file and fills in the data for the structs
 ** Parameters: amount_of_states, state_array, stateFile
 ** Pre-Conditions: int, array and the file must be open
 ** Post-Conditions: fills in the data for each element of the array.
 *********************************************************************/
void get_state_data(int amount_of_states, state* state_array, ifstream& stateFile){
	for(int i=0; i<amount_of_states; i++){
		stateFile >> state_array[i].sname >> state_array[i].spopulation >> state_array[i].amount_of_counties;
		state_array[i].c=new county[state_array[i].amount_of_counties];
		for(int j=0; j<state_array[i].amount_of_counties; j++){
			stateFile >> state_array[i].c[j].cname >> state_array[i].c[j].cpopulation >> state_array[i].c[j].avg_income >> state_array[i].c[j].avg_house >> state_array[i].c[j].cities;
			state_array[i].c[j].city=new string[state_array[i].c[j].cities];
			for(int k=0; k<state_array[i].c[j].cities; k++){
				stateFile >> state_array[i].c[j].city[k];
			}
		}
	}

	cout << "Here are some statistics based on the information provided." << endl << endl;
}

/*********************************************************************
 ** Function: compare_spopulation
 ** Description: compares the population for each state
 ** Parameters: state_array and amount_of_states
 ** Pre-Conditions: array must be filled in correctly 
 ** Post-Conditions: sorts the array in a different manner.
 *********************************************************************/
void compare_spopulation(state* state_array, int amount_of_states){
	state temp;

	for(int i=0; i<(amount_of_states-1); i++){
		for(int j=(i+1); j<amount_of_states; j++){
			if(state_array[i].spopulation<state_array[j].spopulation){
				temp=state_array[j];
				state_array[j]=state_array[i];
				state_array[i]=temp;
			}
		}
	}

	cout << "The state with the largest population is " << state_array[0].sname << " with " << state_array[0].spopulation << " people." << endl << endl;

	cout << "The states sorted by population from largest to smallest go ";
	for(int i=0; i<amount_of_states; i++){
		cout << state_array[i].sname << ", ";
	}
	cout << endl;
}

/*********************************************************************
 ** Function: compare_cpopulation
 ** Description: like the spopulation function, except for the counties
 ** Parameters: state_array, amount_of_states
 ** Pre-Conditions: state_array must be filled in
 ** Post-Conditions: sorts the counties by population
 *********************************************************************/
void compare_cpopulation(state* state_array, int amount_of_states){
	county* temp;
	county tempo;
	int ctemp=0, loc=0;

	for(int i=0; i<amount_of_states; i++){
		ctemp+=state_array[i].amount_of_counties;
	}

	temp=new county[ctemp];

	for(int i=0; i<amount_of_states; i++){
		for(int j=0; j<state_array[i].amount_of_counties; j++){
			temp[loc]=state_array[i].c[j];
			loc++;
		}
	}

	for(int i=0; i<(ctemp-1); i++){
		for(int j=(i+1); j<ctemp; j++){
			if(temp[i].cpopulation<temp[j].cpopulation){
				tempo=temp[j];
				temp[j]=temp[i];
				temp[i]=tempo;
			}
		}
	}
	cout << endl <<"The county with the largest population is " << temp[0].cname << " county with " << temp[0].cpopulation << " people." << endl << endl;
}

/*********************************************************************
 ** Function: compare_county_income
 ** Description: doesn't sort but just does some math with the counties avg_income
 ** Parameters: state_array
 ** Pre-Conditions: state_array must be filled in
 ** Post-Conditions: just prints out the averages for avg_income
 *********************************************************************/
void compare_county_income(state* state_array, int amount_of_states){
	county* temp;
	county tempo;
	int threshold=0, ctemp=0, loc=0;

	cout << "Enter an income amount to compare the counties with: ";
	cin >> threshold;

	for(int i=0; i<amount_of_states; i++){
		ctemp+=state_array[i].amount_of_counties;
	}

	temp=new county[ctemp];

	for(int i=0; i<amount_of_states; i++){
		for(int j=0; j<state_array[i].amount_of_counties; j++){
			temp[loc]=state_array[i].c[j];
			loc++;
		}
	}

	for(int i=0; i<ctemp; i++){
		if(temp[i].avg_income>threshold){
			cout << temp[i].cname << " county has an average income of over " << threshold << " with " << temp[i].avg_income << " dollars. " << endl;
		}
	}
}

/*********************************************************************
 ** Function: compare_household_costs
 ** Description: compares but doesn't switch the avg_house cost
 ** Parameters: state_array
 ** Pre-Conditions: state_array must be filled in
 ** Post-Conditions: just prints information, not changes
 *********************************************************************/
void compare_household_costs(state* state_array, int amount_of_states){
	int* costs;
	int avg;

	cout << endl << "Here are the average household costs for each state." << endl;

	costs=new int[amount_of_states];

	for(int i=0; i<amount_of_states; i++){
		avg=0;
		for(int j=0; j<state_array[i].amount_of_counties; j++){
			avg+=state_array[i].c[j].avg_house;
		}
		costs[i]=(avg/3);
		cout << state_array[i].sname << " has an average household cost of roughly $" << costs[i] << "." << endl;
	}
}

/*********************************************************************
 ** Function: sort_states_name
 ** Description: sorts the array by the name of the state
 ** Parameters: state_array
 ** Pre-Conditions: state_array must be filled in
 ** Post-Conditions: switches elements around
 *********************************************************************/
void sort_states_name(state* state_array, int amount_of_states){
	state temp;

	for(int i=0; i<(amount_of_states-1); i++){
		for(int j=(i+1); j<amount_of_states; j++){
			if(state_array[i].sname.at(0)>state_array[j].sname.at(0)){
				temp=state_array[j];
				state_array[j]=state_array[i];
				state_array[i]=temp;
			}
		}
	}

	cout << endl << "The state names in alphabetical order are ";
	for(int i=0; i<amount_of_states; i++){
		cout << state_array[i].sname << ", ";
	}
	cout << endl;
}

/*********************************************************************
 ** Function: sort_county_names
 ** Description: switches the counties around in the array
 ** Parameters: state_array
 ** Pre-Conditions: state_array must be filled in 
 ** Post-Conditions: switches counties around
 *********************************************************************/
void sort_county_names(state* state_array, int amount_of_states){
	county temp;

	for(int i=0; i<amount_of_states; i++){
		for(int j=0; j<(state_array[i].amount_of_counties-1); j++){
			if(state_array[i].c[j].cname.at(0)<state_array[i].c[j+1].cname.at(0)){
				temp=state_array[i].c[j];
				state_array[i].c[j]=state_array[i].c[j+1];
				state_array[i].c[j+1]=temp;
			}
		}
	}

	cout << endl << "The county names in alphabetical order within each state.";
	for(int i=(amount_of_states-1); i>=0; i--){
		cout << endl << state_array[i].sname << "'s counties are ";
		for(int j=(state_array[i].amount_of_counties-1); j>=0; j--){
			cout << state_array[i].c[j].cname << ", ";
		}
	}
	cout << endl;
}

/*********************************************************************
 ** Function: delete_info
 ** Description: deletes the arrays and closes the files
 ** Parameters: state_array, stateFile
 ** Pre-Conditions: state_array must be filled in, stateFile must be open
 ** Post-Conditions: closes and deletes all the arrays
 *********************************************************************/
void delete_info(state* state_array, ifstream& stateFile){
	stateFile.close();
	delete [] state_array;
}

/*********************************************************************
 ** Function: again
 ** Description: gets choice from the user to see if they want to go again
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: loops the program
 *********************************************************************/
void again(){
	int choice, amount_of_states;
	cout << "Do you want to go again? (0 for no and 1 for yes): ";
	cin >> choice;

	if(choice==0){
		cout << "Okay, thanks!" << endl;
		exit(1);
	}
	else{
		cout << "How many states do you want to compare this time?: ";
		cin >> amount_of_states;
	}
	create_states(amount_of_states);
}