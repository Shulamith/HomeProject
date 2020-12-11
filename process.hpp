#include <iostream>
#include <vector>
#pragma once

class Process {
private:
  int pID;
  std::pair<int, int> memory;

public:
  Process(int priority, int pID);
  int getpID();
  bool running = false;
  bool reading = false;
  int priority;
};
