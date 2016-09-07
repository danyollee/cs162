#include "cave.h"

Cave::Cave(){
}

/*********************************************************************
** Function: Cave
** Description: the copy constructor for the cave. creates the cave
** Parameters: cave_size, from the command line
** Pre-Conditions: cave_size must be geater than 4 and an int
** Post-Conditions: a grid has been created with type rooms
*********************************************************************/
Cave::Cave(int cave_size){
  this->cave_size=cave_size;
  game_cave=new Rooms*[cave_size];
  for(int i=0; i<cave_size; i++){
    game_cave[i]=new Rooms[cave_size];
  }
}

/*********************************************************************
** Function: Welcome
** Description: introduces the player to the game and is a stepping stone for the rest of the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Cave::welcome(){
  cout << "************************************************" << endl;
  cout << "*                                              *" << endl;
  cout << "*          Welcome to Hunt the Wumpus!         *" << endl;
  cout << "*                Good luck!                    *" << endl;
  cout << "*                                              *" << endl;
  cout << "*                                              *" << endl;
  cout << "************************************************" << endl;

  place_rooms();
}

/*********************************************************************
** Function: place_rooms
** Description: places the different types of rooms within the cave. it just changes the boolean values
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Cave::place_rooms(){
  gold_row=rand()%cave_size;
  gold_col=rand()%cave_size;
  game_cave[gold_row][gold_col].set_gold();

  pit1_row=rand()%cave_size;
  pit1_col=rand()%cave_size;
  while(game_cave[pit1_row][pit1_col].get_gold()==true || game_cave[pit1_row][pit1_col].get_pit()==true || game_cave[pit1_row][pit1_col].get_bats()==true || game_cave[pit1_row][pit1_col].get_wumpus()==true){
    pit1_row=rand()%cave_size;
    pit1_col=rand()%cave_size;
  }
  game_cave[pit1_row][pit1_col].set_pit();

  pit2_row=rand()%cave_size;
  pit2_col=rand()%cave_size;
  while(game_cave[pit2_row][pit2_col].get_gold()==true || game_cave[pit2_row][pit2_col].get_pit()==true || game_cave[pit2_row][pit2_col].get_bats()==true || game_cave[pit2_row][pit2_col].get_wumpus()==true){
    pit2_row=rand()%cave_size;
    pit2_col=rand()%cave_size;
  }
  game_cave[pit2_row][pit2_col].set_pit();


  bat1_row=rand()%cave_size;
  bat1_col=rand()%cave_size;
  while(game_cave[bat1_row][bat1_col].get_gold()==true || game_cave[bat1_row][bat1_col].get_pit()==true || game_cave[bat1_row][bat1_col].get_bats()==true || game_cave[bat1_row][bat1_col].get_wumpus()==true){
    bat1_row=rand()%cave_size;
    bat1_col=rand()%cave_size;
  }
  game_cave[bat1_row][bat1_col].set_bats();

  bat2_row=rand()%cave_size;
  bat2_col=rand()%cave_size;
  while(game_cave[bat2_row][bat2_col].get_gold()==true || game_cave[bat2_row][bat2_col].get_pit()==true || game_cave[bat2_row][bat2_col].get_bats()==true || game_cave[bat2_row][bat2_col].get_wumpus()==true){
    bat2_row=rand()%cave_size;
    bat2_col=rand()%cave_size;
  }
  game_cave[bat2_row][bat2_col].set_bats();

  wump_row=rand()%cave_size;
  wump_col=rand()%cave_size;
  while(game_cave[wump_row][wump_col].get_gold()==true || game_cave[wump_row][wump_col].get_pit()==true || game_cave[wump_row][wump_col].get_bats()==true || game_cave[wump_row][wump_col].get_wumpus()==true){
    wump_row=rand()%cave_size;
    wump_col=rand()%cave_size;
  }
  game_cave[wump_row][wump_col].set_wumpus();

  set_player();
}

/*********************************************************************
** Function: set_player
** Description: sets the location of the Player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: a player is no set in the cave.
*********************************************************************/
void Cave::set_player(){
  start_row=rand()%cave_size;
  start_col=rand()%cave_size;
  while(game_cave[start_row][start_col].get_gold()==true || game_cave[start_row][start_col].get_pit()==true || game_cave[start_row][start_col].get_bats()==true || game_cave[start_row][start_col].get_wumpus()==true){
    start_row=rand()%cave_size;
    start_col=rand()%cave_size;
  }
  current_row=start_row;
  current_col=start_col;
  game_cave[start_row][start_col].set_player();

  print_cave();
  check_surroundings();
  play_the_game();
}

/*********************************************************************
** Function: print_cave
** Description: prints the cave, but only the location of the player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Cave::print_cave(){
  cout << "Starting point!" << endl;
  for(int i=0; i<cave_size; i++){
    for(int j=0; j<cave_size; j++){
      if(game_cave[i][j].get_player()==true){
        cout << "J ";
      }
      // else if(game_cave[i][j].get_pit()==true){
      //   cout << "P ";
      // }
      // else if(game_cave[i][j].get_bats()==true){
      //   cout << "B ";
      // }
      // else if(game_cave[i][j].get_wumpus()==true){
      //   cout << "W ";
      // }
      // else if(game_cave[i][j].get_gold()==true){
      //   cout << "G ";
      // }
      else{
        cout << "O ";
      }
    }
    cout << endl;
  }
}

/*********************************************************************
** Function: play_the_game
** Description: is the parent function to run the whole game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the game is played
*********************************************************************/
void Cave::play_the_game(){
  int choice, move_choice;
  while(Jeremy_Cole.get_life_status()==true && Jeremy_Cole.get_win_game()==false){
    cout << "Does Jeremy Cole want to\n(1) Move\n(2) Shoot an arrow\nChoice: ";
    cin >> choice;
    while(choice<1 || choice>2){
      cout << "Error, not valid. Try again: ";
      cin >> choice;
    }
    if(choice==1){
      cout << "Which direction does Jeremy Cole want to move?\n(1) To move left\n(2) To move right\n(3) To move up\n(4) To move down\nChoice: ";
      cin >> move_choice;
      move_Jeremy(move_choice);
    }else if(choice==2){
      shoot_arrow();
    }
    if(Jeremy_Cole.get_amount_of_arrows()==0){
      Jeremy_Cole.has_died();
    }
    check_spot();
    check_surroundings();
  }
  repeat_or_nah();
}

/*********************************************************************
** Function: check_surroundings
** Description: checks the surrounding areas of the player to check to see where the rooms are
** Parameters: none
** Pre-Conditions: none.
** Post-Conditions: percepts are printed IF there are rooms near
*********************************************************************/
void Cave::check_surroundings(){
  int counter=0;
  cout << "******************Message Box******************\n";
  if(current_col==0 && current_row>0 && current_row<(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_bats()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_bats()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_bats()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole hears wings flapping.     *\n";
    }
  }

  if(current_col==0 && current_row==0){
    if(game_cave[current_row][current_col+1].get_bats()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_bats()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole hears wings flapping.     *\n";
    }
  }

  if(current_col==0 && current_row==(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_bats()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_bats()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole hears wings flapping.     *\n";
    }
  }

  if(current_row==(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_bats()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_bats()==true){
      counter++;
    }if(game_cave[current_row-1][current_col].get_bats()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole hears wings flapping.     *\n";
    }
  }

  if(current_col==(cave_size-1) && current_row==(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_bats()==true){
      counter++;
    }if(game_cave[current_row][current_col-1].get_bats()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole hears wings flapping.     *\n";
    }
  }

  if(current_row==0 && current_col==(cave_size-1)){
    if(game_cave[current_row][current_col-1].get_bats()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_bats()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole hears wings flapping.     *\n";
    }
  }

  if(current_row==0 && current_col>0 && current_col<(cave_size-1)){
    if(game_cave[current_row][current_col-1].get_bats()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_bats()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_bats()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole hears wings flapping.     *\n";
    }
  }

  if(current_row>0 && current_row<(cave_size-1) && current_col==(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_bats()==true){
      counter++;
    }if(game_cave[current_row][current_col-1].get_bats()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_bats()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole hears wings flapping.     *\n";
    }
  }

  if(current_row>0 && current_row<(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
    if(game_cave[current_row][current_col-1].get_bats()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_bats()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_bats()==true){
      counter++;
    }if(game_cave[current_row-1][current_col].get_bats()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole hears wings flapping.     *\n";
    }
  }
  counter=0;

  //This checks for pits
  if(current_col==0 && current_row>0 && current_row<(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_pit()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_pit()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_pit()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*         Jeremy Cole feels a breeze.        *\n";
    }
  }

  if(current_col==0 && current_row==0){
    if(game_cave[current_row][current_col+1].get_pit()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_pit()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*         Jeremy Cole feels a breeze.        *\n";
    }
  }

  if(current_col==0 && current_row==(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_pit()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_pit()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*         Jeremy Cole feels a breeze.        *\n";
    }
  }

  if(current_row==(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_pit()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_pit()==true){
      counter++;
    }if(game_cave[current_row-1][current_col].get_pit()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*         Jeremy Cole feels a breeze.        *\n";
    }
  }

  if(current_col==(cave_size-1) && current_row==(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_pit()==true){
      counter++;
    }if(game_cave[current_row][current_col-1].get_pit()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*         Jeremy Cole feels a breeze.        *\n";
    }
  }

  if(current_row==0 && current_col==(cave_size-1)){
    if(game_cave[current_row][current_col-1].get_pit()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_pit()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*         Jeremy Cole feels a breeze.        *\n";
    }
  }

  if(current_row==0 && current_col>0 && current_col<(cave_size-1)){
    if(game_cave[current_row][current_col-1].get_pit()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_pit()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_pit()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*         Jeremy Cole feels a breeze.        *\n";
    }
  }

  if(current_row>0 && current_row<(cave_size-1) && current_col==(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_pit()==true){
      counter++;
    }if(game_cave[current_row][current_col-1].get_pit()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_pit()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*         Jeremy Cole feels a breeze.        *\n";
    }
  }

  if(current_row>0 && current_row<(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
    if(game_cave[current_row][current_col-1].get_pit()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_pit()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_pit()==true){
      counter++;
    }if(game_cave[current_row-1][current_col].get_pit()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*         Jeremy Cole feels a breeze.        *\n";
    }
  }
  counter=0;

  //This checks for the wumpus
  if(current_col==0 && current_row>0 && current_row<(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_wumpus()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*     Jeremy Cole smells a stinky stench.    *\n";
    }
  }

  if(current_col==0 && current_row==0){
    if(game_cave[current_row][current_col+1].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_wumpus()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*     Jeremy Cole smells a stinky stench.    *\n";
    }
  }

  if(current_col==0 && current_row==(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_wumpus()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*     Jeremy Cole smells a stinky stench.    *\n";
    }
  }

  if(current_row==(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row-1][current_col].get_wumpus()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*     Jeremy Cole smells a stinky stench.    *\n";
    }
  }

  if(current_col==(cave_size-1) && current_row==(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row][current_col-1].get_wumpus()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*     Jeremy Cole smells a stinky stench.    *\n";
    }
  }

  if(current_row==0 && current_col==(cave_size-1)){
    if(game_cave[current_row][current_col-1].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_wumpus()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*     Jeremy Cole smells a stinky stench.    *\n";
    }
  }

  if(current_row==0 && current_col>0 && current_col<(cave_size-1)){
    if(game_cave[current_row][current_col-1].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_wumpus()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*     Jeremy Cole smells a stinky stench.    *\n";
    }
  }

  if(current_row>0 && current_row<(cave_size-1) && current_col==(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row][current_col-1].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_wumpus()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*     Jeremy Cole smells a stinky stench.    *\n";
    }
  }

  if(current_row>0 && current_row<(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
    if(game_cave[current_row][current_col-1].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_wumpus()==true){
      counter++;
    }if(game_cave[current_row-1][current_col].get_wumpus()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*     Jeremy Cole smells a stinky stench.    *\n";
    }
  }
  counter=0;

  //This checks for the gold
  if(current_col==0 && current_row>0 && current_row<(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_gold()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_gold()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_gold()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole sees a glimmer nearby.    *\n";
    }
  }

  if(current_col==0 && current_row==0){
    if(game_cave[current_row][current_col+1].get_gold()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_gold()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole sees a glimmer nearby.    *\n";
    }
  }

  if(current_col==0 && current_row==(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_gold()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_gold()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole sees a glimmer nearby.    *\n";
    }
  }

  if(current_row==(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_gold()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_gold()==true){
      counter++;
    }if(game_cave[current_row-1][current_col].get_gold()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole sees a glimmer nearby.    *\n";
    }
  }

  if(current_col==(cave_size-1) && current_row==(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_gold()==true){
      counter++;
    }if(game_cave[current_row][current_col-1].get_gold()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole sees a glimmer nearby.    *\n";
    }
  }

  if(current_row==0 && current_col==(cave_size-1)){
    if(game_cave[current_row][current_col-1].get_gold()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_gold()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole sees a glimmer nearby.    *\n";
    }
  }

  if(current_row==0 && current_col>0 && current_col<(cave_size-1)){
    if(game_cave[current_row][current_col-1].get_gold()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_gold()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_gold()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole sees a glimmer nearby.    *\n";
    }
  }

  if(current_row>0 && current_row<(cave_size-1) && current_col==(cave_size-1)){
    if(game_cave[current_row-1][current_col].get_gold()==true){
      counter++;
    }if(game_cave[current_row][current_col-1].get_gold()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_gold()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole sees a glimmer nearby.    *\n";
    }
  }

  if(current_row>0 && current_row<(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
    if(game_cave[current_row][current_col-1].get_gold()==true){
      counter++;
    }if(game_cave[current_row+1][current_col].get_gold()==true){
      counter++;
    }if(game_cave[current_row][current_col+1].get_gold()==true){
      counter++;
    }if(game_cave[current_row-1][current_col].get_gold()==true){
      counter++;
    }
    for(int i=0; i<counter; i++){
      cout << "*      Jeremy Cole sees a glimmer nearby.    *\n";
    }
  }
  counter=0;

  cout << "***********************************************\n";
}

/*********************************************************************
** Function: check_spot
** Description: checks the current spot of the player to see if they died/got gold or anything like that
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: changes the boolean values, MAYBE
*********************************************************************/
void Cave::check_spot(){
  cout << endl;
  if(Jeremy_Cole.get_amount_of_arrows()==0){
    Jeremy_Cole.has_died();
  }
  else if(game_cave[current_row][current_col].get_player()==game_cave[current_row][current_col].get_bats()){
    game_cave[current_row][current_col].interbat();
    randomize_location();
  }
  else if(game_cave[current_row][current_col].get_player()==game_cave[current_row][current_col].get_pit()){
    game_cave[current_row][current_col].interpit();
    Jeremy_Cole.has_died();
  }
  else if(game_cave[current_row][current_col].get_player()==game_cave[current_row][current_col].get_wumpus()){
    game_cave[current_row][current_col].interwump();
    Jeremy_Cole.has_died();
  }
  else if(game_cave[current_row][current_col].get_player()==game_cave[current_row][current_col].get_gold()){
    game_cave[current_row][current_col].intergold();
    Jeremy_Cole.got_the_gold();
  }
  if(Jeremy_Cole.get_gold_status()==true && current_row==start_row && current_col==start_col){
    cout << "Jeremy Cole won the game!! Congratulations!\n\n";
    Jeremy_Cole.set_win_game();
  }
}

/*********************************************************************
** Function: repeat_or_nah
** Description: sets the option to repeat or quit the game.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: either repeats the game with the same, or differnet cave. or quits the whole game.
*********************************************************************/
void Cave::repeat_or_nah(){
  cout << "\nDoes Jeremy Cole want to\n(1) Repeat the game with the same map?\n(2) Repeat the game with a different map?\n(3) Quit entirely\nChoice: ";
  cin >> repeat;
  while(repeat<1 || repeat>3){
    cout << "Error, not a valid choice. Try again: ";
    cin >> repeat;
  }
  if(repeat==1){
    Jeremy_Cole.set_repeat();
    for(int i=0; i<cave_size; i++){
      for(int j=0; j<cave_size; j++){
        game_cave[i][j].player_leaves();
      }
    }
    set_player();
  }
  if(repeat==2){
    Jeremy_Cole.set_repeat();
    repeat_2();
  }
  if(repeat==3){
    cout << "Thanks for playing my game!\n";
  }
}

/*********************************************************************
** Function: randomize_location
** Description: changes the location of the player if they hit bats
** Parameters: none
** Pre-Conditions: must have encountered bats
** Post-Conditions: moves the player
*********************************************************************/
void Cave::randomize_location(){
  game_cave[current_row][current_col].player_leaves();
  current_row=rand()%cave_size;
  current_col=rand()%cave_size;
  while(game_cave[current_row][current_col].get_gold()==true || game_cave[current_row][current_col].get_pit()==true || game_cave[current_row][current_col].get_bats()==true || game_cave[current_row][current_col].get_wumpus()==true){
    current_row=rand()%cave_size;
    current_col=rand()%cave_size;
  }
  game_cave[current_row][current_col].set_player();
}

/*********************************************************************
** Function: move_Jeremy
** Description: moves jeremy left, down, up, or right
** Parameters: move_choice, which is the direction that they want to go
** Pre-Conditions: none
** Post-Conditions: moves jeremy in a direction
*********************************************************************/
void Cave::move_Jeremy(int move_choice){
  while(move_choice==1 && current_col==0 || move_choice==3 && current_row==0 || move_choice==4 && current_row==(cave_size-1) || move_choice==2 && current_col==(cave_size-1)){
    cout << "Error, Jeremy Cole is at the edge of the cave and cannot go that direction. Choose a different direction: ";
    cin >> move_choice;
  }
  if(move_choice==1){
    game_cave[current_row][current_col].player_leaves();
    current_col--;
    game_cave[current_row][current_col].set_player();
  }
  if(move_choice==2){
    game_cave[current_row][current_col].player_leaves();
    current_col++;
    game_cave[current_row][current_col].set_player();
  }
  if(move_choice==3){
    game_cave[current_row][current_col].player_leaves();
    current_row--;
    game_cave[current_row][current_col].set_player();
  }
  if(move_choice==4){
    game_cave[current_row][current_col].player_leaves();
    current_row++;
    game_cave[current_row][current_col].set_player();
  }
}

/*********************************************************************
** Function: shoot_arrow
** Description: shoots an arrow
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the wumpus might die
*********************************************************************/
void Cave::shoot_arrow(){
  int arrow_choice, wumpus_might_wake_up;
  bool hit_or_naw=false, wumpus_is_around=false;
  wumpus_might_wake_up=rand()%4;

  cout << "Jeremy Cole chose to shoot an arrow. Which direction do Jeremy Cole want to shoot it?\n(1) Shoot left\n(2) Shoot right\n(3) Shoot up\n(4) Shoot down\nChoice: ";
  cin >> arrow_choice;
  if(arrow_choice==1){
    for(int i=1; i<=3; i++){
      if(current_col==0){
        cout << "Jeremy Cole shot directly into a wall. What a waste of an arrow.\n";
        break;
      }
      if(game_cave[current_row][current_col-i].get_wumpus()==true){
        cout << "Jeremy Cole hit the wumpus and it has died!! ";
        hit_or_naw=true;
        game_cave[current_row][current_col-i].wumpus_has_died();
        break;
      }else if(current_col-i==0){
        break;
      }
    }
    if(hit_or_naw==false){
      if(current_col==0 && current_row>0 && current_row<(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_col==0 && current_row==0){
        if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_col==0 && current_row==(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row==(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_col==(cave_size-1) && current_row==(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row==0 && current_col==(cave_size-1)){
        if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row==0 && current_col>0 && current_col<(cave_size-1)){
        if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row>0 && current_row<(cave_size-1) && current_col==(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row>0 && current_row<(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
        if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }
    }
  }

  if(arrow_choice==2){
    for(int i=1; i<=3; i++){
      if(current_col==(cave_size-1)){
        cout << "Jeremy Cole shot directly into a wall. What a waste of an arrow.\n";
        break;
      }
      if(game_cave[current_row][current_col+i].get_wumpus()==true){
        cout << "Jeremy Cole hit the wumpus and it has died!! ";
        hit_or_naw=true;
        game_cave[current_row][current_col+i].wumpus_has_died();
        break;
      }else if(current_col+i==0){
        break;
      }
    }
    if(hit_or_naw==false){
      if(current_col==0 && current_row>0 && current_row<(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_col==0 && current_row==0){
        if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_col==0 && current_row==(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row==(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_col==(cave_size-1) && current_row==(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row==0 && current_col==(cave_size-1)){
        if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row==0 && current_col>0 && current_col<(cave_size-1)){
        if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row>0 && current_row<(cave_size-1) && current_col==(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row>0 && current_row<(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
        if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }
    }
  }

  if(arrow_choice==3){
    for(int i=1; i<=3; i++){
      if(current_row==0){
        cout << "Jeremy Cole shot directly into the wall. What a waste of an arrow.\n";
        break;
      }
      if(game_cave[current_row-i][current_col].get_wumpus()==true){
        cout << "Jeremy Cole hit the wumpus and it has died!! ";
        hit_or_naw=true;
        game_cave[current_row-i][current_col].wumpus_has_died();
        break;
      }else if(current_row-i==0){
        break;
      }
    }
    if(hit_or_naw==false){
      if(current_col==0 && current_row>0 && current_row<(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_col==0 && current_row==0){
        if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_col==0 && current_row==(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row==(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_col==(cave_size-1) && current_row==(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row==0 && current_col==(cave_size-1)){
        if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row==0 && current_col>0 && current_col<(cave_size-1)){
        if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row>0 && current_row<(cave_size-1) && current_col==(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row>0 && current_row<(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
        if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }
    }
  }

  if(arrow_choice==4){
    for(int i=1; i<=3; i++){
      if(current_row==(cave_size-1)){
        cout << "Jeremy Cole shot directly into the wall. What a waste of an arrow.\n";
        break;
      }
      if(game_cave[current_row+i][current_col].get_wumpus()==true){
        cout << "Jeremy Cole hit the wumpus and it has died!! ";
        hit_or_naw=true;
        game_cave[current_row+i][current_col].wumpus_has_died();
        break;
      }else if(current_row+i==(cave_size-1)){
        break;
      }
    }
    if(hit_or_naw==false){
      if(current_col==0 && current_row>0 && current_row<(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_col==0 && current_row==0){
        if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_col==0 && current_row==(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row==(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_col==(cave_size-1) && current_row==(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row==0 && current_col==(cave_size-1)){
        if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row==0 && current_col>0 && current_col<(cave_size-1)){
        if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row>0 && current_row<(cave_size-1) && current_col==(cave_size-1)){
        if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }

      if(current_row>0 && current_row<(cave_size-1) && current_col>0 && current_col<(cave_size-1)){
        if(game_cave[current_row][current_col-1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row+1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row][current_col+1].get_wumpus()==true){
          wumpus_is_around=true;
        }if(game_cave[current_row-1][current_col].get_wumpus()==true){
          wumpus_is_around=true;
        }
        if(wumpus_is_around==true){
          if(wumpus_might_wake_up>=0 && wumpus_might_wake_up<=2){
            cout << "The Wumpus has heard the shot! ";
            wumpus_moves();
            cout << "The Wumpus has moved away. \n";
          }
          if(wumpus_might_wake_up==3){
            cout << "The wumpus did not hear the shot of the arrow. It stays in it's room.\n";
          }
        }
      }
    }
  }
  Jeremy_Cole.used_an_arrow();
  cout << "Jeremy Cole has " << Jeremy_Cole.get_amount_of_arrows() << " arrows left." << endl;
}

/*********************************************************************
** Function: wumpus_moves
** Description: moves the wumpus to a random spot
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: wumpus moves to a random location
*********************************************************************/
void Cave::wumpus_moves(){
  game_cave[wump_row][wump_col].wumpus_leaves();
  wump_row=rand()%cave_size;
  wump_col=rand()%cave_size;
  while(game_cave[wump_row][wump_col].get_gold()==true || game_cave[wump_row][wump_col].get_pit()==true || game_cave[wump_row][wump_col].get_bats()==true || game_cave[wump_row][wump_col].get_wumpus()==true){
    wump_row=rand()%cave_size;
    wump_col=rand()%cave_size;
  }
  game_cave[wump_row][wump_col].set_wumpus();
  cout << "Wumpus is now at " << wump_row << " and " << wump_col << "." << endl;
}

/*********************************************************************
** Function: repeat_2
** Description: gets ready for the next thing
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: deletes and creates an array
*********************************************************************/
void Cave::repeat_2(){
  for(int i=0; i<cave_size; i++){
    delete [] game_cave[i];
    }
  delete [] game_cave;

  game_cave=new Rooms*[cave_size];
  for(int i=0; i<cave_size; i++){
    game_cave[i]=new Rooms[cave_size];
  }

  welcome();
}

/*********************************************************************
** Function: ~Cave
** Description: deletes the array
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: deletes the array
*********************************************************************/
Cave::~Cave(){
  for(int i=0; i<cave_size; i++){
    delete [] game_cave[i];
    }
  delete [] game_cave;
}
