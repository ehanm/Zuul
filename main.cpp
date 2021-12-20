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

    for (int i = 0; i < r.size(); i++){
      if (i == locationval){
	cout << r[i]->getDescription() << endl;
	cout << "" << endl;
	cout << "Objects in the room (will be blank if nothing exists): ";
	cout << r[i]->getItem() << endl;
      }
    }
    
    checkdirection = false;

    while (checkdirection == false) {

    cout << "What do you do?" << endl;

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

    
    if (strcmp(a, "NORTH") == 0){ // north
      if (r[locationval]->exitN == false){
	cout << "invalid direction!" << endl;
      }
      else if (r[locationval]->exitN == true) {

	if (r[locationval]->roomID == 0){
	  locationval = 1;
	}
	checkdirection = true;
      }
    }
    else if (strcmp(a, "SOUTH") == 0){ // south
      if (r[locationval]->exitS == false){
	cout << "invalid direction!" << endl;
      }
      else if (r[locationval]->exitS == true) {
	if (r[locationval]->roomID == 1){
	  locationval = 0;
	}
	checkdirection = true;
      }
    }
    else if (strcmp(a, "EAST") == 0){ // east
      if (r[locationval]->exitE == false){
	cout << "invalid direction!" << endl;
      }
      else if (r[locationval]->exitE == true) {
	if (r[locationval]->roomID == 1){
	  locationval = 2;
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
	checkdirection = true;
      }
    }
    else {
      cout << "invalid input! (make sure your direction is in all caps)" << endl;
    }
    
    }

    if (strcmp(a, "PRINTROOMS") == 0){
      for (it = r.begin(); it < r.end(); it++){

	cout << (*it)->description;
	cout << (*it)->item;
	if ((*it)->exitN == true){
	  cout << "North" << endl;
	}
	if ((*it)->exitS == true){
	  cout << "South" << endl;
	}
	if ((*it)->exitE == true){
	  cout << "East" << endl;
	}
	if ((*it)->exitW == true){
	  cout << "West" << endl;
	}	
	
      }

    }
    
    
    if (strcmp(a, "QUIT") == 0){
      cont = false;
      break;
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
  strcpy(entrance->item, "SPOON");
  entrance->roomID = 0;
  entrance->exitN = true;
  entrance->exitS = false;
  entrance->exitE = false;
  entrance->exitW = false;
  r.push_back(entrance);
  
  // grand hall = 1

  strcpy(grandhall->description, "You are in the grand hall. Unlit chandeliers hang from the ceiling, and portraits of very angry women stare into you as you go down the hallway. There doesn't seem to be any special utensils here, and these women are scary...");
  strcpy(grandhall->item, "");
  grandhall->roomID = 1;
  grandhall->exitN = true;
  grandhall->exitS = true;
  grandhall->exitE = true;
  grandhall->exitW = true;
  (r).push_back(grandhall);
  
  // study = 2

  strcpy(study->description, "You are now in the study. Shelves and shelves of books surround a singular desk in the center of the room. The books look very dusty and the desk looks rotten... ");
  strcpy(study->item, "");
  study->roomID = 2;
  study->exitN = false;
  study->exitS = false;
  study->exitE = false;
  study->exitW = true;
  (r).push_back(study);

  // lavatory = 3

  strcpy(lavatory->description, "You are in the lavatory (aka bathroom). It reeks of poop and pee. It looks like a skeleton is in the corner, his pants completely soiled. You wonder how exactly he died...\nFighting back the urge to throw up, you search the room. By some strange luck, you found the knife! In the toilet though. Not a pleasant experience.");
  strcpy(lavatory->item, "KNIFE");
  lavatory->roomID = 3;
  lavatory->exitN = false;
  lavatory->exitS = false;
  lavatory->exitE = true;
  lavatory->exitW = false;
  (r).push_back(lavatory);

  // dining = 4

  strcpy(dining->description, "You are now in the dining hall. An absurdly long table sits there, plates of rotton food still sitting there. There is only 1 chair? Well, better get searching.");
  strcpy(dining->item, "");
  dining->roomID = 4;
  dining->exitN = true;
  dining->exitS = true;
  dining->exitE = true;
  dining->exitW = true;
  (r).push_back(dining);
  
  // storage = 5

  strcpy(storage->description, "You are now in the storage room. It looks safe enough, so you confidently walk in. Just as you thought you were safe, rats swarm you, and within seconds you reek of rat poop. Humiliated, you push through the rats to the back.\n Here, you found a special fork!");
  strcpy(storage->item, "FORK");
  storage->roomID = 5;
  storage->exitN = false;
  storage->exitS = false;
  storage->exitE = false;
  storage->exitW = true;
  (r).push_back(storage);
  
  // kitchen = 6

  strcpy(kitchen->description, "You are now in the kitchen. You excited run inside, expecting to find the rest of the set, and step on some strange substance on the floor. It sticks to your shoes though. How unlucky. \nAfter some searching, there doesn't seem to be any utensils, much to your disappointment.");
  strcpy(kitchen->item, "");
  kitchen->roomID = 6;
  kitchen->exitN = false;
  kitchen->exitS = false;
  kitchen->exitE = true;
  kitchen->exitW = false;
  (r).push_back(kitchen);

  // den = 7

  strcpy(den->description, "You are now in the den. The fireplace is unlit, and seems like its been that way for a long time. The couch looks ragged and on the verge of collapse.\nNothing shiny here...");
  strcpy(den->item, "");
  den->roomID = 7;
  den->exitN = true;
  den->exitS = true;
  den->exitW = true;
  den->exitE = false;
  (r).push_back(den);

  // backyard = 8

  strcpy(backyard->description, "You are now in the backyard. Although it looks more like a forest here. You look into the depths, and a pair of glowing orange eyes looks right back at you. How...unsettling. The place is super overgrown and there doesn't seem to be a clear path to the pool.\nIt looks like it would take forever to search the place for stuff, so you just hope that there aren't any utensils here.");
  strcpy(backyard->item, "");
  backyard->roomID = 8;
  backyard->exitN = false;
  backyard->exitS = true;
  backyard->exitW = false;
  backyard->exitE = true;
  
  // pool = 9

  strcpy(pool->description, "Pushing through the sharp leaves and branches, you arrive at pool, bleeding and scratched up. Your efforts are rewarded though! As you look into the pool, you found the chopsticks! How did they get here...?\nNow, time to go back...through the forest...");
  strcpy(pool->item, "CHOPSTICKS");
  pool->roomID = 9;
  pool->exitN = false;
  pool->exitS = false;
  pool->exitW = true;
  pool->exitE = false;
  
  // stairs = 10

  strcpy(stairs->description, "You climb the stairs. The stairs are pretty dusty and creaky, and you keep your guard up. Nothing interesting here.");
  strcpy(stairs->item, "");
  stairs->roomID = 10;
  stairs->exitN = false;
  stairs->exitS = false;
  stairs->exitW = true;
  stairs->exitE = true;
  
  // hallway = 11

  strcpy(hallway->description, "You are in a long hallway. Its dark, and a light seems to flicker in one of the rooms. You hear noises of distant screams... You suddenly don't feel too good.");
  strcpy(hallway->item, "");
  hallway->roomID = 11;
  hallway->exitN = true;
  hallway->exitS = true;
  hallway->exitW = true;
  hallway->exitE = true;

  // rec room = 12

  strcpy(recroom->description, "You enter the room where the distant screams seem to come from. You prepare yourself, and then burst into the room, only to find a broken TV playing a terrible horror movie and a pool table that looks like someone got a little too mad at.\n You found the spork, stuck inside the TV screen!");
  strcpy(recroom->item, "SPORK");
  recroom->roomID = 12;
  recroom->exitN = false;
  recroom->exitS = true;
  recroom->exitW = false;
  recroom->exitE = false;
  
  // bedroom = 13

  strcpy(bedroom->description, "You enter the bedroom with the flickering lights. It's quite a nice bedroom, except for the fact that its filled with corpses.\nSome even look fresh?\nAs you walk in to investigate, the door closes behind you, and a creature that looks awfully like Barney jumps at you from under the bed.\n What follows is so violent and gruesome for this assignment that I can't go into details, but in the end, you walk away, hands covered in both your and Barney's blood, victorious. No utensil though.");
  strcpy(bedroom->item, "");
  bedroom->roomID = 13;
  bedroom->exitN = false;
  bedroom->exitS = false;
  bedroom->exitW = false;
  bedroom->exitE = true;

  // laundry = 14

  strcpy(laundry->description, "You don't even bother entering this room. Poop and pee smell bad enough, but ancient underwear... you just hope that you don't need to come back to find a missing utensil...");
  strcpy(laundry->item, "");
  laundry->roomID = 14;
  laundry->exitN = true;
  laundry->exitS = false;
  laundry->exitW = false;
  laundry->exitE = false;
  
}
