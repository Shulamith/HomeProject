#include <cstdlib>
#include <utility>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>
#include<bits/stdc++.h>
#pragma once
class Memory {
private:
  long long size = 0;
  size_t first_available = 0;
  std::map<long long, long long> addresses;
  bool empty;
  std::vector<std::pair<size_t, size_t>> occupied_memory;
  std::map<int, std::pair<size_t, size_t>> process_to_memory;

  //AVAILABLE MEMORY
public:
 Memory();
 void addProcess(int pID, size_t start, size_t end);
 void setMemorySize(long long memSize);
 std::pair<long long, long long> getMemory(int pID, long long bits);
 void removeProcess(int pID);
 void memoryPrint();
};
