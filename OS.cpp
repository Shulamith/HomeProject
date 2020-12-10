#include "./OS.hpp"

OS::OS(long long memSize, int hardDisks) {
  Memory ram_Mem = Memory(memSize);
  hard_disks = hardDisks;
}
void OS::increasePID() { p_id_counter++; }
void OS::setCPU() {
  if (cpu_in_use) {
    cpu_in_use = false;
  } else {
    cpu_in_use = true;
  }
}
void OS::terminate() {
  setCPU();
  // removefromPCB
  //ifReadyQueueNotEmpty,call sendProcesstoCPU func and setCPU() and add process to removefromPCB
  //else
}
void OS::addProcess(int prioritySize, int memoryNeeded) {
  // askRamMem for memory
  Process p = Process(prioritySize, p_id_counter);
  if (!cpu_in_use) {
    p.running = true;
    std::cout << "Process is currently running" << '\n';
    setCPU();
  } else {
      rq.addProcess(p);
  }
  // add process to PCB
  increasePID();
}
void OS::parse(std::vector<std::string> unparsed){
  if (unparsed[0] == "A") {
    std::cout << "Add Process" << '\n';
    addProcess(stoi(unparsed[1]), stoi(unparsed[2]));
  }

}
