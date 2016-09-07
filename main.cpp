/*********************************************************************
** Program Filename: a4.exe
** Author: Daniel Lee
** Date: 5/19/2016
** Description: Plays hunt the wumpus
** Input: none
** Output: none
*********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "room.h"
#include "cave.h"
#include "player.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"

using namespace std;

int main(int argc, char** argv){
  srand(time(NULL));
  int cave_size, repeat=1;

  if(argc!=3){
    cout << "Error, wrong amount of elements. Try again in this format\na4.exe -g (size of a side in the grid)" << endl;
    return 1;
  }

  cave_size=atoi(argv[2]);
  while(cave_size<4){
    cout << "Error, grid not large enough. Each side must be over 4. Try again: ";
    cin >> cave_size;
  }

  Cave game_board(cave_size);
  game_board.welcome();

  return 0;
}
