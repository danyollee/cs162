#pragma once
#include "deck.h"
#include "player.h"
#include "dealer.h"
#include "hand.h"
#include "cards.h"

using namespace std;

class Game{
private:
	Player* game_players;
	int num_player;
	int num_cards;
public:

	/*********************************************************************
	** Function: Game
	** Description: constructor
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: none
	*********************************************************************/ 
	Game(){}

	/*********************************************************************
	** Function: playGame
	** Description: initializes the actaul game
	** Parameters: The one dealer and the card deck
	** Pre-Conditions: none
	** Post-Conditions: none
	*********************************************************************/ 
	void playGame(Dealer, Deck);

	/*********************************************************************
	** Function: createPlayers
	** Description: creates a dynamic array of players
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: creates an array of players
	*********************************************************************/ 
	Player* createPlayers();

	/*********************************************************************
	** Function: determine winner
	** Description: sorts the scores out and finds the winner of each round
	** Parameters: dealer
	** Pre-Conditions: none
	** Post-Conditions: winner is found. also changes the total amount of money for each player
	*********************************************************************/ 
	void determine_winner(Dealer);

	/*********************************************************************
	** Function: ~Game
	** Description: destructor
	** Parameters: none
	** Pre-Conditions: noen
	** Post-Conditions: deletes the array of players
	*********************************************************************/ 
	~Game();
};