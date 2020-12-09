#include <cstdlib>

class Memory {
private:
  std::size_t size;
  //AVAILABLE MEMORY

public:
 Memory (std::size_t size){
   this->size = size;
 }
 //CHECK IF MEMORY IS AVAILABLE;
};
