#pragma once
#include <iostream>

using namespace std;

class Player{
private:
  bool is_alive;
  bool has_gold;
  bool has_gold_and_is_back_to_starting_spot;
  int amount_of_arrows;
public:
  Player();
  void has_died();
  bool get_life_status();
  void set_repeat();
  void got_the_gold();
  bool get_gold_status();
  void used_an_arrow();
  void set_win_game();
  bool get_win_game();
  int get_amount_of_arrows();
};
