#include <queue>
#include "process.hpp"
class readyQueue {
private:
  std::priority_queue<std::pair<int, int>> processes;
  //have to make sure prioriy queue sorts correctly with the pairs;
  bool empty = false;

public:
  readyQueue(){

  }
  bool checkEmpty(){
    return empty;
  }
  void addProcess(Process &p){
    processes.push(std::make_pair(p.priority, p.getpID()));
    std::cout << "Front of queue" << processes.top().second << '\n';
  }
};
