#include "dealer.h"

Dealer::Dealer(){
	hand_value=0;
	choice=0;
}

int Dealer::get_dealer_hand(Deck ze_deck, int num_cards){
 	Card card1, card2;

 	card1.value=ze_deck.game_deck[num_cards].value;
 	card1.suit=ze_deck.game_deck[num_cards].suit;
 	print_card(&card1);
 	num_cards++;

 	card2.value=ze_deck.game_deck[num_cards].value;
 	card2.suit=ze_deck.game_deck[num_cards].suit;
 	print_card(&card2);
 	num_cards++;
 	do_initial_math(card1, card2, ze_deck, num_cards);
 	n_cards = num_cards;
}

void Dealer::do_initial_math(Card card1, Card card2, Deck ze_deck, int &num_cards){
	hand_value=(atoi(card1.value.c_str())+(atoi(card2.value.c_str())));
	hit_or_stay(ze_deck, num_cards);
}

int Dealer::get_num_cards() {
	return n_cards;
}

Card* Dealer::print_card(Card* pulled_card){
	string ace, face;
	if(pulled_card->value=="Jack" || pulled_card->value=="Queen" || pulled_card->value=="King"){
		cout << "Dealer pulled the " << pulled_card->value << " of " << pulled_card->suit << ". " << endl;
		pulled_card->value="10";
	}else if(pulled_card->value=="Ace"){
		if(hand_value>=11){
			ace="1";
			cout << "Dealer pulled an Ace! Dealer chooses it to be 1." << endl;
			pulled_card->value=ace;
		}if(hand_value<=10){
			ace="11";
			cout << "Dealer pulled an Ace! Dealer chooses it to be 11." << endl;
			pulled_card->value=ace;
		}
	}else
		cout << "Dealer pulled the " << pulled_card->value << " of " << pulled_card->suit << ". " << endl;
}

int Dealer::hit_or_stay(Deck ze_deck, int &num_cards){
	cout << endl << "Dealer total card value is " << hand_value << "." << endl;
	win_or_lose();
	if(hand_value>21){
		cout << "Dealer went over 21, he loses." << endl;
	}if(hand_value>0 && hand_value<17){
		cout << "Dealer chooses to hit." << endl;
		dealer_hit(choice, ze_deck, num_cards);
	}if(hand_value>17 && hand_value<21){
		hand_value=hand_value;
	}
}

void Dealer::win_or_lose(){
	if(hand_value==21){
		cout << "Dealer wins!" << endl;

	}if(hand_value<21){
		return;
	}
}

int Dealer::get_hand_value(){
	return hand_value;
}

int Dealer::dealer_hit(int choice, Deck ze_deck, int &num_cards){
	Card temp_card;
	num_cards++;
	temp_card.value=ze_deck.game_deck[num_cards].value;
	temp_card.suit=ze_deck.game_deck[num_cards].suit;
	print_card(&temp_card);
	hand_value=(hand_value+(atoi(temp_card.value.c_str())));
	hit_or_stay(ze_deck, num_cards);
}

Dealer::~Dealer(){
	
}