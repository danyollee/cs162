#include "tiger.h"

/*********************************************************************
** Function: Tigers
** Description: the constructer
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: the age is set to 0
*********************************************************************/
Tigers::Tigers(){
  age=0;
}

/*********************************************************************
** Function: get_tig_age
** Description: gets the age of the tigers
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the age value
*********************************************************************/
int Tigers::get_tig_age(){
  return age;
}

/*********************************************************************
** Function: increment_tig_age
** Description: increments the age of the tigers
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: age is +1
*********************************************************************/
void Tigers::increment_tig_age(){
  age++;
}

/*********************************************************************
** Function: ~Tigers
** Description: the destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Tigers::~Tigers(){
}
