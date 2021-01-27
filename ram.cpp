#include "ram.hpp"
Memory::Memory() {}
void Memory::setMemorySize(long long memSize) { this->size = memSize; }
void Memory::addProcess(int pID, size_t start, size_t end) {
  occupied_memory.push_back(std::make_pair(start, end));
  process_to_memory[pID] = std::make_pair(start, end);
}
std::pair<long long, long long> Memory::getMemory(int pID, long long bits) {
  // CHECK IF MEMORY IS AVAILABLE;
  if (bits > size) {
    std::cout << "Too much memory requested" << '\n';
    return std::make_pair(-1, -1);
  }
  sort(occupied_memory.begin(), occupied_memory.end());
  if (occupied_memory.size() < 1) {
    addProcess(pID, 0, bits - 1);
    return std::make_pair(0, bits - 1);
  } else if (occupied_memory[0].first > bits - 1) {
    addProcess(pID, 0, (bits - 1));
    return std::make_pair(0, bits - 1);
  }
  for (int i = 1; i < occupied_memory.size(); i++) {
    if (occupied_memory[i - 1].second + bits + 1 < occupied_memory[i].first) {
      addProcess(pID, (occupied_memory[i - 1].second + 1),
                 occupied_memory[i - 1].second + bits + 1);
      return std::make_pair((occupied_memory[i - 1].second + 1),
                            (occupied_memory[i - 1].second + bits + 1));
    }
  }
  if (occupied_memory[occupied_memory.size() - 1].second + bits + 1 < size) {
    addProcess(pID, (occupied_memory[occupied_memory.size() - 1].second + 1),
               (occupied_memory[occupied_memory.size() - 1].second + 1 + bits));
    return std::make_pair(
        (occupied_memory[occupied_memory.size() - 1].second + 1),
        (occupied_memory[occupied_memory.size() - 1].second + 1 + bits));
  }
  return std::make_pair(-1, -1);
}

void Memory::removeProcess(int pID) {
  std::pair<size_t, size_t> memoryAddress = process_to_memory[pID];
  for (size_t i = 0; i < occupied_memory.size(); i++) {
    if (occupied_memory[i].first == memoryAddress.first) {
      occupied_memory.erase(occupied_memory.begin() + i);
      process_to_memory.erase(pID);
      return;
    }
  }
}

void Memory::memoryPrint() {
  std::map<int, std::pair<size_t, size_t>>::iterator it;
  for (it = process_to_memory.begin(); it != process_to_memory.end(); ++it) {
    std::cout << "Process " << it->first << ": ";
    std::cout << it->second.first << "-" << it->second.second << '\n';
  }
}
