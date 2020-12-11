#include "./disk.hpp"
disk::disk(int numOfDisks) {
  num_disks = numOfDisks;
  for (int i = 0; i < num_disks; i++) {
    std::cout << "complete" << '\n';
    // IO Queue where each index of vector holds a queue for each disk of
    // cylinder to read
    disk_queue.push_back(std::queue<std::pair<int, int>>());
  }
}

void disk::finishReading(int diskNumber) {
  if (!disk_queue[diskNumber].empty()) {
    disk_queue[diskNumber].pop();
  }
}
void disk::addCylinder(int diskNumber, int pID, int cylinder) {
  disk_queue[diskNumber].push(std::make_pair(cylinder, pID));
}
void disk::diskPrint() {
  for (size_t i = 0; i < disk_queue.size(); i++) {
    if (!disk_queue[i].empty()) {
      std::queue<std::pair<int,int>> copy = disk_queue[i];
      std::cout << "Disk " << i << " reading cylinder: " << disk_queue[i].front().first << "\n";
      std::set<int> processes;
      // Add all the processes it is currently serving to set

      while (!copy.empty()) {
        processes.insert(copy.front().second);
        copy.pop();
      }

      std::cout << "Curretly Serving: ";
      for (std::set<int>::iterator it = processes.begin();
           it != processes.end(); ++it) {
        std::cout << " P" << *it;
      }
    }
  }
  std::cout  << '\n';
}
