// make room .h file
#include <iostream>
#include <cstring>

using namespace std;

class Room {


public: 
  char place[1000];
  char item[10000];

  bool exitN;
  bool exitS;
  bool exitE;
  bool exitW;
  

  Room(char a[]);
  getItem();
  getDescription();

  getInventory();
  


  
};
