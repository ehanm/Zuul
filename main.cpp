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

  bool cont = true;

  while (cont == true){

    cin >> a;

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
  // entrance

  char input[1000];

  strcpy(rp->place, "entrance");
  
  strcpy(rp->description, "You are at the entrance of the haunted house! You feel a pretty nervous, but the\
 legendary utensil set sounds pretty cool...");
  //rp->place = input;

  strcpy(rp->item, "SPOON");
  //rp->item = input;
  
  rp->exitN = true;
  rp->exitS = false;
  rp->exitE = false;
  rp->exitW = false;
  (r).push_back(rp);

}
