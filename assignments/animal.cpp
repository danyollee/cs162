#include "animal.h"

/*********************************************************************
** Function: Animals
** Description: constructer
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: all values are set to be used later on
*********************************************************************/
Animals::Animals(){
  cost_to_feed=10;
  cost_of_tigers=10000;
  cost_of_penguins=1000;
  cost_of_pbs=5000;
  cost_of_emus=5000;
  age=3;
}

int Animals::set_bought_age(){
  age=3;
}

int Animals::increment_age(){
  age++;
  return age;
}

/*********************************************************************
** Function: set_born_age
** Description: sets the age to 0
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: age is 0
*********************************************************************/
int Animals::set_born_age(){
  age=0;
}

int Animals::get_age(){
  return age;
}

/*********************************************************************
** Function: get_animals_info
** Description: prints out the cost of each animal as well as how many there are
** Parameters: the counter for all animals, and the array for each animal
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Animals::get_animals_info(int pb_counter, int tig_counter, int penguin_counter, int emu_counter){
  cout << "Tigers cost $" << cost_of_tigers << " to purchase. You currently have "<< tig_counter << endl;
  cout << "Penguins cost $" << cost_of_penguins << " to purchase. You currently have "<< penguin_counter << endl;
  cout << "Polar bears cost $" << cost_of_pbs << " to purchase. You currently have " << pb_counter << endl;
  cout << "Emus cost $" << cost_of_emus << " to purchase. You currently have " << emu_counter << endl;
  cout << endl;
}

/*********************************************************************
** Function: get_cost_of_tigers
** Description: returns the cost to purchase a tiger
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the cost of tigers
*********************************************************************/
int Animals::get_cost_of_tigers(){
  return cost_of_tigers;
}

/*********************************************************************
** Function: get_cost_of_emus
** Description: returns the cost of emus
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the cost of emus
*********************************************************************/
int Animals::get_cost_of_emus(){
  return cost_of_emus;
}

/*********************************************************************
** Function: get_cost_of_penguins
** Description: returns the cost to purchase a penguin
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the cost to purchase a penguin
*********************************************************************/
int Animals::get_cost_of_penguins(){
  return cost_of_penguins;
}

/*********************************************************************
** Function: get_cost_of_pbs
** Description: gets the cost to purchase a Polarbear
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the cost to purchase a Polarbear
*********************************************************************/
int Animals::get_cost_of_pbs(){
  return cost_of_pbs;
}

/*********************************************************************
** Function: get_cost_to_feed_pbs
** Description: returns the cost to feed a polar bear
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the base cost to feed x 3
*********************************************************************/
int Animals::get_cost_to_feed_pbs(){
  return (3*cost_to_feed);
}

/*********************************************************************
** Function: get_cost_to_feed_emus
** Description: returns cost to feed the emus
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the base cost to feed x 4
*********************************************************************/
int Animals::get_cost_to_feed_emus(){
  return (4*cost_to_feed);
}

/*********************************************************************
** Function: get_cost_to_feed_tigers
** Description: returns the cost to feed tigers
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the base cost to feed x 5
*********************************************************************/
int Animals::get_cost_to_feed_tigers(){
  return (5*cost_to_feed);
}

/*********************************************************************
** Function: get_cost_to_feed_penguins
** Description: returns the cost to feed penguins
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the base cost to feed animals
*********************************************************************/
int Animals::get_cost_to_feed_penguins(){
  return cost_to_feed;
}

/*********************************************************************
** Function: calc_pb_feed_cost
** Description: calculates the total cost to feed all your polarbears
** Parameters: zoo_budget and the amount of polarbears
** Pre-Conditions: none
** Post-Conditions: the zoo budget is altered
*********************************************************************/
int Animals::calc_pb_feed_cost(int zoo_budget, int amount_to_feed){
  zoo_budget=zoo_budget-(get_cost_to_feed_pbs()*cost_to_feed);
  return zoo_budget;
}

/*********************************************************************
** Function: calc_tig_feed_cost
** Description: calculates the total cost to feed all your tigers
** Parameters: the zoo_budget and the amount of tigers
** Pre-Conditions: none
** Post-Conditions: the zoo budget is altered
*********************************************************************/
int Animals::calc_tig_feed_cost(int zoo_budget, int amount_to_feed){
  zoo_budget=zoo_budget-(get_cost_to_feed_tigers()*cost_to_feed);
  return zoo_budget;
}

/*********************************************************************
** Function: calc_peng_feed_cost
** Description: calculates the total cost to feed all your penguins
** Parameters: the zoo_budget and the amount of penguins
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int Animals::calc_peng_feed_cost(int zoo_budget, int amount_to_feed){
  zoo_budget=zoo_budget-(get_cost_to_feed_penguins()*cost_to_feed);
  return zoo_budget;
}



/*********************************************************************
** Function: ~Animals
** Description: the destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Animals::~Animals(){

}
