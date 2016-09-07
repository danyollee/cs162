#include "penguin.h"

/*********************************************************************
** Function: Penguins
** Description: the constructer
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: the age is set to 0
*********************************************************************/
Penguins::Penguins(){
  age=0;
}

/*********************************************************************
** Function: get_penguin_age
** Description: gets the age of the polarbear
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the age value
*********************************************************************/
int Penguins::get_penguin_age(){
  return age;
}

/*********************************************************************
** Function: increment_penguin_age
** Description: increments the age of the polarbear
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: age is +1
*********************************************************************/
void Penguins::increment_penguin_age(){
  age++;
}

/*********************************************************************
** Function: ~Penguins
** Description: the destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Penguins::~Penguins(){
}
