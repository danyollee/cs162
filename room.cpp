#include "room.h"

/*********************************************************************
** Function: Rooms
** Description: constructs the room class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sets all the values to false
*********************************************************************/
Rooms::Rooms(){
  has_gold=false;
  has_pit=false;
  has_gold=false;
  has_wumpus=false;
  has_player=false;
}

/*********************************************************************
** Function: set_gold
** Description: sets the gold in a room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sets the room to have gold
*********************************************************************/
void Rooms::set_gold(){
  event=&game_gold;
  has_gold=true;
}

/*********************************************************************
** Function: set_pit
** Description: sets the pit in a room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sets the room to have a pit
*********************************************************************/
void Rooms::set_pit(){
  event=&bottomless_pit;
  has_pit=true;
}

/*********************************************************************
** Function: interpit
** Description: calls the polymorphic function
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: calls the interaction function
*********************************************************************/
void Rooms::interpit(){
  event->interaction();
}

/*********************************************************************
** Function: set_bats
** Description: sets the bats in a room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sets the room to have bats
*********************************************************************/
void Rooms::set_bats(){
  event=&superbats;
  has_bats=true;
}

/*********************************************************************
** Function: interbat
** Description: calls the polymorphic function
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: calls the interaction function
*********************************************************************/
void Rooms::interbat(){
  event->interaction();
}

/*********************************************************************
** Function: intergold
** Description: calls the polymorphic function
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: calls the interaction function
*********************************************************************/
void Rooms::intergold(){
  event->interaction();
}

/*********************************************************************
** Function: set_wumpus
** Description: sets the wumpus in a room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sets the room to have wumpus
*********************************************************************/
void Rooms::set_wumpus(){
  event=&wumpus;
  has_wumpus=true;
}

/*********************************************************************
** Function: wumpus_leaves
** Description: sets the wumpus bool to false when it moves around
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the room does not have a wumpus anymore
*********************************************************************/
void Rooms::wumpus_leaves(){
  has_wumpus=false;
}

/*********************************************************************
** Function: interwump
** Description: calls the polymorphic function
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: calls the interaction function
*********************************************************************/
void Rooms::interwump(){
  event->interaction();
}

/*********************************************************************
** Function: wumpus_has_died
** Description: sets the wumpus to false
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the wumpus is not in the room anymore
*********************************************************************/
void Rooms::wumpus_has_died(){
  has_wumpus=false;
}

/*********************************************************************
** Function: set_player
** Description: sets the player in a room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sets the room to have player
*********************************************************************/
void Rooms::set_player(){
  has_player=true;
}

/*********************************************************************
** Function: player_leaves
** Description: sets the player bool false if they leave
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sets the player to false in that room
*********************************************************************/
void Rooms::player_leaves(){
  has_player=false;
}

/*********************************************************************
** Function: get_gold
** Description: returns the bool values
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns has_gold
*********************************************************************/
bool Rooms::get_gold(){
  return has_gold;
}

/*********************************************************************
** Function: get_pit
** Description: returns the bool values
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns get_pit
*********************************************************************/
bool Rooms::get_pit(){
  return has_pit;
}

/*********************************************************************
** Function: get_bats
** Description: returns the bool values
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns has_bats
*********************************************************************/
bool Rooms::get_bats(){
  return has_bats;
}

/*********************************************************************
** Function: get_wumpus
** Description: returns the bool values
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns has_wumpus
*********************************************************************/
bool Rooms::get_wumpus(){
  return has_wumpus;
}

/*********************************************************************
** Function: get_player
** Description: returns the bool values
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns has_player
*********************************************************************/
bool Rooms::get_player(){
  return has_player;
}
