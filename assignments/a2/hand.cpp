#include "hand.h"
#include "deck.h"

Hand::Hand(){
	hand_value=0;
	choice=0;
}

int Hand::get_player_hand(Deck ze_deck, int num_cards){
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
 	return num_cards;
}

void Hand::do_initial_math(Card card1, Card card2, Deck ze_deck, int num_cards){
	hand_value=(atoi(card1.value.c_str())+(atoi(card2.value.c_str())));
	hit_or_stay(ze_deck, num_cards);
}

Card* Hand::print_card(Card* pulled_card){
	string ace, face;
	cin.sync();
	if(pulled_card->value=="Jack" || pulled_card->value=="Queen" || pulled_card->value=="King"){
		cout << "You pulled the " << pulled_card->value << " of " << pulled_card->suit << ". " << endl;
		pulled_card->value="10";
	} else if(pulled_card->value=="Ace"){
		cout << "You pulled an Ace! Would you like it to count as 1 or 11?: ";
		cin >> ace;
		pulled_card->value=ace;
	}else
		cout << "You pulled the " << pulled_card->value << " of " << pulled_card->suit << ". " << endl;
}

void Hand::hit_or_stay(Deck ze_deck, int num_cards){
	cout << "Your total card value is " << hand_value << "." << endl;
	if(hand_value>21){
		cout << "You went over 21.\n" << endl;
		return;
	}
	cout << "Would you like to hit(1) or stay(0)?: ";
	cin >> choice;
	if(choice==0){
		return;
	}
	if(choice==1){
		player_hit(choice, ze_deck, num_cards);
	}
}

int Hand::get_hand_value(){
	return hand_value;
}

void Hand::player_hit(int choice, Deck ze_deck, int num_cards){
	Card temp_card;
	num_cards++;
	temp_card.value=ze_deck.game_deck[num_cards].value;
	temp_card.suit=ze_deck.game_deck[num_cards].suit;
	print_card(&temp_card);
	hand_value=(hand_value+(atoi(temp_card.value.c_str())));
	hit_or_stay(ze_deck, num_cards);
}
