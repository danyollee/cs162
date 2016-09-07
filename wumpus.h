#pragma once
#include <iostream>
#include "event.h"

using namespace std;

class Wumpus: public Event{
public:
  void interaction();
};
