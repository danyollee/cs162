#pragma once
#include "cards.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

class Deck{
private:
	int num_cards;
public:
	Card* game_deck;
	/*********************************************************************
	** Function: Deck
	** Description: Constructs the deck. Assigns values to the struct Card and makes an array.
	** Parameters: None
	** Pre-Conditions: No card deck available
	** Post-Conditions: Creates a deck for the game to use
	*********************************************************************/ 
	Deck();

	/*********************************************************************
	** Function: shuffle_cards
	** Description: Takes the deck and shuffles the cards around 7 times because truley random.
	** Parameters: None
	** Pre-Conditions: The card deck is in order
	** Post-Conditions: The card deck is shuffled
	*********************************************************************/ 
	void shuffle_cards(); 

	/*********************************************************************
	** Function: ~Deck
	** Description: Deconstructs. It deletes the deck of cards
	** Parameters: None
	** Pre-Conditions: There is a card deck
	** Post-Conditions: There is no more card deck
	*********************************************************************/ 
	// ~Deck();
};