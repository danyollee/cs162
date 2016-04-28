#include <iostream>

using namespace std;

class Card {
private:
	string value; // A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K
	string suit; // 4 of each: Diamond, Heart, Spades, Club

public:
	Card(){}
	Card(string c_value, string c_suit){
		value = c_value;
		suit = c_suit;
	}

	string print_card(){
		return (value + " of " + suit);
	}

};