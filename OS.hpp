// OS.cpp
#include "./disk.hpp"
#include "./process.hpp"
#include "./ram.hpp"
#include "./readyQueue.cpp"
#include <map>
#include <string>
#pragma once
class OS {
private:
  readyQueue rq = readyQueue();
  int p_id_counter = 1;
  bool cpu_in_use = false;
  int hard_disks;
  int process_in_cpu;
  std::pair<long long, long long> process_in_cpu_memory;
  disk disk_control;
  Memory ram_mem = Memory();
  std::map<int, bool> pcb;
  void increasePID();
  void setCPU();
  void terminate();

public:
  OS(long long memSize, int hardDisks);
  void addProcess(int prioritySize, long long memoryNeeded);
  void showProcesses();
  void sendProcesstoCPU();
  void parse(std::vector<std::string> unparsed);
};
