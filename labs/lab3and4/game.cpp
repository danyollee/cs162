#include "game.h"
#include "dealer.h"

void Game::playGame(Dealer game_dealer, Deck game_deck){
	int repeat=1, empty=0;
	num_cards=0;
	game_players=createPlayers();
	while(repeat==1){
		for(int i=0; i<num_player; i++){
			for(int j=0; j<num_player; j++){
				if(game_players[i].get_total_moneys()<=0){
					empty++;
				}
			}
			if(empty==num_player){
				cout << "Nobody has money. Cannot play again.\n";
				repeat=0;
				break;
			}
			cout << "\n--------------Player " << (i+1) << " turn--------------\n" << endl;
			game_players[i].print_total_money(i);
			game_players[i].set_round_bet(i);
			num_cards=game_players[i].player_hand.get_player_hand(game_deck, num_cards);
		}
		if(repeat==0){
			break;
		}
		cout << "\n--------------Dealers turn--------------\n" << endl;
		game_dealer.get_dealer_hand(game_deck, num_cards);
		determine_winner(game_dealer);
		cout << "Do you want to go again? (0) for no, (1) for yes: ";
		cin >> repeat;
	}
	cout << "Game over." << endl;
}

Player* Game::createPlayers(){
	cout << "How many players do you have?: ";
	cin >> num_player;
	game_players=new Player[num_player];
	return game_players;
}

void Game::determine_winner(Dealer game_dealer){
	cout << "\n--------------Round Stats--------------\n" << endl;
	cout << "Dealer ended that round with card values totaling to " << game_dealer.get_hand_value() << endl;
	for(int i=0; i<num_player; i++){
		cout << "Player " << (i+1) << " ended that round with card values " << game_players[i].player_hand.get_hand_value() << endl;
	}

	if(game_dealer.get_hand_value()>21){
		for(int i=0; i<num_player; i++){
			if(game_players[i].player_hand.get_hand_value()<21){
				game_players[i].set_moneys_dealer_loss();
			}else if(game_players[i].player_hand.get_hand_value()>21){
				game_players[i].set_moneys_loss();
			}
		}
	}if(game_dealer.get_hand_value()==21){
		cout << "Dealer got blackjack!" << endl;
		for(int i=0; i<num_player; i++){
			if(game_players[i].player_hand.get_hand_value()==21){
				cout << "Player " << (i+1) << " tied with the dealer. They do not lose anything." << endl;
			}else if(game_players[i].player_hand.get_hand_value()<21 || game_players[i].player_hand.get_hand_value()>21){
				cout << "Player " << (i+1) << " loses." << endl;
				game_players[i].set_moneys_loss();
			}
		}
	}if(game_dealer.get_hand_value()<21){
		for(int i=0; i<num_player; i++){
			if(game_players[i].player_hand.get_hand_value()<21 && game_players[i].player_hand.get_hand_value()>game_dealer.get_hand_value()){
				cout << "Player " << (i+1) << " beat the dealer." << endl;
				game_players[i].set_moneys_dealer_loss();
			}if(game_players[i].player_hand.get_hand_value()>21 || game_players[i].player_hand.get_hand_value()<game_dealer.get_hand_value()){
				game_players[i].set_moneys_loss();
			}
		}
	}for(int i=0; i<num_player; i++){
		if(game_players[i].player_hand.get_hand_value()==21 && game_dealer.get_hand_value()!=21){
			game_players[i].blackjack_win();
		}
	}
}

Game::~Game(){
	delete [] game_players;
}