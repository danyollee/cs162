#pragma once
#include <iostream>
#include "event.h"
#include "bats.h"
#include "pit.h"
#include "wumpus.h"
#include "gold.h"

using namespace std;

class Rooms{
private:
  bool has_gold;
  bool has_pit;
  bool has_bats;
  bool has_wumpus;
  bool has_player;
  Bats superbats;
  Pit bottomless_pit;
  Wumpus wumpus;
  Gold game_gold;
public:
  Event* event;
  Rooms();
  void set_gold();
  void set_pit();
  void set_bats();
  void interbat();
  void interpit();
  void intergold();
  void interwump();
  void set_wumpus();
  void wumpus_leaves();
  void wumpus_has_died();
  void set_player();
  void player_leaves();
  bool get_gold();
  bool get_pit();
  bool get_bats();
  bool get_wumpus();
  bool get_player();
};
