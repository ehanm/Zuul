// create room cpp file
#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

char* Room::getItem(){

  return item;
  
}

char* Room::getDescription(){

  return description;
  
}

char* Room::getPlace(){

  return place;
  
}

bool Room::getNorthExit(){

  return exitN;
  
}

bool Room::getSouthExit(){

  return exitS;
  
}

bool Room::getEastExit(){

  return exitE;
  
}

bool Room::getWestExit(){

  return exitW;
  
}
