#include <iostream>
class Process {
private:
  int pID;
  int priority;
  std::pair<int, int> memory;

public:
  Process (int priority, int pID){
    this->priority = priority;
    this->pID = pID;
  }
  bool running = false;
  bool reading = false;
};
