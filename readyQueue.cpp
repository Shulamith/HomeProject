#include <queue>
#include "process.hpp"
class readyQueue {
private:
  std::priority_queue<std::pair<int, int>> processes;
  bool empty = true;
  std::priority_queue<std::pair<int, int>> copy;

public:
  readyQueue(){
  }
  void printReadyQueue(){
    std::cout << "Ready Queue: ";
    if(processes.empty()){
      std::cout << "Empty";
    }
    else {
      copy = processes;
      for (size_t i=0; i<processes.size(); i++){
        std::cout << "P" << copy.top().second << " ";
        copy.pop();
      }
    }
    std::cout << '\n';
  }
  bool checkEmpty(){
    return processes.empty();
  }
  int getSize(){
    return processes.size();
  }
  //return pID of nextInLine and removes from rq
  int getNextInLine(){
    int id = processes.top().first;
    processes.pop();
    return id;
  }
  void addProcess(Process &p){
    processes.push(std::make_pair(p.priority, p.getpID()));
  }
};
