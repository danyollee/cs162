#include <string>
#include "cards2.h"

using namespace std;

class Deck {
private:
	cards *card_deck;
	//Card *fill_cards;

public:
	Deck(){ // Constructor
		//string values[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8" ,"9", "10", "Jack", "Queen", "King"};
		//string suits[4] = {"Diamond", "Hearts", "Clubs", "Spades"};

		card_deck=new cards[52];

		for(int i=0; i<52; i++){
			for(int j=0; j<13; j++){
				card_deck[i].values=card_deck->values.value_of_card[j];
			}		
		}
	}

	void shuffle_cards(){ // Mutator
		int random;
		cards temp_card;
 		cout << endl << "Shuffing deck... " << endl;
 		for(int i=0; i<52; i++){
			random=(rand()%52);
			temp_card=card_deck[i];
			card_deck[i]=card_deck[random];
			card_deck[random]=temp_card;
		}
	}

	/*void print_deck(){ // Accessor
		for(int i=0; i<52; i++){
			cout << card_deck[i].print_card() << endl;
		}
	}*/
};