#include "deck.h"

Deck::Deck(){
  string values[13]={"Ace", "2", "3", "4", "5", "6", "7", "8" ,"9", "10", "Jack", "Queen", "King"};
  string suits[4]={"Diamond", "Hearts", "Clubs", "Spades"};
  num_cards=52;

  game_deck=new Card[52];
  for(int i=0; i<52; i++){
    game_deck[i].value=values[i%13];
    game_deck[i].suit=suits[i/13];
  }
}

void Deck::shuffle_cards(){
  for(int i=0; i<7; i++){ //Shuffles 7 times because true random
    for(int j=0; j<52; j++){
      int random=(rand()%52);
      Card new_card=game_deck[j];
      game_deck[j]=game_deck[random];
      game_deck[random]=new_card;
    }
  }
}

// Deck::~Deck(){
//   delete [] game_deck;
// }