#include "ram.hpp"
Memory::Memory() {}
void Memory::setMemorySize(long long memSize) { this->size = memSize; }
std::pair<long long, long long> Memory::getMemory(long long bits) {
  // CHECK IF MEMORY IS AVAILABLE;
  // sort first_available
  //FROM HERE
  // std::cout << "I made it to geMem func" << '\n';
  // std::cout << addresses.begin()->first << '\n';
  // // if (bits < addresses.begin()->first) {
  // //   addresses[0] = bits;
  // //   std::cout << "I made it to if statement" << '\n';
  // //   return std::make_pair(0, bits);
  // // }
  // if (first_available != 0) {
  //   std::map<long long, long long>::iterator it;
  //   for (it = addresses.begin(); it != addresses.end()--; it++) {
  //     long long start = it->second;
  //     if (start + bits < it++->first) {
  //       std::cout << "I found a space for you" << '\n';
  //       addresses[start + bits] = it++->first;
  //       return std::make_pair(start, start + bits);
  //     }
  //   }
  // }
  // else {
  //   addresses[0] = bits;
  //   first_available = bits;
  //   return std::make_pair(0, bits);
  // }
  // std::cout << "Could not find memory" << '\n';
  return std::make_pair(-1, -1);
}
