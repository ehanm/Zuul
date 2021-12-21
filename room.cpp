// create room cpp file
#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

char* Room::getDescription(){

  return description;
  
}


bool Room::getNorthExit(){
  if (exitN == true){
    return true;
  }

  return false;
  
}

bool Room::getSouthExit(){
  if (exitS == true){
    return true;
  }

  return false;
}

bool Room::getEastExit(){
  if (exitE == true){
    return exitE;
  }

  return false;
}

bool Room::getWestExit(){
  if (exitW == true){
    return exitW;
  }

  return false;
}

int Room::getID(){
  return roomID;
}
