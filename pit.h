#pragma once
#include <iostream>
#include "event.h"

using namespace std;

class Pit: public Event{
public:
  void interaction();
};
