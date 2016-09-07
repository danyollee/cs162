#pragma once
#include <stdlib.h>
#include <ctime>
#include "room.h"
#include "player.h"
#include "event.h"
#include "bats.h"

using namespace std;

class Cave{
private:
  int cave_size, gold_row, gold_col, pit1_row, pit1_col, pit2_row, pit2_col, bat1_row, bat1_col, bat2_row, bat2_col, wump_row, wump_col, start_row, start_col, current_row, current_col, repeat;
  Rooms** game_cave;
  Player Jeremy_Cole;
public:
  Cave();
  Cave(int);
  void welcome();
  void set_game_cave_size();
  void place_rooms();
  void set_player();
  void print_cave();
  void play_the_game();
  void check_spot();
  void check_surroundings();
  void randomize_location();
  void move_Jeremy(int);
  void shoot_arrow();
  void wumpus_moves();
  void repeat_or_nah();
  void repeat_2();

  ~Cave();
};
