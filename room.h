// make room .h file
#include <iostream>
#include <cstring>

using namespace std;

class Room {

public: 
  char description[10000];
  
  bool hasSpoon = false; // if the room has utensil, the bool will be true
  bool hasKnife = false;
  bool hasFork = false;
  bool hasChopsticks = false;
  bool hasSpork = false;
  
  bool exitN; // false or true depending on where the room has 
  bool exitS;
  bool exitE;
  bool exitW;

  int roomID; // each room has an ID, so manually moving between rooms is possible
  
  char* getItem();
  char* getDescription();

  bool getNorthExit();
  bool getSouthExit();
  bool getEastExit();
  bool getWestExit();

  int getID();

  
};
