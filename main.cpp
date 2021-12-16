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
  int locationval = 0;
  // an entrance
  // a grand hall
  // the ability to move between the 2

  makeRooms(r);

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
	cout << r[i]->description << endl;
	cout << "" << endl;
	cout << "Objects in the room (will be blank if nothing exists): ";
	cout << r[i]->item << endl;
      }
    }

    checkdirection = false;

    while (checkdirection == false) {

    cout << "Where do you want to go?" << endl;

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

    
    if (strcmp(a, "NORTH") == 0){
      if (r[locationval]->exitN == false){
	cout << "invalid direction!" << endl;
      }
      else if (r[locationval]->exitN == true) {
	// move north
	checkdirection = true;
      }
    }
    else if (strcmp(a, "SOUTH") == 0){
      if (r[locationval]->exitS == false){
	cout << "invalid direction!" << endl;
      }
      else if (r[locationval]->exitS == true) {
	// move south
	checkdirection = true;
      }
    }
    else if (strcmp(a, "EAST") == 0){
      if (r[locationval]->exitE == false){
	cout << "invalid direction!" << endl;
      }
      else if (r[locationval]->exitE == true) {
	// move east
	checkdirection = true;
      }
    }
    else if (strcmp(a, "WEST") == 0){
      if (r[locationval]->exitW == false){
	cout << "invalid direction!" << endl;
      }
      else if (r[locationval]->exitW == true) {
	// move west
	checkdirection = true;
      }
    }
    else {
      cout << "invalid input! (make sure your direction is in all caps)" << endl;
    }
    
    }

    if (strcmp(a, "PRINTROOMS") == 0){
      for (it = r.begin(); it < r.end(); it++){

	cout << (*it)->place;
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

  Room* rp = new Room();

  char input[1000];


  // laundry = 14


  // bedroom = 13

  
  // rec room = 12

  
  // hallway = 11
  

  // stairs = 10  


  // pool = 9


  // backyard = 8

  
  // den = 7
  

  // kitchen = 6
  

  // storage = 5
  

  // dining = 4
  

  // lavatory = 3

  
  // study = 2

  
  // grand hall = 1
  strcpy(rp->place, "grand hall");
  strcpy(rp->description, "You are in the grand hall. (add more detail)");
  strcpy(rp->item, "");
  (r).push_back(rp);


  // entrance = 0
  strcpy(rp->place, "entrance");
  strcpy(rp->description, "You are at the entrance of the haunted house! You feel a pretty nervous, but the\
 legendary utensil set sounds pretty cool...");
  strcpy(rp->item, "SPOON");

  rp->exitN = true;
  rp->exitS = false;
  rp->exitE = false;
  rp->exitW = false;
  r.push_back(rp);


 
  
}
