#include <cstdlib>
#include <utility>
#include <vector>
class Memory {
private:
  long long size;
  size_t remaining;
  size_t first_available;
  std::vector<std::pair<int,int>> slots_in_use;
  //AVAILABLE MEMORY
public:
 Memory(long long memSize){
   this->size = memSize;
 }
 std::pair<int, int> getMemory(int bits){
   //CHECK IF MEMORY IS AVAILABLE;
   //really should just loop until you can find
   // long long x = 0;
   // long long slots = bits/100 +1;
   // //sort first_available
   // if (x + bits < slots_in_use[0].first) {
   //   slots_in_use.push_back(make_pair(0,))
   //   return make_pair(0,bits);
   // }
   // for(auto& pair: slots_in{
   //
   // }
   return std::make_pair(0,999);
 }
};
