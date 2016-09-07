#pragma once
#include <iostream>

using namespace std;

class Animals{
private:
  int cost_of_tigers, cost_of_penguins, cost_of_pbs, cost_of_emus, cost_to_feed, age;
public:
  Animals();
  int set_born_age();
  int set_bought_age();
  int get_age();
  int increment_age();
  void get_animals_info(int, int, int, int);
  int get_cost_of_tigers();
  int get_cost_of_penguins();
  int get_cost_of_pbs();
  int get_cost_of_emus();
  int get_cost_to_feed_pbs();
  int get_cost_to_feed_tigers();
  int get_cost_to_feed_penguins();
  int get_cost_to_feed_emus();
  int calc_pb_feed_cost(int, int);
  int calc_tig_feed_cost(int, int);
  int calc_peng_feed_cost(int, int);
  void buy_animals();
  ~Animals();
};
