#include <queue>
#include "process.hpp"
class readyQueue {
private:
  std::priority_queue<std::pair<int, int>> processes;
  bool empty = true;

public:
  readyQueue(){

  }
  bool checkEmpty(){
    return processes.empty();
  }
  //return pID of nextInLine and removes from rq
  int getNextInLine(){
    int id = processes.top().first;
    processes.pop();
    return id;
  }
  void addProcess(Process &p){
    processes.push(std::make_pair(p.priority, p.getpID()));
    std::cout << "Front of queue" << processes.top().second << '\n';
  }
};
