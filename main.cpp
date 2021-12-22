#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include <map>

using namespace std;

void makeRooms(vector<Room*> &r);

int main(){

  map<int, Room> hauntedhouse;
  vector<Room*> r;
  char a[10000];
  bool cont = true;
  bool checkdirection = false;

  bool spoonInv = false; // if the items are not in your inventory, its false
  bool forkInv = false;
  bool knifeInv = false;
  bool chopsticksInv = false;
  bool sporkInv = false;
  
  // an entrance
  // a grand hall
  // the ability to move between the 2

  makeRooms(r);

  int locationval = 0;
  
  vector<Room*>::iterator it;
  
  cout << "Welcome to Zuul. You are in a haunted house. ooooohhh spooky!" << endl;
  cout << "" << endl;
  cout << "Your job is to collect the legendary utensil set: the spoon, the fork, the knife, the chopsticks, and the spork." << endl;
  cout << "" << endl;
  cout << "Why?" << endl;
  cout << "..." << endl;
  cout << "I don't know actually, just go get them." << endl;
  cout << "" << endl;
  cout << "" << endl;
  
  while (cont == true){
  checkdirection = false;

    while (checkdirection == false) {


    for (int i = 0; i < r.size(); i++){
      if (i == locationval){
	cout << r[i]->getDescription() << endl;
	cout << "" << endl;
	cout << "Objects in the room: ";
        if (r[i]->hasSpoon == true){
	  cout << "SPOON ";
	}
	if (r[i]->hasKnife == true){
	  cout << "KNIFE ";
	}
	if (r[i]->hasFork == true){
	  cout << "FORK ";
	}
	if (r[i]->hasChopsticks == true){
	  cout << "CHOPSTICKS ";
	}
	if (r[i]->hasSpork == true){
	  cout << "SPORK ";
	}
      }
    }

    cout << "What do you do? (GO, GET, DROP, INVENTORY, QUIT)" << endl;

    cout << "Available directions: ";

    if (r[locationval]->exitN == true){
      cout << "NORTH ";
    }
    if (r[locationval]->exitS == true){
      cout << "SOUTH ";
    }
    if (r[locationval]->exitE == true){
      cout << "EAST ";
    }
    if (r[locationval]->exitW == true){
      cout << "WEST ";
    }
    cout << "" << endl;

    cin >> a;    

    if (strcmp(a, "GO") == 0) {

      cout << "Go where?" << endl;

      cin >> a;
      
      if (strcmp(a, "NORTH") == 0){ // north]
	if (r[locationval]->exitN == false){
	  cout << "invalid direction!" << endl;
	}
	else if (r[locationval]->exitN == true) {

	  if (r[locationval]->roomID == 0){ // entrance
	    locationval = 1;
	  }
	  else if (r[locationval]->roomID == 1){ // grandhall
	    locationval = 4;
	  }
	  else if (r[locationval]->roomID == 4){ // dining
	    locationval = 7;
	  }
	  else if (r[locationval]->roomID == 7){ // den
	    locationval = 8;
	  }
	  else if (r[locationval]->roomID == 11){ // hallway
	    locationval = 12;
	  }
	  else if (r[locationval]->roomID == 14){ // laundry
	    locationval = 11;
	  }
	  checkdirection = true;
	}
      }
      else if (strcmp(a, "SOUTH") == 0){ // south
	if (r[locationval]->exitS == false){
	  cout << "invalid direction!" << endl;
	}
	else if (r[locationval]->exitS == true) {
	  if (r[locationval]->roomID == 1){ // grandhall
	    locationval = 0;
	  }
	  else if (r[locationval]->roomID == 4){ // dining
	    locationval = 1;
	  }
	  else if (r[locationval]->roomID == 7){ // den
	    locationval = 4;
	  }
	  else if (r[locationval]->roomID == 8){ // backyard
	    locationval = 7;
	  } 
	  else if (r[locationval]->roomID == 12){ // recroom
	    locationval = 11;
	  }
	  else if (r[locationval]->roomID == 11){ // hallway
	    locationval = 14;
	  }
					
	  checkdirection = true;
	}
      }
      else if (strcmp(a, "EAST") == 0){ // east
	if (r[locationval]->exitE == false){
	  cout << "invalid direction!" << endl;
	}
	else if (r[locationval]->exitE == true) {
	  if (r[locationval]->roomID == 1){ // grandhall
	    locationval = 2;
	  }
	  else if (r[locationval]->roomID == 4){ // dining
	    locationval = 5;
	  }
	  else if (r[locationval]->roomID == 3){ // lavatory
	    locationval = 1;
	  }
	  else if (r[locationval]->roomID == 6){ // kitchen
	    locationval = 4;
	  }
	  else if (r[locationval]->roomID == 8){ // backyard
	    locationval = 9;
	  }
	  else if (r[locationval]->roomID == 10){ // stairs
	    locationval = 7;
	  }
	  else if (r[locationval]->roomID == 11){ // hallway
	    locationval = 10;
	  }
	  else if (r[locationval]->roomID == 13){ // bedroom
	    locationval = 11;
	  }
	
	  checkdirection = true;
	}
      }
      else if (strcmp(a, "WEST") == 0){ // west
	if (r[locationval]->exitW == false){
	  cout << "invalid direction!" << endl;
	}
	else if (r[locationval]->exitW == true) {
	  if (r[locationval]->roomID == 2){
	    locationval = 1;
	  }
	  else if (r[locationval]->roomID == 1){
	    locationval = 3;
	  }
	  else if (r[locationval]->roomID == 5){
	    locationval = 4;
	  }
	  else if (r[locationval]->roomID == 4){
	    locationval = 6;
	  }
	  else if (r[locationval]->roomID == 7){
	    locationval = 10;
	  }
	  else if (r[locationval]->roomID == 10){
	    locationval = 11;
	  }
	  else if (r[locationval]->roomID == 9){
	    locationval = 8;
	  }
	  else if (r[locationval]->roomID == 11){
	    locationval = 13;
	  }
					  
	  checkdirection = true;
	}
      }
      else {
	cout << "invalid input! (make sure your direction is in all caps)" << endl;
      }
    }
    

    else if (strcmp(a, "GET") == 0){

      cout << "Get what?" << endl;
      cin >> a;
      if (strcmp(a, "SPOON") == 0){
	if (r[locationval]->hasSpoon == true){
	  r[locationval]->hasSpoon = false;
	  spoonInv = true;
	  cout << "SPOON is in your inventory now!" << endl;
	}
	else {
	  cout << "That's not here!" << endl;
	}
      }
      else if (strcmp(a, "FORK") == 0){
	if (r[locationval]->hasFork == true){
	  r[locationval]->hasFork = false;
	  forkInv = true;
	  cout << "FORK is in your inventory now!" << endl;
	}
	else {
	  cout << "That's not here!" << endl;
	}
      }
      else if (strcmp(a, "KNIFE") == 0){
	if (r[locationval]->hasKnife == true){
	  r[locationval]->hasKnife = false;
	  knifeInv = true;
	  cout << "KNIFE is in your inventory now!" << endl;
	}
	else {
	  cout << "That's not here!" << endl;
	}
      }
      else if (strcmp(a, "CHOPSTICKS") == 0){
	if (r[locationval]->hasChopsticks == true){
	  r[locationval]->hasChopsticks = false;
	  chopsticksInv = true;
	  cout << "CHOPSTICKS is in your inventory now!" << endl;
	}
	else {
	  cout << "That's not here!" << endl;
	}
	
      }
      else if (strcmp(a, "SPORK") == 0){
	if (r[locationval]->hasSpork == true){
	  r[locationval]->hasSpork = false;
	  sporkInv = true;
	}
	else {
	  cout << "That's not here!" << endl;
	}	
      }
    }

    else if (strcmp(a, "DROP") == 0){

      cout << "What do you want to drop?" << endl;
      cin >> a;

      if (strcmp(a, "SPOON") == 0){
	if (spoonInv == true && r[locationval]->hasSpoon == false){
	  spoonInv = false;
	  r[locationval]->hasSpoon = true;
	  cout << "SPOON dropped!" << endl;
	}
	else {
	  cout << "You can't drop that!" << endl;
	}
      }

      if (strcmp(a, "FORK") == 0){
	if (forkInv == true && r[locationval]->hasFork == false){
	  forkInv = false;
	  r[locationval]->hasFork = true;
	  cout << "FORK dropped!" << endl;
	}
	else {
	  cout << "You can't drop that!" << endl;
	}
	
      }
      if (strcmp(a, "KNIFE") == 0){
	if (knifeInv == true && r[locationval]->hasKnife == false){
	  knifeInv = false;
	  r[locationval]->hasKnife = true;
	  cout << "KNIFE dropped!" << endl;
	}
	else{
	  cout << "You can't drop that!" << endl;
	}
      }
      if (strcmp(a, "CHOPSTICKS") == 0){
	if (chopsticksInv == true && r[locationval]->hasChopsticks == false){
	  knifeInv = false;
	  r[locationval]->hasKnife = true;
	  cout << "KNIFE dropped!" << endl;
	}
	else{
	  cout << "You can't drop that!" << endl;
	}

      }
      if (strcmp(a, "SPORK") == 0) {
	if (sporkInv == true && r[locationval]->hasSpork == false){
	  sporkInv = false;
	  r[locationval]->hasSpork = true;
	  cout << "SPORK dropped!" << endl;
	}
	else {
	  cout << "You can't drop that!" << endl;
	}
      }
    }

    else if (strcmp(a, "INVENTORY") == 0){

      cout << "In inventory: ";
      
      if (spoonInv == true){
          cout << "SPOON ";
      }
      else if (knifeInv == true){
	cout << "KNIFE ";
      }
      else if (forkInv == true){
	cout << "FORK ";
      }
      else if (chopsticksInv == true){
	cout << "CHOPSTICKS ";
      }
      else if (sporkInv == true){
	cout << "SPORK ";
      }

      cout << "" << endl;
      
    }
    
    
    else if (strcmp(a, "QUIT") == 0){
      cont = false;
      break;
    }

    cout << "" << endl; // spacing
    cout << "" << endl;
    
  }
  }
  return 0;
}

void makeRooms(vector<Room*> &r){
  Room* entrance = new Room();
  Room* grandhall = new Room();
  Room* study = new Room();
  Room* lavatory = new Room();
  Room* dining = new Room();
  Room* storage = new Room();
  Room* kitchen = new Room();
  Room* den = new Room();
  Room* backyard = new Room();
  Room* pool = new Room();
  Room* stairs = new Room();
  Room* hallway = new Room();
  Room* recroom = new Room();
  Room* bedroom = new Room();
  Room* laundry = new Room();
  
  char input[1000];

  // entrance = 0

  strcpy(entrance->description, "You are at the entrance of the haunted house! You feel a pretty nervous, but the legendary utensil set sounds pretty cool...\nHow lucky! You found a shiny spoon here. Just a few more utensils to go.");
  entrance->hasSpoon = true;
  entrance->roomID = 0;
  entrance->exitN = true;
  entrance->exitS = false;
  entrance->exitE = false;
  entrance->exitW = false;
  r.push_back(entrance);
  
  // grand hall = 1

  strcpy(grandhall->description, "You are in the grand hall. Unlit chandeliers hang from the ceiling, and portraits of very angry women stare into you as you go down the hallway. There doesn't seem to be any special utensils here, and these women are scary...");
  grandhall->roomID = 1;
  grandhall->exitN = true;
  grandhall->exitS = true;
  grandhall->exitE = true;
  grandhall->exitW = true;
  (r).push_back(grandhall);
  
  // study = 2

  strcpy(study->description, "You are now in the study. Shelves and shelves of books surround a singular desk in the center of the room. The books look very dusty and the desk looks rotten... ");
  study->roomID = 2;
  study->exitN = false;
  study->exitS = false;
  study->exitE = false;
  study->exitW = true;
  (r).push_back(study);

  // lavatory = 3

  strcpy(lavatory->description, "You are in the lavatory (aka bathroom). It reeks of poop and pee. It looks like a skeleton is in the corner, his pants completely soiled. You wonder how exactly he died...\nFighting back the urge to throw up, you search the room. By some strange luck, you found the knife! In the toilet though. Not a pleasant experience.");
  lavatory->hasKnife = true;
  lavatory->roomID = 3;
  lavatory->exitN = false;
  lavatory->exitS = false;
  lavatory->exitE = true;
  lavatory->exitW = false;
  (r).push_back(lavatory);

  // dining = 4

  strcpy(dining->description, "You are now in the dining hall. An absurdly long table sits there, plates of rotton food still sitting there. There is only 1 chair? Well, better get searching.");
  dining->roomID = 4;
  dining->exitN = true;
  dining->exitS = true;
  dining->exitE = true;
  dining->exitW = true;
  (r).push_back(dining);
  
  // storage = 5

  strcpy(storage->description, "You are now in the storage room. It looks safe enough, so you confidently walk in. Just as you thought you were safe, rats swarm you, and within seconds you reek of rat poop. Humiliated, you push through the rats to the back.\n Here, you found a special fork!");
  storage->hasFork = true;
  storage->roomID = 5;
  storage->exitN = false;
  storage->exitS = false;
  storage->exitE = false;
  storage->exitW = true;
  (r).push_back(storage);
  
  // kitchen = 6

  strcpy(kitchen->description, "You are now in the kitchen. You excited run inside, expecting to find the rest of the set, and step on some strange substance on the floor. It sticks to your shoes though. How unlucky. \nAfter some searching, there doesn't seem to be any utensils, much to your disappointment.");
  kitchen->roomID = 6;
  kitchen->exitN = false;
  kitchen->exitS = false;
  kitchen->exitE = true;
  kitchen->exitW = false;
  (r).push_back(kitchen);

  // den = 7

  strcpy(den->description, "You are now in the den. The fireplace is unlit, and seems like its been that way for a long time. The couch looks ragged and on the verge of collapse.\nNothing shiny here...");
  den->roomID = 7;
  den->exitN = true;
  den->exitS = true;
  den->exitW = true;
  den->exitE = false;
  (r).push_back(den);

  // backyard = 8

  strcpy(backyard->description, "You are now in the backyard. Although it looks more like a forest here. You look into the depths, and a pair of glowing orange eyes looks right back at you. How...unsettling. The place is super overgrown and there doesn't seem to be a clear path to the pool.\nIt looks like it would take forever to search the place for stuff, so you just hope that there aren't any utensils here.");
  backyard->roomID = 8;
  backyard->exitN = false;
  backyard->exitS = true;
  backyard->exitW = false;
  backyard->exitE = true;
  (r).push_back(backyard);
  
  // pool = 9

  strcpy(pool->description, "Pushing through the sharp leaves and branches, you arrive at pool, bleeding and scratched up. Your efforts are rewarded though! As you look into the pool, you found the chopsticks! How did they get here...?\nNow, time to go back...through the forest...");
  pool->hasChopsticks = true;
  pool->roomID = 9;
  pool->exitN = false;
  pool->exitS = false;
  pool->exitW = true;
  pool->exitE = false;
  (r).push_back(pool);
  
  // stairs = 10

  strcpy(stairs->description, "You climb the stairs. The stairs are pretty dusty and creaky, and you keep your guard up. Nothing interesting here.");
  stairs->roomID = 10;
  stairs->exitN = false;
  stairs->exitS = false;
  stairs->exitW = true;
  stairs->exitE = true;
  (r).push_back(stairs);
  
  // hallway = 11

  strcpy(hallway->description, "You are in a long hallway. Its dark, and a light seems to flicker in one of the rooms. You hear noises of distant screams... You suddenly don't feel too good.");
  hallway->roomID = 11;
  hallway->exitN = true;
  hallway->exitS = true;
  hallway->exitW = true;
  hallway->exitE = true;
  (r).push_back(hallway);
  
  // rec room = 12

  strcpy(recroom->description, "You enter the room where the distant screams seem to come from. You prepare yourself, and then burst into the room, only to find a broken TV playing a terrible horror movie and a pool table that looks like someone got a little too mad at.\n You found the spork, stuck inside the TV screen!");
  recroom->hasSpork = true;
  recroom->roomID = 12;
  recroom->exitN = false;
  recroom->exitS = true;
  recroom->exitW = false;
  recroom->exitE = false;
  (r).push_back(recroom);
  
  // bedroom = 13

  strcpy(bedroom->description, "You enter the bedroom with the flickering lights. It's quite a nice bedroom, except for the fact that its filled with corpses.\nSome even look fresh?\nAs you walk in to investigate, the door closes behind you, and a creature that looks awfully like Barney jumps at you from under the bed.\n What follows is so violent and gruesome for this assignment that I can't go into details, but in the end, you walk away, hands covered in both your and Barney's blood, victorious. No utensil though.");
  bedroom->roomID = 13;
  bedroom->exitN = false;
  bedroom->exitS = false;
  bedroom->exitW = false;
  bedroom->exitE = true;
  (r).push_back(bedroom);

  // laundry = 14

  strcpy(laundry->description, "You don't even bother entering this room. Poop and pee smell bad enough, but ancient underwear... you just hope that you don't need to come back to find a missing utensil...");
  laundry->roomID = 14;
  laundry->exitN = true;
  laundry->exitS = false;
  laundry->exitW = false;
  laundry->exitE = false;
  (r).push_back(laundry);
  
}
