#include <iostream>
#include "zoo.h"
using namespace std;
#include <cstdlib>
#include <ctime>

int main(){
  srand(time(NULL));

  Zoo game_zoo;
  game_zoo.welcome_to_the_game();
  game_zoo.play_the_game();

  return 0;
}
