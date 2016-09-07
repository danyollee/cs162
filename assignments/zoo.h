#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "animal.h"
#include "pb.h"
#include "penguin.h"
#include "tiger.h"
#include "emu.h"

using namespace std;

class Zoo{
private:
  int zoo_budget, amount_to_buy, age_of_bought, day, repeat, pb_counter, tig_counter, penguin_counter, emu_counter, amount_to_feed, bonus, amount_that_starved;
  Polarbear* game_polarbears;
  Polarbear* temp;
  Penguins* game_penguins;
  Penguins* penguin_temp;
  Tigers* game_tigers;
  Tigers* tig_temp;
  Emus* game_emus;
  Emus* temp_emu;
public:
  Animals game_animals;
  Zoo();
  void welcome_to_the_game();
  void play_the_game();
  int get_zoo_budget();
  void buy_animals();
  void buy_pb();
  void set_pb();
  void set_emus();
  void buy_tigers();
  void buy_emus();
  void set_tigers();
  void buy_penguins();
  void set_penguins();
  void set_zoo_budget();
  int another_day();
  void set_ages();
  void get_ages();
  void feed_animals();
  void start_rand_event();
  void animal_gets_sick();
  void pb_dies_from_starvation();
  void tig_dies_from_starvation();
  void penguin_dies_from_starvation();
  void emu_dies_from_starvation();
  void increase_day();
  int set_moneys();
  void all_pb_dies();
  void all_tigers_die();
  void all_emus_die();
  void all_penguins_die();
  void animal_is_born(int);
  int calc_payout();
  int calc_pb_death_cost();
  int calc_tig_death_cost();
  int calc_peng_death_cost();
  int calc_emu_death_cost();
  int calc_tig_bonus();
  ~Zoo();
};
