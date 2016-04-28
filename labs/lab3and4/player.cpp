#include "player.h"

Player::Player(){
	total_money=100;
}

Player::Player(int i){
	player_number=i;
}

int Player::print_total_money(int i){
	cout << "Player " << (i+1) << " has $" << total_money << "." << endl;
}

int Player::set_round_bet(int i){
	cout << "Player " << (i+1) << ", how much do you want to bet this round? $";
	cin >> round_bet;
	while(round_bet>total_money){
		cout << "You do not have enough. Please enter a new amount to bet: $";
		cin >> round_bet;
	}
}

int Player::set_moneys_dealer_loss(){
	total_money+=round_bet;
}

int Player::blackjack_win(){
	total_money+=(round_bet*1.5);
}

int Player::set_moneys_loss(){
	total_money-=round_bet;
	if(total_money<0)
		total_money=0;
}

int Player::get_total_moneys(){
	return total_money;
}

int Player::get_player_number(){
	player_number++;
	return player_number;
}