#pragma once
#include <iostream>
#include "animal.h"

class Polarbear: public Animals{
private:
  int age;
  float payout;
public:
  Polarbear();
  int get_pb_age();
  void increment_pb_age();
  void set_ages();
  ~Polarbear();
};
