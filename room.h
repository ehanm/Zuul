// make room .h file
#include <iostream>
#include <cstring>

using namespace std;

class Room {

public:
  char description[10000];
  char item[10000];
  
  bool exitN;
  bool exitS;
  bool exitE;
  bool exitW;

  int roomID;
  
  char* getItem();
  char* getDescription();

  bool getNorthExit();
  bool getSouthExit();
  bool getEastExit();
  bool getWestExit();

  int getID();

  
};
