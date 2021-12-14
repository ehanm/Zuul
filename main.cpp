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
  const char b[10000];
  // an entrance
  // a grand hall
  // the ability to move between the 2

  makeRooms(r);
  
  
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

    cout << a;

    b = "help me";

    cout << b;
    
    
    if (strcmp(a, "QUIT") == 0){
      cont = false;
      break;
    }
    
  }
  
  return 0;
}

void makeRooms(vector<Room*> &r){

  // entrance

  
  

}
