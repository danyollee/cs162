#pragma once
#include <iostream>
#include "animal.h"

class Emus: public Animals{
private:
  int age;
public:
  Emus();
  int get_emu_age();
  void increment_emu_age();
  void set_ages();
  ~Emus();
};
