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