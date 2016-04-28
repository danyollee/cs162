#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

#include "a1.h"
struct county{
 string cname; 
 string *city;
 int cities;
 int cpopulation; 
 float avg_income; 
 int avg_house;
};

struct state {
 string sname; 
 county *c;
 int amount_of_counties; 
 int spopulation; 
 };

//prototypes
void is_valid_arguments(int, char**);
state* create_states(int);
void get_state_data(int, state*, ifstream&);
void compare_spopulation(state*,int);
void compare_cpopulation(state*, int);
void compare_county_income(state*, int);
void compare_household_costs(state*, int);
void sort_states_name(state*, int);
void sort_county_names(state*, int);
void delete_info(state*, ifstream&); 
void again();

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

void is_valid_arguments(int argc, char** argv){
	if(argc!=5 || strcmp(argv[1], "-s")!=0 || strcmp(argv[3], "-f")!=0){
		cout << "Error, not enough arguments. Please try again. \n(i.e a.out -s 2 -f stateInfo.txt)" << endl;
		exit(1);
	}
}

state* create_states(int amount_of_states){
	state* state_array=new state[amount_of_states];
	return state_array;
}

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

void delete_info(state* state_array, ifstream& stateFile){
	stateFile.close();
	delete [] state_array;
}

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