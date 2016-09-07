#pragma once
#include <iostream>
#include "animal.h"

class Tigers: public Animals{
private:
  int age;
public:
  Tigers();
  int get_tig_age();
  void increment_tig_age();
  void set_ages();
  ~Tigers();
};
