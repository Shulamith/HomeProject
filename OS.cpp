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
void OS::sendProcesstoCPU(){
  if(!rq.checkEmpty()){
    int pID = rq.getNextInLine();
    //setCPU();
    cpu_in_use = true;
    process_in_cpu = pID;
    pcb[pID] = true;
  }
}
void OS::terminate() {
  cpu_in_use = false;
  //remove process from pcb
  pcb.erase(process_in_cpu);
  sendProcesstoCPU();
  //else
}
void OS::addProcess(int prioritySize, int memoryNeeded) {
  // askRamMem for memory
  Process p = Process(prioritySize, p_id_counter);
  if (!cpu_in_use) {
    p.running = true;
    process_in_cpu = p_id_counter;
    std::cout << "Process is currently running" << '\n';
    setCPU();
  } else {
      rq.addProcess(p);
  }
  // add process to PCB
  pcb[p_id_counter] = p.running;
  //increase processIDCounter
  increasePID();
}
void OS::parse(std::vector<std::string> unparsed){
  if (unparsed[0] == "A") {
    std::cout << "Add Process" << '\n';
    addProcess(stoi(unparsed[1]), stoi(unparsed[2]));
  }
  else if(unparsed[0] == "t"){
    terminate();
  }
  else if(unparsed[0] == "S"){
    if(unparsed.size() != 2){
      std::cout << "Unrecognizable input" << '\n';
    }
    else if(unparsed[1] == "r"){
      std::cout << "Show processes" << '\n';
    }
    else if(unparsed[1] == "m"){
      std::cout << "Show memory" << '\n';
    }
    else if (unparsed[1]== "i") {
      std::cout << "Show hardDisks" << '\n';
    }
    else {
      std::cout << "Unrecognizable Input" << '\n';
    }
  }
  else{
    std::cout << "Unrecognizable Input" << '\n';
  }
}
