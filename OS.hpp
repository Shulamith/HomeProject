//OS.cpp
#include "./readyQueue.cpp"
#include "ram.cpp"
#include "./process.hpp"
#include <cstring>
#pragma once
class OS {
private:
  readyQueue rq = readyQueue();
  int p_id_counter = 0;
  bool cpu_in_use = false;
  int hard_disks;
  Memory ram_Mem();
  //PCB as a Map
  void increasePID();
  void setCPU();
  void terminate();
public:
 OS (long long memSize, int hardDisks);
 void addProcess(int prioritySize, int memoryNeeded);
 //setRamMem();
 //setHardDisks();
 void parse(std::vector<std::string> unparsed);
};
