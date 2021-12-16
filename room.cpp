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

int getID(){
  return roomID;
}
