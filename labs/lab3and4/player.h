#pragma once
#include "hand.h"
#include "deck.h"

using namespace std;

class Player{
private:
	int total_money;
	int round_bet;
	int player_number;
public: 
	Hand player_hand;

	/*********************************************************************
	** Function: Player
	** Description: constructs the player and sets the total amount of money
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: total money gets 100
	*********************************************************************/ 
	Player();

	/*********************************************************************
	** Function: Another constructor
	** Description: used to differentiate the players
	** Parameters: i
	** Pre-Conditions: must be called from a for loop
	** Post-Conditions: sets player number
	*********************************************************************/ 
	Player(int);

	/*********************************************************************
	** Function: print_total_money
	** Description:	just prints the total money that that player has
	** Parameters: i
	** Pre-Conditions: i must be called from a for loop
	** Post-Conditions: prints out a statement
	*********************************************************************/ 
	int print_total_money(int);

	/*********************************************************************
	** Function: set_round_bet
	** Description: sets the bet amount for that round
	** Parameters: int i
	** Pre-Conditions: none
	** Post-Conditions: sets the private bet amount
	*********************************************************************/ 
	int set_round_bet(int);

	/*********************************************************************
	** Function: set_moneys_dealer_loss
	** Description: if the player wins, sets the total amount
	** Parameters: none
	** Pre-Conditions: player has to have won
	** Post-Conditions: adds to total amount
	*********************************************************************/ 
	int set_moneys_dealer_loss();

	/*********************************************************************
	** Function: blackjack_win
	** Description: if they player wins, sets the total amount
	** Parameters: none
	** Pre-Conditions: player has to have won
	** Post-Conditions: adds to total amount
	*********************************************************************/ 
	int blackjack_win();

	/*********************************************************************
	** Function: set_money_loss
	** Description: if the player loses, sets the total amount
	** Parameters: none
	** Pre-Conditions: player has to have lost
	** Post-Conditions: subtracts to the total amount
	*********************************************************************/ 
	int set_moneys_loss();

	/*********************************************************************
	** Function: get_total_moneys
	** Description: returns the total money
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: returns the total money
	*********************************************************************/ 
	int get_total_moneys();

	/*********************************************************************
	** Function: get_player_number
	** Description: returns the player number
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: returns the player number
	*********************************************************************/ 
	int get_player_number();
};