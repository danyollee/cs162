#include <iostream>
#include <string>

using namespace std;

struct value{
	string value_of_card[13]={"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
};

struct suit{
	string suit_of_card[4]={"Hearts", "Diamonds", "Clubs", "Spades"};
};

struct cards{
	value values;
	suit suits;
};