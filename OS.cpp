#include "./OS.hpp"

OS::OS(long long memSize, int hardDisks) {
  ram_mem.setMemorySize(memSize);
  hard_disks = hardDisks;
  disk_control.setup(hardDisks);
}
void OS::increasePID() { p_id_counter++; }
void OS::setCPU() {
  if (cpu_in_use) {
    cpu_in_use = false;
  } else {
    cpu_in_use = true;
  }
}
void OS::sendProcesstoCPU() {
  if (!rq.checkEmpty()) {
    int pID = rq.getNextInLine();
    cpu_in_use = true;
    process_in_cpu = pID;
    pcb[pID] = true;
  }
}
void OS::terminate() {
  cpu_in_use = false;
  process_in_cpu = -1;
  // removes process from pcb
  pcb.erase(process_in_cpu);
  sendProcesstoCPU();
}
void OS::addProcess(int prioritySize, long long memoryNeeded) {
  std::pair<long long, long long> memoryAddress =
      ram_mem.getMemory(memoryNeeded);
  // if (memoryAddress.first == -1) {
  //   std::cout << "Not enough memory" << '\n';
  // } else {
  Process p = Process(prioritySize, p_id_counter);
  p.setMemory(memoryAddress);
  if (!cpu_in_use) {
    p.running = true;
    process_in_cpu = p_id_counter;
    setCPU();
  } else {
    rq.addProcess(p);
  }
  // add process to PCB
  pcb[p_id_counter] = p.running;
  // increase processIDCounter
  increasePID();
  //  }
}
void OS::showProcesses() {
  if (cpu_in_use == true) {
    std::cout << "CPU: P" << process_in_cpu << '\n';
  } else {
    std::cout << "CPU: idle" << '\n';
  }
  rq.printReadyQueue();
}
void OS::parse(std::vector<std::string> unparsed) {
  if (unparsed[0] == "A") {
    if (unparsed.size() != 3) {
      std::cout << "Unrecognizable input" << '\n';
      return;
    }
    addProcess(stoi(unparsed[1]), stoll(unparsed[2]));
  } else if (unparsed[0] == "t") {
    terminate();
  } else if (unparsed[0] == "S") {
    if (unparsed.size() != 2) {
      std::cout << "Unrecognizable input" << '\n';
    } else if (unparsed[1] == "r") {
      showProcesses();
    } else if (unparsed[1] == "m") {
      std::cout << "Show memory" << '\n';
    } else if (unparsed[1] == "i") {
      disk_control.diskPrint();
    } else {
      std::cout << "Unrecognizable Input" << '\n';
    }
  }
  else if (unparsed[0]=="D" && unparsed.size()==2) {
    disk_control.finishReading(stoi(unparsed[1]));
  }
  else if (unparsed[0]=="d" && unparsed.size()>2) {
    if(cpu_in_use){
    int diskNumber = stoi(unparsed[1]);

    for(int i=2; i<unparsed.size(); i++){
      disk_control.addCylinder(diskNumber,process_in_cpu,stoi(unparsed[i]));
    }
  }
  }else {
    std::cout << "Unrecognizable Input" << '\n';
  }

}
