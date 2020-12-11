//OS.cpp
#include "./readyQueue.cpp"
#include "ram.cpp"
#include "./process.hpp"
#include <cstring>
#include <map>
#pragma once
class OS {
private:
  readyQueue rq = readyQueue();
  int p_id_counter = 0;
  bool cpu_in_use = false;
  int hard_disks;
  int process_in_cpu;
  Memory ram_Mem();
  std::map<int,bool> pcb;
  void increasePID();
  void setCPU();
  void terminate();
public:
 OS (long long memSize, int hardDisks);
 void addProcess(int prioritySize, int memoryNeeded);
 //setRamMem();
 //setHardDisks();
 void sendProcesstoCPU();
 void parse(std::vector<std::string> unparsed);
};
