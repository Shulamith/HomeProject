#include <queue>
class readyQueue {
private:
  std::priority_queue<int> processes;
  bool empty = false;

public:
  bool checkEmpty(){
    return this->empty;
  }
  readyQueue(){

  }
  virtual ~readyQueue ();
};
