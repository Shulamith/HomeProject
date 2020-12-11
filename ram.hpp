#include <cstdlib>
#include <utility>
#include <vector>
#include <map>
#include <iostream>
#pragma once
class Memory {
private:
  long long size = 0;
  size_t remaining;
  size_t first_available = 0;
  std::map<long long, long long> addresses;
  //AVAILABLE MEMORY
public:
 Memory();
 void setMemorySize(long long memSize);
 std::pair<long long, long long> getMemory(long long bits);
};
