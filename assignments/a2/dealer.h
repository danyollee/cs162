#pragma once
#include "hand.h"
#include "deck.h"

using namespace std;

class Dealer{
private:
	int hand_value;
	int choice;
	int n_cards;
public:

	/*********************************************************************
	** Function: Dealer
	** Description: Constructs and sets the values in private to 0
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: Sets the values above
	*********************************************************************/ 
	Dealer();

	/*********************************************************************
	** Function: get_dealer_hand
	** Description: picks up the initial 2 cards for the dealer
	** Parameters: The deck and the ncards
	** Pre-Conditions: Dealer has no cards
	** Post-Conditions: Dealer now has 2 cards
	*********************************************************************/ 
	int get_dealer_hand(Deck, int); 

	/*********************************************************************
	** Function: do_initial_math
	** Description: Adds the two cards up that were initially pulled
	** Parameters: Card1, card2, deck and numcards
	** Pre-Conditions: None
	** Post-Conditions: Dealer now has a hand total
	*********************************************************************/ 
	void do_initial_math(Card, Card, Deck, int&);

	/*********************************************************************
	** Function: get_num_cards
	** Description: Just returns the ncards
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: returns a private value
	*********************************************************************/ 
	int get_num_cards();

	/*********************************************************************
	** Function: print_card
	** Description: prints the indivial card that they pulled
	** Parameters: card they pulled
	** Pre-Conditions: None
	** Post-Conditions: puts a value to the card pulled
	*********************************************************************/ 
	Card* print_card(Card*);

	/*********************************************************************
	** Function: hit_or_stay
	** Description: automates the dealer hit or stay gamefunction
	** Parameters: the deck and numcards
	** Pre-Conditions: none
	** Post-Conditions: hits or stays the dealer
	*********************************************************************/ 
	int hit_or_stay(Deck, int&);

	/*********************************************************************
	** Function: win_or_lose
	** Description: just checks to see if they won
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: a simple print statement
	*********************************************************************/ 
	void win_or_lose();

	/*********************************************************************
	** Function: get_hand_value
	** Description: just a getter for the hand value
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: returns the hand value
	*********************************************************************/ 
	int get_hand_value();

	/*********************************************************************
	** Function: dealer_hit
	** Description: pulls a card for the dealer
	** Parameters: the choice, the deck, numcards
	** Pre-Conditions: none
	** Post-Conditions: pulls a card
	*********************************************************************/ 
	int dealer_hit(int, Deck, int&);

	/*********************************************************************
	** Function: ~Dealer
	** Description: destructor
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: none
	*********************************************************************/ 
	~Dealer();
};