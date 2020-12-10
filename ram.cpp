#include <cstdlib>
#include <utility>
class Memory {
private:
  std::size_t size;
  //AVAILABLE MEMORY
public:
 Memory(std::size_t memSize){
   this->size = memSize;
 }
 std::pair<int, int> getMemory(int bytes){
   return std::make_pair(0,999);
 }
 //CHECK IF MEMORY IS AVAILABLE;
};
