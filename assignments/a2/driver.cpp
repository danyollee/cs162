/*********************************************************************
** Program Filename: a2.cpp
** Author: Daniel Lee
** Date: 4/24/2016
** Description: Plays the game blackjack
** Input: Game inputs
** Output: Blackjack game
*********************************************************************/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "dealer.h"
#include "deck.h"
#include "hand.h"
#include "game.h"

using namespace std;

int main(){
  srand(time(NULL));
  Deck ze_deck;
  Dealer game_dealer;
  int repeat=1;

  ze_deck.shuffle_cards();

	while(repeat==1){
		Game blackjack;
		blackjack.playGame(game_dealer, ze_deck);
		cout << "Do you want to play again? (1) for yes and (0) for no: ";
		cin >> repeat;
		if(repeat==0){
			cout << "Okay, thanks for playing my blackjack game!\n";
		}
	}

  return 0;
}