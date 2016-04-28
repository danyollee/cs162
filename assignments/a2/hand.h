#pragma once
#include "deck.h"
#include "cards.h"

using namespace std;

class Hand{
private:
	int hand_value;
	int choice;
public:
	/*********************************************************************
	** Function: Hand
	** Description: constructs and sets each value to 0
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: private values are now set
	*********************************************************************/ 
	Hand();

	/*********************************************************************
	** Function: get_player_hand
	** Description: picks up the initial 2 cards for the player
	** Parameters: The deck and the ncards
	** Pre-Conditions: player has no cards
	** Post-Conditions: player now has 2 cards
	*********************************************************************/ 
	int get_player_hand(Deck, int);

	/*********************************************************************
	** Function: print_card
	** Description: prints the indivial card that they pulled
	** Parameters: card they pulled
	** Pre-Conditions: None
	** Post-Conditions: puts a value to the card pulled
	*********************************************************************/	
	Card* print_card(Card*);

	/*********************************************************************
	** Function: do_initial_math
	** Description: Adds the two cards up that were initially pulled
	** Parameters: Card1, card2, deck and numcards
	** Pre-Conditions: None
	** Post-Conditions: player now has a hand total
	*********************************************************************/ 
	void do_initial_math(Card, Card, Deck, int);

	/*********************************************************************
	** Function: hit_or_stay
	** Description: automates the player hit or stay gamefunction
	** Parameters: the deck and numcards
	** Pre-Conditions: none
	** Post-Conditions: hits or stays the player
	*********************************************************************/ 
	void hit_or_stay(Deck, int);

	/*********************************************************************
	** Function: get_hand_value
	** Description: just a getter for the hand value
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: returns the hand value
	*********************************************************************/ 
	int get_hand_value();

	/*********************************************************************
	** Function: player_hit
	** Description: pulls a card for the player
	** Parameters: the choice, the deck, numcards
	** Pre-Conditions: none
	** Post-Conditions: pulls a card
	*********************************************************************/ 
	void player_hit(int, Deck, int);

	/*********************************************************************
	** Function: win_or_lose
	** Description: just checks to see if they won
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: a simple print statement
	*********************************************************************/ 
	void win_or_lose();
};