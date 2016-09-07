#include "pb.h"

/*********************************************************************
** Function: Polarbear
** Description: the constructer
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: the age is set to 0
*********************************************************************/
Polarbear::Polarbear(){
  age=0;
}

/*********************************************************************
** Function: get_pb_age
** Description: gets the age of the polarbear
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the age value
*********************************************************************/
int Polarbear::get_pb_age(){
  return age;
}

/*********************************************************************
** Function: increment_pb_age
** Description: increments the age of the polarbear
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: age is +1
*********************************************************************/
void Polarbear::increment_pb_age(){
  age++;
}

/*********************************************************************
** Function: ~Polarbear
** Description: the destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Polarbear::~Polarbear(){
}
