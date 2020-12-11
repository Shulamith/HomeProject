//OS.cpp
#include "./readyQueue.cpp"
#include "./ram.hpp"
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
  Memory ram_mem = Memory();
  std::map<int,bool> pcb;
  void increasePID();
  void setCPU();
  void terminate();
public:
 OS (long long memSize, int hardDisks);
 void addProcess(int prioritySize, long long memoryNeeded);
 //setRamMem();
 //setHardDisks;
 void showProcesses();
 void sendProcesstoCPU();
 void parse(std::vector<std::string> unparsed);
};
