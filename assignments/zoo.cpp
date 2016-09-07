/******************************************************
** Program: zoo.cpp
** Author: Daniel Lee
** Date: 05/08/2016
** Description: Plays zoo tycoon
** Input: None
** Output: None
******************************************************/
#include "zoo.h"

/*********************************************************************
** Function: Zoo constructer
** Description: Sets all the values that will be used later in the game
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Sets all the values to the correct starting amount
*********************************************************************/
Zoo::Zoo(){
  amount_to_buy=0;
  zoo_budget=100000;
  day=-1;
  repeat=1;
  pb_counter=0;
  tig_counter=0;
  emu_counter=0;
  penguin_counter=0;
  amount_to_feed=0;
}

/*********************************************************************
** Function: welcome_to_the_game
** Description: Introduces the user to the game. Just asthetic stuff
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Zoo::welcome_to_the_game(){
  cout << "\n****************************** Welcome! ******************************" << endl;
  cout << "You are in charge of a zoo with 4 types of animals.\nYou have tigers, polar bears, penguins, and emus.\nYour starting budget is $" << zoo_budget << ". The cost to feed each animal is \nPolar bears: $" << game_animals.get_cost_to_feed_pbs() << "\nTigers: $" << game_animals.get_cost_to_feed_tigers() << "\nEmus: $" << game_animals.get_cost_to_feed_emus() << "\n**************************** Play wisely! ****************************\n" << endl;
}

/*********************************************************************
** Function: The main controller for the game
** Description: Calls all the functions that will run the game
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Plays the game
*********************************************************************/
void Zoo::play_the_game(){
  while(repeat==1){
    increase_day();
    get_ages();
    get_zoo_budget();
    if(day>0){
      feed_animals();
      start_rand_event();
      zoo_budget=set_moneys();
    }
    set_ages();
    game_animals.get_animals_info(pb_counter, tig_counter, penguin_counter, emu_counter);
    buy_animals();
    another_day();
    system("clear");
  }
  cout << "Thanks for playing!" << endl;
}

/*********************************************************************
** Function: set_moneys
** Description: gives the days earnings and sets the budget from the payout
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: changes the zoo budget to the correct amount
*********************************************************************/
int Zoo::set_moneys(){
  cout << "\nThe days earnings is $" << calc_payout() << ".\n\n";
  zoo_budget+=calc_payout();
  return zoo_budget;
}

/*********************************************************************
** Function: buy_animals
** Description: starts the purchasing of animals
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: changes the array size for each animal
*********************************************************************/
void Zoo::buy_animals(){
  buy_pb();
  buy_tigers();
  buy_penguins();
  buy_emus();
}

/*********************************************************************
** Function: increase_day
** Description: increases the day of the game.
** Parameters: none
** Pre-Conditions: day must be an int
** Post-Conditions: the day is increased by one
*********************************************************************/
void Zoo::increase_day(){
  day++;
  cout << "******************** It is now day " << day << " ********************" << endl;
}

/*********************************************************************
** Function: get_zoo_budget
** Description: prints out the zoo budget as well as the cost for each animal and basic stats at the start of the round
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Zoo::get_zoo_budget(){
  if(zoo_budget<=0){
    cout << "GAME OVER. Your zoo budget went under $0.\n";
    exit(1);
  }
  cout << "Your zoo budget is $" << zoo_budget << ".\n";
  cout << "Polar bears cost $" << game_animals.get_cost_to_feed_pbs() << " each to feed. You have " << pb_counter << " Polar bears.\n";
  cout << "Tigers cost $" << game_animals.get_cost_to_feed_tigers() << " each to feed. You have " << tig_counter << " tigers.\n";
  cout << "Penguins cost $" << game_animals.get_cost_to_feed_penguins() << " each to feed. You have " << penguin_counter << " penguins.\n";
  cout << "Emus cost $" << game_animals.get_cost_to_feed_emus() << " each to feed. You have " << emu_counter << " emus.\n";
}

/*********************************************************************
** Function: buy_pb
** Description: purchases a polar bear
** Parameters: none
** Pre-Conditions: none
** Post-Conditions:a polarbear is appended to the array. the zoo budget also decreases too
*********************************************************************/
void Zoo::buy_pb(){
  if(day==0){
    cout << "How many polar bears do you want to buy? (Up to 2): ";
    cin >> amount_to_buy;
    while(amount_to_buy<0 || amount_to_buy>2){
      cout << "Error, not a valid amount. Try again: ";
      cin >> amount_to_buy;
      }
    if(amount_to_buy>0){
      set_pb();
      zoo_budget=zoo_budget-(game_animals.get_cost_of_pbs()*amount_to_buy);
    }
  }
  if(day>0){
    cout << "Do you want to buy a polar bear? (0) for no or (1) for yes: ";
    cin >> amount_to_buy;
    while(amount_to_buy<0 || amount_to_buy>1){
      cout << "Error, not a valid choice. Try again: ";
      cin >> amount_to_buy;
    }
    if(amount_to_buy>0){
      set_pb();
      zoo_budget=zoo_budget-(game_animals.get_cost_of_pbs()*amount_to_buy);
    }
  }
  amount_to_buy=0;
}

/*********************************************************************
** Function: buy_penguins
** Description: purchases penguins
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: adds a penguin to the array, also changes the zoo budget correctly
*********************************************************************/
void Zoo::buy_penguins(){
  if(day==0){
    cout << "How many penguins do you want to buy? (Up to 2): ";
    cin >> amount_to_buy;
    while(amount_to_buy<0 || amount_to_buy>2){
      cout << "Error, not a valid amount. Try again: ";
      cin >> amount_to_buy;
    }
    if(amount_to_buy>0){
      set_penguins();
      zoo_budget=zoo_budget-(game_animals.get_cost_of_penguins()*amount_to_buy);
    }
  }
  if(day>0){
    cout << "Do you want to buy a penguin? (0) for no or (1) for yes: ";
    cin >> amount_to_buy;
    while(amount_to_buy<0 || amount_to_buy>1){
      cout << "Error, not a valid choice. Try again: ";
      cin >> amount_to_buy;
    }
    if(amount_to_buy>0){
      set_penguins();
      zoo_budget=zoo_budget-(game_animals.get_cost_of_pbs()*amount_to_buy);
    }
  }
  amount_to_buy=0;
}

/*********************************************************************
** Function: buy_tigers
** Description: purchases a tiger
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: adds a tiger to the array, as well as changes the zoo budget
*********************************************************************/
void Zoo::buy_tigers(){
  if(day==0){
    cout << "How many tigers do you want to buy? (Up to 2): ";
    cin >> amount_to_buy;
    while(amount_to_buy<0 || amount_to_buy>2){
      cout << "Error, not a valid amount. Try again: ";
      cin >> amount_to_buy;
    }
    if(amount_to_buy>0){
      set_tigers();
      zoo_budget=zoo_budget-(game_animals.get_cost_of_tigers()*amount_to_buy);
    }
    if(amount_to_buy==0){
    }
  }
  if(day>0){
    cout << "Do you want to buy a tiger? (0) for no or (1) for yes: ";
    cin >> amount_to_buy;
    while(amount_to_buy<0 || amount_to_buy>1){
      cout << "Error, not a valid choice. Try again: ";
      cin >> amount_to_buy;
    }
    if(amount_to_buy>0){
      set_tigers();
      zoo_budget=zoo_budget-(game_animals.get_cost_of_tigers()*amount_to_buy);
    }
  }
  amount_to_buy=0;
}

/*********************************************************************
** Function: buy_emus
** Description: purchases an emu
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: adds an emu to the array, as well as correctly adjusts the zoo budget
*********************************************************************/
void Zoo::buy_emus(){
  if(day==0){
    cout << "How many emus do you want to buy? (Up to 2): ";
    cin >> amount_to_buy;
    while(amount_to_buy<0 || amount_to_buy>2){
      cout << "Error, not a valid choice. Try again: ";
      cin >> amount_to_buy;
    }
    if(amount_to_buy>0){
      set_emus();
      zoo_budget=zoo_budget-(game_animals.get_cost_of_emus()*amount_to_buy);
    }
    if(amount_to_buy==0){
    }
  }
  if(day>0){
    cout << "Do you want to buy an emu? (0) for no or (1) for yes: ";
    cin >> amount_to_buy;
    while(amount_to_buy<0 || amount_to_buy>1){
      cout << "Error, not a valid choice. Try again: ";
      cin >> amount_to_buy;
    }
    if(amount_to_buy>0){
      set_emus();
      zoo_budget=zoo_budget-(game_animals.get_cost_of_emus()*amount_to_buy);
    }
  }
  amount_to_buy=0;
}

/*********************************************************************
** Function: set_pb
** Description: actually adds the polarbear to the array
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: adds the polarbear to the array
*********************************************************************/
void Zoo::set_pb(){
  if(pb_counter==0){
    game_polarbears=new Polarbear[amount_to_buy];
    for(int i=0; i<amount_to_buy; i++){
      game_polarbears[i].set_bought_age();
    }
  }
  else if(pb_counter>0){
    temp=new Polarbear[pb_counter+amount_to_buy];
    for(int i=0; i<pb_counter; i++){
      temp[i]=game_polarbears[i];
    }
    delete [] game_polarbears;
    game_polarbears=temp;
    for(int i=0; i<pb_counter+amount_to_buy; i++){
      if(i>=pb_counter){
        game_polarbears[i].set_bought_age();
      }
    }
  }
    pb_counter+=amount_to_buy;
}

/*********************************************************************
** Function: set_emus
** Description: actually adds the emu to the array
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: array is appended
*********************************************************************/
void Zoo::set_emus(){
  if(emu_counter==0){
    game_emus=new Emus[amount_to_buy];
    for(int i=0; i<amount_to_buy; i++){
      game_emus[i].set_bought_age();
    }
  }
  else if(pb_counter>0){
    temp_emu=new Emus[emu_counter+amount_to_buy];
    for(int i=0; i<emu_counter; i++){
      temp_emu[i]=game_emus[i];
    }
    delete [] game_emus;
    game_emus=temp_emu;
    for(int i=0; i<emu_counter+amount_to_buy; i++){
      if(i>=emu_counter){
        game_emus[i].set_bought_age();
      }
    }
  }
  emu_counter+=amount_to_buy;
}

/*********************************************************************
** Function: set_tigers
** Description: actually adds the tigers to the array
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the tiger array is appended
*********************************************************************/
void Zoo::set_tigers(){
  if(tig_counter==0){
    game_tigers=new Tigers[amount_to_buy];
    for(int i=0; i<amount_to_buy; i++){
      game_tigers[i].set_bought_age();
    }
  }
  else if(tig_counter>0){
    tig_temp=new Tigers[tig_counter+amount_to_buy];
    for(int i=0; i<tig_counter; i++){
      tig_temp[i]=game_tigers[i];
    }
    delete [] game_tigers;
    game_tigers=tig_temp;
    for(int i=0; i<(tig_counter+amount_to_buy); i++){
      if(i>=tig_counter){
        game_tigers[i].set_bought_age();
      }
    }
  }
  tig_counter+=amount_to_buy;
}

/*********************************************************************
** Function: set_penguins
** Description: actually adds the penguins to the array
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: array is appended
*********************************************************************/
void Zoo::set_penguins(){
  if(penguin_counter==0){
    game_penguins=new Penguins[amount_to_buy];
    for(int i=0; i<amount_to_buy; i++){
      game_penguins[i].set_bought_age();
    }
  }
  else if(penguin_counter>0){
    penguin_temp=new Penguins[penguin_counter+amount_to_buy];
    for(int i=0; i<penguin_counter; i++){
      penguin_temp[i]=game_penguins[i];
    }
    delete [] game_penguins;
    game_penguins=penguin_temp;
    for(int i=0; i<(penguin_counter+amount_to_buy); i++){
      if(i>=penguin_counter){
        game_penguins[i].set_bought_age();
      }
    }
  }
  penguin_counter+=amount_to_buy;
}

/*********************************************************************
** Function: another_day
** Description: asks user if they want to continue another day
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: another day will occur
*********************************************************************/
int Zoo::another_day(){
  cout << "\nDo you want to play another day? (1) for yes and (0) for no: ";
  cin >> repeat;
  while(repeat<0 || repeat>1){
    cout << "Error, not a valid choice. Try again: ";
    cin >> repeat;
  }
  return repeat;
}

/*********************************************************************
** Function: set_ages
** Description: increments the age of each animal
** Parameters: none
** Pre-Conditions: there must be at least 1 of each animal
** Post-Conditions: each animal is a day older
*********************************************************************/
void Zoo::set_ages(){
  for(int i=0; i<pb_counter; i++){
    game_polarbears[i].increment_age();
  }
  for(int i=0; i<tig_counter; i++){
    game_tigers[i].increment_age();
  }
  for(int i=0; i<penguin_counter; i++){
    game_penguins[i].increment_age();
  }
}

/*********************************************************************
** Function: get_ages
** Description: gets the ages of all available animals
** Parameters: none
** Pre-Conditions: the day must be greater than 0
** Post-Conditions: prints out the ages of all the animals
*********************************************************************/
void Zoo::get_ages(){
  cout << endl << "******************** AGES_OF_ANIMALS ********************\n";
  for(int i=0; i<pb_counter; i++){
    cout << "The age of Polar bear " << (i+1) << " is " << game_polarbears[i].get_age() << " days old." << endl;
  }
  cout << endl;
  for(int i=0; i<tig_counter; i++){
    cout << "The age of tiger " << (i+1) << " is " << game_tigers[i].get_age() << " days old." << endl;
  }
  cout << endl;
  for(int i=0; i<penguin_counter; i++){
    cout << "The age of penguin " << (i+1) << " is " << game_penguins[i].get_age() << " days old." << endl;
  }
  cout << endl;
  for(int i=0; i<emu_counter; i++){
    cout << "The age of emu " << (i+1) << " is " << game_emus[i].get_age() << " days old." << endl;
  }
  cout << "*********************************************************\n";
}

/*********************************************************************
** Function: feed_animals
** Description: gets user choice to feed animals or not
** Parameters: none
** Pre-Conditions: there must be at least one of each animal
** Post-Conditions: each animal is fed and none die
*********************************************************************/
void Zoo::feed_animals(){
  int feed_choice;
  cout << "The total cost to feed your animals is $" << ((tig_counter*game_animals.get_cost_to_feed_tigers())+(pb_counter*game_animals.get_cost_to_feed_pbs())+(penguin_counter*game_animals.get_cost_to_feed_penguins())+emu_counter*game_animals.get_cost_to_feed_emus()) << ". You currently have $" << zoo_budget << ". Do you want to feed your animals? (1) for yes and (0) for no: ";
  cin >> feed_choice;
  if(feed_choice==0){
    cout << "\nAll your animals died because you did not feed them.\n";
    if(pb_counter==0){
    }else if(pb_counter>0){
      pb_counter=0;
      all_pb_dies();
    }if(tig_counter==0){
    }else if(tig_counter>0){
      tig_counter=0;
      all_tigers_die();
    }if(penguin_counter==0){
    }if(penguin_counter>0){
      penguin_counter=0;
      all_penguins_die();
    }if(emu_counter==0){
    }else if(emu_counter>0){
      emu_counter=0;
      all_emus_die();
    }
  }if(feed_choice==1){
    if(zoo_budget>((tig_counter*game_animals.get_cost_to_feed_tigers())+(pb_counter*game_animals.get_cost_to_feed_pbs())+(penguin_counter*game_animals.get_cost_to_feed_penguins()))){
      zoo_budget=zoo_budget-((tig_counter*game_animals.get_cost_to_feed_tigers())+(pb_counter*game_animals.get_cost_to_feed_pbs())+(penguin_counter*game_animals.get_cost_to_feed_penguins()));
      cout << "Your animals are well fed.";
    }if(zoo_budget<((tig_counter*game_animals.get_cost_to_feed_tigers())+(pb_counter*game_animals.get_cost_to_feed_pbs())+(penguin_counter*game_animals.get_cost_to_feed_penguins()))){
      cout << "Not enough to feed all your animals. All will die except for 1 of each.\n";
      amount_to_feed=1;
      pb_dies_from_starvation();
      amount_to_feed=0;
      amount_to_feed=1;
      tig_dies_from_starvation();
      amount_to_feed=0;
      amount_to_feed=1;
      penguin_dies_from_starvation();
      amount_to_feed=0;
    }
  }
}

/*********************************************************************
** Function: start_rand_event
** Description: gets the choice of the random event that will occur
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: 4 options can occur
*********************************************************************/
void Zoo::start_rand_event(){
  int babychoice=0, rand_event;

  cout << "\n\nA random event has occured!\nThe random event is...\n";
  rand_event=rand()%4;
  if(rand_event==0) //random sickness occurs
    animal_gets_sick();
  else if(rand_event==1){ //boom in attendance
    bonus=251+(rand()%250);
    cout << "\nA boom in attendance! Tigers attracted $" << bonus << " in extra payoff!\n\n";
    zoo_budget=calc_tig_bonus();
  }
  else if(rand_event==2){
    if(pb_counter==0 && tig_counter==0 && penguin_counter==0 && emu_counter==0){
      cout << "Nothing! You got lucky!\n";
      return;
    }else if(pb_counter>0 || tig_counter>0 || penguin_counter>0 || emu_counter>0)
    cout << "Babies are born! Do you want the baby to be of ";
    if(pb_counter>0){
      cout << "Polar bears(0), ";
    }if(tig_counter>0){
      cout << "tigers(1), ";
    }if(penguin_counter>0){
      cout << "penguins(2), ";
    }if(emu_counter>0){
      cout << "or emus(3)?: ";
    }
    cin >> babychoice;
    animal_is_born(babychoice);
  }
  else if(rand_event==3){
    cout << "Nothing! You got lucky!\n";
  }
}

/*********************************************************************
** Function: animal_is_born
** Description: adds animals to the array if they are born
** Parameters: babychoice(from start_rand_event)
** Pre-Conditions: none
** Post-Conditions: whatever the user chooses, the array is appended
*********************************************************************/
void Zoo::animal_is_born(int babychoice){
  while(babychoice<0 || babychoice>3){
    cout << "Error, not a valid choice. Try again: ";
    cin >> babychoice;
  }
  if(babychoice==0){
      if(pb_counter>0){
      pb_counter+=2;
      temp=new Polarbear[pb_counter];
      for(int i=0; i<pb_counter-2; i++){
        temp[i]=game_polarbears[i];
      }
      delete [] game_polarbears;
      game_polarbears=temp;
      for(int i=0; i<pb_counter; i++){
        if(i>=(pb_counter-2)){
          game_polarbears[i].set_born_age();
        }
      }
    }
  }
  if(babychoice==1){
    tig_counter++;
    tig_temp=new Tigers[tig_counter];
    for(int i=0; i<tig_counter-1; i++){
      tig_temp[i]=game_tigers[i];
    }
    delete [] game_tigers;
    game_tigers=tig_temp;
    for(int i=0; i<tig_counter; i++){
      if(i>=tig_counter-1){
        game_tigers[i].set_born_age();
      }
    }
  }
  if(babychoice==2){
    penguin_counter=penguin_counter+3;
    penguin_temp=new Penguins[penguin_counter];
    for(int i=0; i<penguin_counter-3; i++){
      penguin_temp[i]=game_penguins[i];
    }
    delete [] game_penguins;
    game_penguins=penguin_temp;
    for(int i=0; i<penguin_counter; i++){
      if(i>=penguin_counter-3){
        game_penguins[i].set_born_age();
      }
    }
  }
  if(babychoice==3){
    emu_counter=emu_counter+2;
    temp_emu=new Emus[emu_counter];
    for(int i=0; i<emu_counter-2; i++){
      temp_emu[i]=game_emus[i];
    }
    delete [] game_emus;
    game_emus=temp_emu;
    for(int i=0; i<emu_counter; i++){
      if(i>=emu_counter-2){
        game_emus[i].set_born_age();
      }
    }
  }
}

/*********************************************************************
** Function: animal_gets_sick
** Description: an animal gets sick and dies
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: user array is decreased by one
*********************************************************************/
void Zoo::animal_gets_sick(){
  if(pb_counter==0 && penguin_counter==0 && tig_counter==0 && emu_counter==0){
    cout << "Nothing! You got lucky!\n";
  }if(pb_counter>0 || penguin_counter>0 || tig_counter>0 || emu_counter>0){
    int temp_choice=0;
    cout << "Unfortunately an animal got sick. But you get to choose which one dies. Do you want it to be ";
    if(pb_counter>0){
      cout << "a Polar bear(0), ";
    }if(tig_counter>0){
      cout << "a tiger(1), ";
    }if(penguin_counter>0){
      cout << "a penguin(2), ";
    }if(emu_counter>0){
      cout << "or an emu(3)?: ";
    }
    cin >> temp_choice;
    while(temp_choice<0 || temp_choice>3){
      cout << "Error, not valid. Try again: ";
      cin >> temp_choice;
    }
    if(temp_choice==0){
      amount_to_feed=1;
      pb_dies_from_starvation();
      cout << "A Polar bear has died.\n";
    }
    if(temp_choice==1){
      amount_to_feed=1;
      tig_dies_from_starvation();
      cout << "A tiger has died.\n";
    }
    if(temp_choice==2){
      amount_to_feed=1;
      penguin_dies_from_starvation();
      cout << "A penguin has died.\n";
    }
    if(temp_choice==3){
      amount_to_feed=1;
      emu_dies_from_starvation();
      cout << "An emu has died.\n";
    }
  }
}

/*********************************************************************
** Function: pb_dies_from_starvation
** Description: a polarbear dies
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: array is 1 less and zoo budget is altered
*********************************************************************/
void Zoo::pb_dies_from_starvation(){
  if(pb_counter==0){
    delete [] game_polarbears;
  }else if(pb_counter==1){
    pb_counter--;
    delete [] game_polarbears;
  }else{
    pb_counter--;
  }
  zoo_budget=calc_pb_death_cost();

}

/*********************************************************************
** Function: all_pb_dies
** Description: deletes the array of polar bears
** Parameters: none
** Pre-Conditions: it must be an array
** Post-Conditions: deletes the array
*********************************************************************/
void Zoo::all_pb_dies(){
  delete [] game_polarbears;
}

/*********************************************************************
** Function: all_penguins_die
** Description: deletes the array of penguins
** Parameters: none
** Pre-Conditions: it must be an array
** Post-Conditions: deletes the array
*********************************************************************/
void Zoo::all_penguins_die(){
  delete [] game_penguins;
}

/*********************************************************************
** Function: all_tigers_die
** Description: deletes the array of tigers
** Parameters: none
** Pre-Conditions: it must be an array
** Post-Conditions: deletes the array
*********************************************************************/
void Zoo::all_tigers_die(){
  delete [] game_tigers;
}

/*********************************************************************
** Function: all_emus_die
** Description: deletes the array of emus
** Parameters: none
** Pre-Conditions: it must be an array
** Post-Conditions: deletes the array
*********************************************************************/
void Zoo::all_emus_die(){
  delete [] game_emus;
}

/*********************************************************************
** Function: tig_dies_from_starvation
** Description: tiger dies
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: tiger array decreased and zoo budget is adjusted
*********************************************************************/
void Zoo::tig_dies_from_starvation(){
  int amount_that_starved=tig_counter-amount_to_feed;
  if(tig_counter==0){
    delete [] game_tigers;
  }else if(tig_counter==1){
    tig_counter--;
    delete [] game_tigers;
  }else{
    tig_counter--;
  }
  zoo_budget=calc_tig_death_cost();
}

/*********************************************************************
** Function: penguin_dies_from_starvation
** Description: a penguin dies
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: penguin array is 1 less and zoo budget is changed
*********************************************************************/
void Zoo::penguin_dies_from_starvation(){
  int amount_that_starved=penguin_counter-amount_to_feed;
  penguin_temp=new Penguins[penguin_counter];
  penguin_temp=game_penguins;
  delete [] game_penguins;
  penguin_counter-=amount_to_feed;
  game_penguins=new Penguins[penguin_counter];
  for(int i=0; i<penguin_counter; i++){
    game_penguins[i]=penguin_temp[i];
  }
  zoo_budget=calc_peng_death_cost();
}

/*********************************************************************
** Function: emu_dies_from_starvation
** Description: an emu dies
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: emu array is 1 less and zoo budget is adjusted accordingly
*********************************************************************/
void Zoo::emu_dies_from_starvation(){
  int amount_that_starved=emu_counter-amount_to_feed;
  temp_emu=new Emus[emu_counter];
  temp_emu=game_emus;
  delete [] game_emus;
  emu_counter-=amount_to_feed;
  game_emus=new Emus[emu_counter];
  for(int i=0; i<emu_counter; i++){
    game_emus[i]=temp_emu[i];
  }
  zoo_budget=calc_emu_death_cost();
}

/*********************************************************************
** Function: calc_payout
** Description: calculates the total payout for all the animals
** Parameters: the zoo_budget, the counters for each animal and all the animal arrays
** Pre-Conditions: none
** Post-Conditions: zoo_budget is altered
*********************************************************************/
int Zoo::calc_payout(){
  int payout=0;
  if(pb_counter>0){
    for(int i=0; i<pb_counter; i++){
      if(game_polarbears[i].get_age()<=3){
        payout+=(2*((game_animals.get_cost_of_pbs())*.05));
      }
      else if(game_polarbears[i].get_age()>3){
        payout+=((game_animals.get_cost_of_pbs())*.05);
      }
    }
  }

  if(tig_counter>0){
    for(int i=0; i<tig_counter; i++){
      if(game_tigers[i].get_age()<=3){
        payout+=(2*((game_animals.get_cost_of_tigers())*.1));
      }else if(game_tigers[i].get_age()>3){
        payout+=((game_animals.get_cost_of_tigers())*.1);
      }
    }
  }

  if(penguin_counter>0){
    for(int i=0; i<penguin_counter; i++){
      if(game_penguins[i].get_age()<=3){
        payout+=(2*((game_animals.get_cost_of_penguins())*.05));
      }else if(game_penguins[i].get_age()>3){
        payout+=((game_animals.get_cost_of_penguins())*.05);
      }
    }
  }

  if(emu_counter>0){
    for(int i=0; i<emu_counter; i++){
      if(game_emus[i].get_age()<=3){
        payout+=(2*((game_animals.get_cost_of_emus())*.9));
      }else if(game_emus[i].get_age()>3){
        payout+=((game_animals.get_cost_of_emus())*.9);
      }
    }
  }
  return payout;
}

/*********************************************************************
** Function: calc_pb_death_cost
** Description: alters the zoo budget if polarbears die
** Parameters: zoo_budget and the amount that starved
** Pre-Conditions: none
** Post-Conditions: just changes the zoo budget
*********************************************************************/
int Zoo::calc_pb_death_cost(){
  for(int i=0; i<pb_counter; i++){
    if(game_polarbears[i].get_age()<=3){
      zoo_budget=zoo_budget-(2*(amount_that_starved*game_animals.get_cost_of_pbs()));
    }else if(game_polarbears[i].get_age()>3){
      zoo_budget=zoo_budget-(amount_that_starved*game_animals.get_cost_of_pbs());
    }
  }
  return zoo_budget;
}

/*********************************************************************
** Function: calc_tig_death_cost
** Description: alters the zoo budget if tigers die
** Parameters: zoo_budget and the amount that starved
** Pre-Conditions: none
** Post-Conditions: just changes the zoo_budget
*********************************************************************/
int Zoo::calc_tig_death_cost(){
  for(int i=0; i<tig_counter; i++){
    if(game_tigers[i].get_age()<=3){
      zoo_budget=zoo_budget-(2*(amount_that_starved*game_animals.get_cost_of_tigers()));
    }
    else if(game_tigers[i].get_age()>3){
      zoo_budget=zoo_budget-(amount_that_starved*game_animals.get_cost_of_tigers());
    }
  }
  return zoo_budget;
}

/*********************************************************************
** Function: calc_peng_death_cost
** Description: alters the zoo budget if penguins die
** Parameters: zoo budget and the amount that starved
** Pre-Conditions: none
** Post-Conditions: alters the zoo_budget
*********************************************************************/
int Zoo::calc_peng_death_cost(){
  for(int i=0; i<penguin_counter; i++){
    if(game_penguins[i].get_age()<=3){
      zoo_budget=zoo_budget-(2*(amount_that_starved*game_animals.get_cost_of_penguins()));
    }else if(game_penguins[i].get_age()>3){
      zoo_budget=zoo_budget-(amount_that_starved*game_animals.get_cost_of_penguins());
    }
  }
  return zoo_budget;
}

/*********************************************************************
** Function: calc_emu_death_cost
** Description: alters the zoo budget if emus die
** Parameters: zoo_budget and the amount that starved
** Pre-Conditions: none
** Post-Conditions: alters the zoo budget
*********************************************************************/
int Zoo::calc_emu_death_cost(){
  for(int i=0; i<emu_counter; i++){
    if(game_emus[i].get_emu_age()<=3){
      zoo_budget=zoo_budget-(2*(amount_that_starved*game_animals.get_cost_of_emus()));
    }else if(game_emus[i].get_emu_age()>3){
      zoo_budget=zoo_budget-(amount_that_starved*game_animals.get_cost_of_emus());
    }
  }
}

/*********************************************************************
** Function: calc_tig_bonus
** Description: alters the zoo_budget for the tiger bonus
** Parameters: the zoo_budget, the amount of tigers and the actual bonus amount
** Pre-Conditions: none
** Post-Conditions: the zoo_budget is altered
*********************************************************************/
int Zoo::calc_tig_bonus(){
  if(tig_counter==0){
    cout << "No tigers so no bonus!" << endl;
    return zoo_budget;
  }
  zoo_budget+=(((game_animals.get_cost_of_tigers()*.1)*tig_counter))+bonus;
  cout << "The tiger bonus was $" << (game_animals.get_cost_of_tigers()*.1)*tig_counter+bonus << endl;
  return zoo_budget;
}

/*********************************************************************
** Function: ~Zoo
** Description: deletes the arrays
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: everything is deleted
*********************************************************************/
Zoo::~Zoo(){
  if(pb_counter!=0)
    delete [] game_polarbears;
  if(penguin_counter!=0)
    delete [] game_penguins;
  if(tig_counter!=0)
    delete [] game_tigers;
  if(emu_counter!=0)
    delete [] game_emus;
}
