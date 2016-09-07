#pragma once
#include <iostream>
#include "animal.h"

class Penguins: public Animals{
private:
  int age;
public:
  Penguins();
  int get_penguin_age();
  void increment_penguin_age();
  void set_ages();
  ~Penguins();
};
