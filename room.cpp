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


bool Room::getNorthExit(){
  if (exitN == true){
    return true;
  }
  
}

bool Room::getSouthExit(){
  if (exitS == true){
    return true;
  }
}

bool Room::getEastExit(){
  if (exitE == true){
    return exitE;
  }  
}

bool Room::getWestExit(){
  if (exitW == true){
    return exitW;
  }
}

int Room::getID(){
  return roomID;
}
