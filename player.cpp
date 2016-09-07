#include "player.h"

/*********************************************************************
** Function: Player
** Description: sets all the boolean and arrow values
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all values are set for the game
*********************************************************************/
Player::Player(){
  is_alive=true;
  has_gold=false;
  amount_of_arrows=3;
  has_gold_and_is_back_to_starting_spot=false;
}

/*********************************************************************
** Function: set_repeat
** Description: when it's repeated, it resets all the values
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all values are set for the next round
*********************************************************************/
void Player::set_repeat(){
  is_alive=true;
  has_gold=false;
  amount_of_arrows=3;
  has_gold_and_is_back_to_starting_spot=false;
}

/*********************************************************************
** Function: has_died
** Description: sets the life value to false
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: is_alive is set to dead
*********************************************************************/
void Player::has_died(){
  cout << "Unfortunately Jeremy Cole has died.\n";
  is_alive=false;
}

/*********************************************************************
** Function: set_win_game
** Description: sets the winning bool to true
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: has_gold_and_is_back_to_starting_spot is set to true
*********************************************************************/
void Player::set_win_game(){
  has_gold_and_is_back_to_starting_spot=true;
}

/*********************************************************************
** Function: get_win_game
** Description: returns the winning bool value
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns has_gold_and_is_back_to_starting_spot
*********************************************************************/
bool Player::get_win_game(){
  return has_gold_and_is_back_to_starting_spot;
}

/*********************************************************************
** Function: get_life_status
** Description: return the is_alive boolean
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns is_alive
*********************************************************************/
bool Player::get_life_status(){
  return is_alive;
}

/*********************************************************************
** Function: got_the_gold
** Description: changes the value to true if they get the gold
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: has_gold is changed to true
*********************************************************************/
void Player::got_the_gold(){
  has_gold=true;
}

/*********************************************************************
** Function: get_gold_status
** Description: returns if the user has gold or not
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns has_gold
*********************************************************************/
bool Player::get_gold_status(){
  return has_gold;
}

/*********************************************************************
** Function: used_an_arrow
** Description: decrements the amuont of arrows a player has
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: amount_of_arrows is decremented
*********************************************************************/
void Player::used_an_arrow(){
  amount_of_arrows--;
}

/*********************************************************************
** Function: get_amount_of_arrows
** Description: returns the amount of arrows a player has
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the amount_of_arrows
*********************************************************************/
int Player::get_amount_of_arrows(){
  return amount_of_arrows;
}
