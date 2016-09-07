#include "emu.h"

/*********************************************************************
** Function: Emus
** Description: the constructer
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sets age to 0
*********************************************************************/
Emus::Emus(){
  age=0;
}

/*********************************************************************
** Function: get_emu_age
** Description: gets the age of the emu
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the age value
*********************************************************************/
int Emus::get_emu_age(){
  return age;
}

/*********************************************************************
** Function: increment_emu_age
** Description: increments the age of the emu
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: age is +1
*********************************************************************/
void Emus::increment_emu_age(){
  age++;
}

/*********************************************************************
** Function: ~Emus
** Description: the destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Emus::~Emus(){
}
