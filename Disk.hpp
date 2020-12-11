#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#pragma once
class disk {
private:
  int num_disks;
  std::vector<std::queue<std::pair<int,int>>> disk_queue;
public:
  disk ();
  void setup(int hardDisks);
  void finishReading(int diskNumber);
  void addCylinder(int diskNumber, int pID, int cylinder);
  void diskPrint();
};
