#include "process.hpp"

  Process::Process(int priority, int pID){
    this->priority = priority;
    this->pID = pID;
  }
  int Process::getpID(){
    return pID;
  }
