// make room .h file
#include <iostream>
#include <cstring>

using namespace std;

class Room {

public:
  char description[10000];
  char place[1000];
  char item[10000];
  int roomID;
  
  bool exitN;
  bool exitS;
  bool exitE;
  bool exitW;
  
  char* getItem();
  char* getDescription();
  char* getPlace();

  bool getNorthExit();
  bool getSouthExit();
  bool getEastExit();
  bool getWestExit();

  int getID();
  
};
