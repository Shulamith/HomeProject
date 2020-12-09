#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#include "process.cpp"
#include <utility>
#include <cstdlib>
#include "readyQueue.cpp"
#include "ram.cpp"
void command(std::vector<std::string> &result){ //ToDo: pass by reference
    Memory ramMem = Memory(4000);
    int count = 0;
   if(result[0] == "A"){
     count++;
     std::cout << "here\n";
  //   //Ask memory if it has room and ask for it to recieve
  //   //Create process
  //   //Check if CPU in use
  //   //if no: let cpu be in use with this processes, and change process status to running
  //   //if yes: add it to the readyQueue;
   }
}
void parse(std::string input) {
  std::vector<std::string> parsedResult;
  int number;
  //std::cout << input[input.size()-1];
  std::istringstream ss(input);
    std::string word; // for storing each word
    while (ss >> word)
    {
        std::cout << word << "\n";
        parsedResult.push_back(word);
    }
  //  command(parsedResult);
}

void listen() {
  std::string input;
  while (getline(std::cin, input)) {
    std::cout << input << std::endl;
    parse(input);
  }
}

int main(int argc, char const *argv[]) {
  std::string memory, numOfDisks;

  std::cout << "How much RAM memory is there on the simulated computer?" << "\n";
  std::cin >> memory;
  std::cout << "How many hard disks does the simulated computer have?" << "\n";
  std::cin >> numOfDisks;
  listen();
  std::cout << "Main exit" << std::endl;
  return 0;
}
